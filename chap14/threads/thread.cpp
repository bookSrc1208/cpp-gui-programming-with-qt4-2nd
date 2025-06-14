#include <QtCore>
#include <iostream>

#include "thread.h"


QThreadStorage<int> cn;
//int n = 0;


Thread::Thread()
{
    stopped = false;
}

void Thread::setMessage(const QString &message)
{
    messageStr = message;
}

void Thread::run()
{
//    if(!cn.hasLocalData())
//        cn.setLocalData(0);
    int i = 100000;
    while (i--){
        cn.localData() = cn.localData()+1;
    }
    if(cn.localData()>i)
        std::cout <<"n:"<< cn.localData() <<std::endl;
//    while (!stopped){
//        //QThread::sleep(1);
//        std::cerr << qPrintable(messageStr)<<endl;
//        ++n;
//    }

    stopped = false;
    std::cerr << std::endl;
}

void Thread::stop()
{
    stopped = true;
}

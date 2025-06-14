#include <QtCore>
#include <iostream>

#include "ftpget.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QStringList args = QCoreApplication::arguments();

//    if (args.count() != 2) {
//        std::cerr << "Usage: ftpget url" << std::endl
//                  << "Example:" << std::endl
//                  << "    ftpget ftp://ftp.trolltech.com/mirrors"
//                  << std::endl;
//        return 1;
//    }

    FtpGet getter;
    if (!getter.getFile(QUrl("ftp://name@127.0.0.1/385507.jpg")))//args[1]
        return 1;

    QObject::connect(&getter, SIGNAL(done()), &app, SLOT(quit()));

    return app.exec();
}
//2795225013

#include <QApplication>

#include "threaddialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//    ThreadDialog dialog;
//    dialog.show();
    Thread ta;
    Thread tb;
    ta.start();
    tb.start();
    return app.exec();
}

#include <QtWidgets>
#include <QDebug>

#include "bronzedialog.h"
#include "bronzestyle.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //QApplication::setStyle(new BronzeStyle);
    //QApplication::setStyle("Bronze");
QApplication::setStyle("bronzestyle");
    //QApplication::setStyle("simplestyle");

    qDebug()<<QStyleFactory::keys ();

    BronzeDialog dialog;
    dialog.layout()->setSpacing(7);
    dialog.layout()->setMargin(7);
    dialog.show();
    return app.exec();
}

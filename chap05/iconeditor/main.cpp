#include <QApplication>
#include <QScrollArea>
#include <QPalette>
#include "iconeditor.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//    IconEditor iconEditor;
//    iconEditor.setWindowTitle(QObject::tr("Icon Editor"));
//    iconEditor.setIconImage(QImage(":/images/mouse.png"));
//    iconEditor.show();
    IconEditor *iconEditor = new IconEditor;
    iconEditor->setWindowTitle(QObject::tr("Icon Editor"));
    iconEditor->setIconImage(QImage(":/images/mouse.png"));
    QScrollArea qsa;
    qsa.setWidget(iconEditor);
    qsa.viewport()->setBackgroundRole(QPalette::Dark);
    qsa.viewport()->setAutoFillBackground(true);
    qsa.setWindowTitle(QObject::tr("Icon Editor"));
    qsa.show();

    return app.exec();
}

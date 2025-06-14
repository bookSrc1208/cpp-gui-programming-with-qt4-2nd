#include <QApplication>
#include <iostream>

#include "tetrahedron.h"

int main(int argc, char *argv[])
{
//    QApplication app(argc, argv);

//    if (!QGLFormat::hasOpenGL()) {
//        std::cerr << "This system has no OpenGL support" << std::endl;
//        return 1;
//    }
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setColorSpec(QApplication::CustomColor);
    QApplication app(argc,argv);

    if (QOpenGLContext::openGLModuleType() != QOpenGLContext::LibGL) {
        qWarning("This system does not support OpenGL. Exiting.");
        return -1;
    }

    Tetrahedron tetrahedron;
    tetrahedron.setWindowTitle(QObject::tr("Tetrahedron"));
    tetrahedron.resize(300, 300);
    tetrahedron.show();

    return app.exec();
}

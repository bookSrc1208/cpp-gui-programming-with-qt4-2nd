#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include <QGLWidget>
//#include <QOpenGLWindow>
#include <QOpenGLFunctions_1_1>

class Tetrahedron : public QGLWidget,public QOpenGLFunctions_1_1
{
    Q_OBJECT

public:
    Tetrahedron(QWidget *parent = 0);

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    void draw();
    int faceAtPosition(const QPoint &pos);

    GLfloat rotationX;
    GLfloat rotationY;
    GLfloat rotationZ;
    QColor faceColors[4];
    QPoint lastPos;
};

#endif

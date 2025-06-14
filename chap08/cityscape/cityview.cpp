#include <QtWidgets>
#include <cmath>

#include "cityview.h"

// using nocheck cityview.h.moc.cpp
// cpps-make cityview.h.moc.cpp : cityview.h // moc cityview.h -o cityview.h.moc.cpp


CityView::CityView(QWidget *parent)
    : QGraphicsView(parent)
{
    setDragMode(ScrollHandDrag);
}

void CityView::wheelEvent(QWheelEvent *event)
{
    double numDegrees = -event->delta() / 8.0;
    double numSteps = numDegrees / 15.0;
    double factor = std::pow(1.125, numSteps);
    scale(factor, factor);
}

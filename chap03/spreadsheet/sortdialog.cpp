//#include <QtGui>
#include <QtWidgets>
#include "sortdialog.h"
// 这个对话框是用界面设计器生成的，所以还得产生相应的ui_*.h
// cpps-make ui_sortdialog.h : sortdialog.ui // uic sortdialog.ui -o ui_sortdialog.h

// 引入附属的.h.moc.cpp
// using nocheck sortdialog.h.moc.cpp
// cpps-make sortdialog.h.moc.cpp : sortdialog.h // moc sortdialog.h -o sortdialog.h.moc.cpp


SortDialog::SortDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);

    secondaryGroupBox->hide();
    tertiaryGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    setColumnRange('A', 'Z');
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
    primaryColumnCombo->clear();
    secondaryColumnCombo->clear();
    tertiaryColumnCombo->clear();

    secondaryColumnCombo->addItem(tr("None"));
    tertiaryColumnCombo->addItem(tr("None"));

    primaryColumnCombo->setMinimumSize(
            secondaryColumnCombo->sizeHint());

    QChar ch = first;
    while (ch <= last) {
        primaryColumnCombo->addItem(QString(ch));
        secondaryColumnCombo->addItem(QString(ch));
        tertiaryColumnCombo->addItem(QString(ch));
        ch = ch.unicode() + 1;
    }
}

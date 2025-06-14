//#include <QtGui>
#include <QtWidgets>
#include <QPushButton>

#include "gotocelldialog.h"
// 这个对话框是用界面设计器生成的，所以还得产生相应的ui_*.h
// cpps-make ui_gotocelldialog.h : gotocelldialog.ui // uic gotocelldialog.ui -o ui_gotocelldialog.h

// 引入附属的.h.moc.cpp
// using nocheck gotocelldialog.h.moc.cpp
// cpps-make gotocelldialog.h.moc.cpp : gotocelldialog.h // moc gotocelldialog.h -o gotocelldialog.h.moc.cpp

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

void GoToCellDialog::on_lineEdit_textChanged()
{
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(
            lineEdit->hasAcceptableInput());
}

#include <QTreeWidgetItem>
#include <QtXml>
#include <QDebug>
#include <iostream>

#include "saxhandler.h"
#define DEBUG             qDebug()<<Q_FUNC_INFO<<__LINE__
SaxHandler::SaxHandler(QTreeWidget *tree)
{
    treeWidget = tree;
}

bool SaxHandler::readFile(const QString &fileName)
{
    currentItem = 0;
pagestart = false;
    QFile file(fileName);
    QXmlInputSource inputSource(&file);
    QXmlSimpleReader reader;
    reader.setContentHandler(this);
    reader.setErrorHandler(this);
    return reader.parse(inputSource);
}

bool SaxHandler::startElement(const QString & /* namespaceURI */,
                              const QString & /* localName */,
                              const QString &qName,
                              const QXmlAttributes &attributes)
{
    if (qName == "entry") {
        currentItem = new QTreeWidgetItem(currentItem ?
                currentItem : treeWidget->invisibleRootItem());
        currentItem->setText(0, attributes.value("term"));
    } else if (qName == "page") {
        currentText.clear();
        pagestart = true;
    }
    return true;
}

bool SaxHandler::characters(const QString &str)
{
    if(pagestart){
        currentText += str;
        DEBUG<<currentText;
    }
    return true;
}

bool SaxHandler::endElement(const QString & /* namespaceURI */,
                            const QString & /* localName */,
                            const QString &qName)
{
    if (qName == "entry") {
        currentItem = currentItem->parent();
    } else if (qName == "page") {
        if (currentItem) {
            QString allPages = currentItem->text(1);
            if (!allPages.isEmpty())
                allPages += ", ";
            allPages += currentText;
            currentItem->setText(1, allPages);
            pagestart = false;
        }
    }
    return true;
}

bool SaxHandler::fatalError(const QXmlParseException &exception)
{
    std::cerr << "Parse error at line " << exception.lineNumber()
              << ", " << "column " << exception.columnNumber() << ": "
              << qPrintable(exception.message()) << std::endl;
    return false;
}

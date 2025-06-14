#ifndef FTPGET_H
#define FTPGET_H

#include <QFile>
#include <QObject>
#include <QFtp>// 这个类已经被淘汰了

class QUrl;

class FtpGet : public QObject
{
    Q_OBJECT

public:
    FtpGet(QObject *parent = 0);

    bool getFile(const QUrl &url);

signals:
    void done();

private slots:
    void ftpDone(bool error);

private:
    QFtp ftp;
    QFile file;
};

#endif

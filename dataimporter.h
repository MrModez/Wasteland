#ifndef DATAIMPORTER_H
#define DATAIMPORTER_H

#include <QtCore>

class DataImporter : public QObject
{
    Q_OBJECT

public:
    explicit DataImporter(QObject *parent = 0);
    QVariant getListA();
    QVariant getListPDK();

signals:

public slots:

private:
    QList<QStringList> readCSV(QString filename);

    QList<QStringList> StringListA;
    QList<QStringList> StringListPDK;
};

#endif // DATAIMPORTER_H

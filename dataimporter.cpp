#include "dataimporter.h"

DataImporter::DataImporter(QObject *parent) : QObject(parent)
{
    StringListA = readCSV("resource01.csv");
    StringListPDK = readCSV("resource02.csv");
}

QList<QStringList> DataImporter::readCSV(QString filename)
{
    // Open csv-file
    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    // Read data from file
    QTextStream stream(&file);
    QList<QStringList> data;
    QString separator(",");
    while (stream.atEnd() == false)
    {
        QString line = stream.readLine();
        data << line.split(separator);
    }

    file.close();
    return data;
}

QVariant DataImporter::getListA()
{
    QList<QVariant>list;
    for (auto &strlist : StringListA)
        list << QVariant(strlist);
    return QVariant(list);
}

QVariant DataImporter::getListPDK()
{
    QList<QVariant>list;
    for (auto &strlist : StringListPDK)
        list << QVariant(strlist);
    return QVariant(list);
}

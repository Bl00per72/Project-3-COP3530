#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <qqml.h>

class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString brand READ brand WRITE setBrand)
    Q_PROPERTY(QString price READ price WRITE setPrice)
    Q_PROPERTY(QString mileage READ mileage WRITE setMileage)
    Q_PROPERTY(QString treeType READ treeType WRITE setTreeType)
    Q_PROPERTY(QString searchTree READ searchTree NOTIFY resultsReady)

    QML_ELEMENT

public:
    explicit BackEnd(QObject *parent = nullptr);


    QString brand();
    void setBrand(const QString &brand);
    QString price();
    void setPrice(const QString &price);
    QString mileage();
    void setMileage(const QString &mileage);
    QString treeType();
    void setTreeType(const QString &treeType);

    bool searchTree();

private:
    QString m_brand;
    QString m_price;
    QString m_mileage;
    QString m_treeType;
    QString m_searchTree;
};

#endif // BACKEND_H

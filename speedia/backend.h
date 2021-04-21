#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <qqml.h>
#include <bst.h>
#include <avltree.h>

class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString brand READ getbrand WRITE setBrand)
    Q_PROPERTY(QString price READ getprice WRITE setPrice)
    Q_PROPERTY(QString mileage READ getmileage WRITE setMileage)
    Q_PROPERTY(QString searchTree READ readyToSearch WRITE beginSearch)
    //Q_PROPERTY(QVector<QString> results READ getResults WRITE setResults)

    QML_ELEMENT

public:
    explicit BackEnd(QObject *parent = nullptr);


    QString getbrand();
    void setBrand(const QString &brand);
    QString getprice();
    void setPrice(const QString &price);
    QString getmileage();
    void setMileage(const QString &mileage);

    bool readyToSearch();
    void beginSearch(const QString &x);

    Q_INVOKABLE QString getResults();
    //void setResults(std::vector<std::string> text);

private:
    AVLTree atree;
    BST btree;
    QString m_brand;
    QString m_price;
    QString m_mileage;

    QString q_results;
};

#endif // BACKEND_H

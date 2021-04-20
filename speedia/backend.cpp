#include "backend.h"

BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{
}


QString BackEnd::brand()
{
    return m_brand;
}

void BackEnd::setBrand(const QString &brand)
{
    if (brand == m_brand)
        return;

    m_brand = brand;
}

QString BackEnd::price()
{
    return m_price;
}

void BackEnd::setPrice(const QString &price)
{
    if (price == m_price)
        return;

     m_price = price;
}

QString BackEnd::mileage()
{
    return m_mileage;
}

void BackEnd::setMileage(const QString &mileage)
{
    if (mileage == m_mileage)
        return;

    m_mileage = mileage;
}

QString BackEnd::treeType()
{
    return m_treeType;
}

void BackEnd::setTreeType(const QString &treeType)
{
    if (treeType == m_treeType)
        return;

    m_treeType = treeType;
}

bool BackEnd::searchTree()
{
    m_searchTree = true;
}

#include "backend.h"
#include <sstream>
#include <fstream>

BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{
    // AVL Start Time

    ifstream file ("C:/Users/QUO/Documents/speedia/cars_shuffled.csv");

    string junk;
    getline(file, junk);

    string b;
    string c;
    string d;
    string e;
    string f;
    string g;
    string h;
    string i;
    string j;
    string k;
    string l;
    getline(file, b, ',');
    getline(file, c, ',');
    getline(file, d, ',');
    getline(file, e, ',');
    getline(file, f, ',');
    getline(file, g, ',');
    getline(file, h, ',');
    getline(file, i, ',');
    getline(file, j, ',');
    getline(file, k, ',');
    getline(file, l);
    atree.setRoot(atree.insertdataID(nullptr, c, d, e, f, g, h, i, j, k, l, stoi(b)));

    while (stoi(b) < 10000)
    {
        getline(file,b,',');
        getline(file,c,',');
        getline(file,d,',');
        getline(file,e,',');
        getline(file,f,',');
        getline(file,g,',');
        getline(file,h,',');
        getline(file,i,',');
        getline(file,j,',');
        getline(file,k,',');
        getline(file,l);
        atree.insertdataID(atree.getRoot(), c, d, e, f, g, h, i, j, k, l, stoi(b));
    }

    // AVL End Time


    // BST Start Time

    file.seekg(0, std::ios::beg); //reset file pointer to beg

    string junk2;
    getline(file, junk2);

    getline(file, b, ',');
    getline(file, c, ',');
    getline(file, d, ',');
    getline(file, e, ',');
    getline(file, f, ',');
    getline(file, g, ',');
    getline(file, h, ',');
    getline(file, i, ',');
    getline(file, j, ',');
    getline(file, k, ',');
    getline(file, l);
    btree.setRoot(btree.insertdataID(nullptr, c, d, e, f, g, h, i, j, k, l, stoi(b)));

    while (stoi(b) < 10000)
    {
        getline(file,b,',');
        getline(file,c,',');
        getline(file,d,',');
        getline(file,e,',');
        getline(file,f,',');
        getline(file,g,',');
        getline(file,h,',');
        getline(file,i,',');
        getline(file,j,',');
        getline(file,k,',');
        getline(file,l);
        btree.insertdataID(btree.getRoot(), c, d, e, f, g, h, i, j, k, l, stoi(b));
    }

    file.close();

    // BST End Time
}


QString BackEnd::getbrand()
{
    return m_brand;
}

void BackEnd::setBrand(const QString &brand)
{
    if (brand == m_brand)
        return;

    m_brand = brand;
}

QString BackEnd::getprice()
{
    return m_price;
}

void BackEnd::setPrice(const QString &price)
{
    if (price == m_price)
        return;

     m_price = price;
}

QString BackEnd::getmileage()
{
    return m_mileage;
}

void BackEnd::setMileage(const QString &mileage)
{
    if (mileage == m_mileage)
        return;

    m_mileage = mileage;
}

bool BackEnd::readyToSearch()
{
    return true;
}

void BackEnd::beginSearch(const QString &x)
{
    QString getter;
    string brand;
    string price;
    string mileage;
    string treeType;

    getter = getbrand();
    brand = getter.toLocal8Bit().constData();

    for(int i = 0; i < brand.size(); i++)
    {
        if(brand.at(i) >= 65 && brand.at(i) <= 90)
            brand.at(i) += 32;
    }

    getter = getprice();
    price = getter.toLocal8Bit().constData();

    getter = getmileage();
    mileage = getter.toLocal8Bit().constData();

    vector<string> results;
    results.push_back("Brand\tModel\tYear\tPrice\tTransmission"
    "\tMileage\tFuel Type\tMPG\tEngine Size");

    if(x == "avl")
        atree.searchCar(brand, atree.getRoot(), price, mileage, results);
    else if(x == "bst")
        btree.searchCar(brand, btree.getRoot(), price, mileage);

    //q_results.clear();
    for (int i = 0; i < results.size(); i++)
    {
        QString line = QString::fromStdString(results[i]);
        q_results.append(line + '\n');
    }

}

/*void BackEnd::setResults(std::vector<std::string> text) {

}*/

QString BackEnd::getResults() {
    return q_results;
}

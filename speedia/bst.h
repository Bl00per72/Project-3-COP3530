#ifndef BST_H
#define BST_H
#include <string>
#include <iostream>
using namespace std;

class BST
{
    class Node
    {
    public:

        // Node Properties
        Node* left;
        Node* right;
        string brand;
        string model;
        string year;
        string price;
        string tran;
        string mileage;
        string fuelType;
        string tax;
        string mpg;
        string engineSize;
        long ID;

        // Constructors
        Node(string brand, string model, string year, string price, string tran, string mileage, string fuelType, string tax, string mpg, string engineSize, long ID)
        {
            this->brand = brand;
            this->model = model;
            this->year = year;
            this->price = price;
            this->tran = tran;
            this->mileage = mileage;
            this->fuelType = fuelType;
            this->tax = tax;
            this->mpg = mpg;
            this->engineSize = engineSize;
            this->ID = ID;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    Node* root;

public:
    Node* insertdataID(Node* root, string brand, string model, string year, string price, string tran, string mileage, string fuelType, string tax, string mpg, string engineSize, long ID);
    bool searchCar(string brand, Node* root, string price, string mileage);
    void setRoot(Node* root)
    {
        // Sets root
        this->root = root;
    }

    Node* getRoot()
    {
        // Gets root
        return this->root;
    }
};

#endif // BST_H

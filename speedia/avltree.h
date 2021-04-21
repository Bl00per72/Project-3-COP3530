#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class AVLTree
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
        Node(string brand, string model, string year, string price, string tran, string mileage, string fuelType, string tax, string mpg, string engineSize, long ID);
    };

    // AVL Tree Properties
    Node* root;
    bool containsdata;
    int numNodes;
    int compareNodes;

    // Helper Functions
    int height(Node* node);
    int max(int x, int y);
    int getBalanceFactor(Node* node);
    string padZeros(string ID);
    AVLTree::Node* rotateLeft(Node* node);
    AVLTree::Node* rotateRight(Node* node);
    AVLTree::Node* rotateLeftRight(Node* node);
    AVLTree::Node* rotateRightLeft(Node* node);

public:

    // Constructor
    AVLTree();

    // Tree Manipulation
    vector<string> searchCar(string brand, Node* root, string price, string mileage, vector<string> &s);
    void searchID(long ID, Node* root);
    Node* insertdataID(Node* root, string brand, string model, string year, string price, string tran, string mileage, string fuelType, string tax, string mpg, string engineSize, long ID);

    // Getters and Setters
    void setRoot(Node* root);
    Node* getRoot();
};

#endif // AVLTREE_H

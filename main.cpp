#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
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
    bool searchBrand(string brand, Node* root, string price, string model, string mileage);
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

BST::Node* BST::insertdataID(Node* root, string brand, string model, string year, string price, string tran, string mileage, string fuelType, string tax, string mpg, string engineSize, long ID)
{
    // If current node is null, insert new node and print successful
    if (root == nullptr)
    {
        return new Node(brand, model, year, price, tran, mileage, fuelType, tax, mpg, engineSize, ID);
    }
    // If ID is less than the current node's ID, go to left subtree
    if (stoi(price) > stoi(root->price))
    {
        root->right = insertdataID(root->right, brand, model, year, price, tran, mileage, fuelType, tax, mpg, engineSize, ID);
    }
    // If ID is greater than the current node's ID, go to right subtree
    else if (stoi(price) < stoi(root->price))
    {
        root->left = insertdataID(root->left, brand, model, year, price, tran, mileage, fuelType, tax, mpg, engineSize, ID);
    }
    // If ID is equal to the current node's ID, print unsuccesful and return
    else
    {
        return root;
    }

    return root;
}

bool BST::searchBrand(string brand, Node* root, string price, string model, string mileage)
{
    // If tree is empty, print unsuccessful
    if (this->root == nullptr)
    {
        return false;
    }
    // If current node is null, return
    else if (root == nullptr)
    {
        return true;
    }
    // Current node exists
    else
    {
        // If current node's data is equal to target data, print ID and keep traversing through tree
        if (root->brand == brand && stoi(root->price) <= stoi(price) && root->model == model && stoi(root->mileage) <= stoi(mileage))
        {
            cout << root->brand << " " << root->model << ", Year: " << root->year << " Price: " << root->price << " Transmission: "
                << root->tran << " Mileage: " << root->mileage << " Fuel Type: " << root->fuelType << " MPG: " << root->mpg << " Engine Size: " << root->engineSize << endl;
            //cout << endl;
            searchBrand(brand, root->left, price, model, mileage);
            searchBrand(brand, root->right, price, model, mileage);
        }
        // If current node's data is not equal to target data, keep traversing through tree
        else
        {
            searchBrand(brand, root->left, price, model, mileage);
            searchBrand(brand, root->right, price, model, mileage);
        }
        // If tree contains data, return true. Else, print unsuccessful
        if (root == this->root)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

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
    bool searchBrand(string brand, Node* root, string price, string model, string mileage);
    void searchID(long ID, Node* root);
    Node* insertdataID(Node* root, string brand, string model, string year, string price, string tran, string mileage, string fuelType, string tax, string mpg, string engineSize, long ID);

    // Getters and Setters
    void setRoot(Node* root);
    Node* getRoot();
};

AVLTree::AVLTree()
{
    // Initializes all tree properties and create AVLTree object
    this->root = nullptr;
    this->containsdata = false;
    this->numNodes = 0;
    this->compareNodes = 0;
}

bool AVLTree::searchBrand(string brand, Node* root, string price, string model, string mileage)
{
    // If tree is empty, print unsuccessful
    if (this->root == nullptr)
    {
        return false;
    }
    // If current node is null, return
    else if (root == nullptr)
    {
        return true;
    }
    // Current node exists
    else
    {
        // If current node's data is equal to target data, print ID and keep traversing through tree
        if (root->brand == brand && stoi(root->price) <= stoi(price) && root->model == model && stoi(root->mileage) <= stoi(mileage))
        {
            cout << root->brand << " " << root->model << ", Year: " << root->year << " Price: " << root->price << " Transmission: " 
                << root->tran << " Mileage: " << root->mileage << " Fuel Type: " << root-> fuelType << " MPG: " << root->mpg << " Engine Size: " << root->engineSize << endl;
            //cout << endl;
            this->containsdata = true;
            searchBrand(brand, root->left, price, model, mileage);
            searchBrand(brand, root->right, price, model, mileage);
        }
        // If current node's data is not equal to target data, keep traversing through tree
        else
        {
            searchBrand(brand, root->left, price, model, mileage);
            searchBrand(brand, root->right, price, model, mileage);
        }
        // If tree contains data, return true. Else, print unsuccessful
        if (root == this->root && this->containsdata == true)
        {
            this->containsdata = false;
            return true;
        }
        else
        {
            return false;
        }
    }
}

void AVLTree::searchID(long ID, Node* root)
{
    // If current node is null, print unsuccessful
    if (root == nullptr)
    {
    }
    // If tree is not empty
    else
    {
        // If target ID is less than current node ID, go to left subtree
        if (ID < root->ID)
        {
            searchID(ID, root->left);
        }
        // If target ID is greater than current node ID, go to right subtree
        else if (ID > root->ID)
        {
            searchID(ID, root->right);
        }
        // If target ID is equal to current node ID, print data
        else if (ID == root->ID)
        {
            cout << root->brand << endl;
        }
    }
}

AVLTree::Node* AVLTree::insertdataID(Node* root, string brand, string model, string year, string price, string tran, string mileage, string fuelType, string tax, string mpg, string engineSize, long ID)
{
    // If current node is null, insert new node and print successful
    if (root == nullptr)
    {
        this->numNodes++;
        return new Node(brand, model, year, price, tran, mileage, fuelType, tax, mpg, engineSize, ID);
    }
    // If ID is less than the current node's ID, go to left subtree
    if (stoi(price) > stoi(root->price))
    {
        root->right = insertdataID(root->right, brand, model, year, price, tran, mileage, fuelType, tax, mpg, engineSize, ID);
    }
    // If ID is greater than the current node's ID, go to right subtree
    else if (stoi(price) < stoi(root->price))
    {
        root->left = insertdataID(root->left, brand, model, year, price, tran, mileage, fuelType, tax, mpg, engineSize, ID);
    }
    // If ID is equal to the current node's ID, print unsuccesful and return
    else
    {
        return root;
    }

    int balanceFactor = getBalanceFactor(root);
    // Left Left Case
    if (balanceFactor == 2 && stoi(price) < stoi(root->left->price))
    {
        if (this->root == root)
        {
            this->root = root->left;
        }
        return rotateRight(root);
    }
    // Left Right Case
    else if (balanceFactor == 2 && stoi(price) > stoi(root->left->price))
    {
        if (this->root == root)
        {
            this->root = root->left->right;
        }
        return rotateLeftRight(root);
    }
    // Right Left Case
    else if (balanceFactor == -2 && stoi(price) < stoi(root->right->price))
    {
        if (this->root == root)
        {
            this->root = root->right->left;
        }
        return rotateRightLeft(root);
    }
    // Right Right Case
    else if (balanceFactor == -2 && stoi(price) > stoi(root->right->price))
    {
        if (this->root == root)
        {
            this->root = root->right;
        }
        return rotateLeft(root);
    }

    return root;
}

AVLTree::Node* AVLTree::rotateLeft(Node* node)
{
    // Simple left rotation implementation
    Node* newRoot;
    newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    return newRoot;
}

AVLTree::Node* AVLTree::rotateRight(Node* node)
{
    // Simple right rotation implementation 
    Node* newRoot;
    newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    return newRoot;
}

AVLTree::Node* AVLTree::rotateLeftRight(Node* node)
{
    // Simple left-right rotation implementation
    Node* newRoot = rotateLeft(node->left);
    node->left = newRoot;
    newRoot = rotateRight(node);
    return newRoot;
}

AVLTree::Node* AVLTree::rotateRightLeft(Node* node)
{
    // Simple right-left rotation implementation
    Node* newRoot = rotateRight(node->right);
    node->right = newRoot;
    newRoot = rotateLeft(node);
    return newRoot;
}

int AVLTree::max(int x, int y)
{
    // Simple max function
    if (x < y)
        return y;
    else
        return x;
}

string AVLTree::padZeros(string ID)
{
    // Pads string ID's with zeros if they don't have 8 digits
    if (ID.length() < 8)
    {
        string result = "";
        for (int i = 0; i < 8 - ID.length(); i++)
        {
            result += "0";
        }
        result += ID;
        return result;
    }
    return ID;
}

int AVLTree::height(Node* node)
{
    // Finds height of tree given the root 
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + max(height(node->left), height(node->right));
    }
}

int AVLTree::getBalanceFactor(Node* node)
{
    // Finds the balance factor of a certain node
    if (node == nullptr)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

void AVLTree::setRoot(Node* root)
{
    // Sets root
    this->root = root;
}

AVLTree::Node* AVLTree::getRoot()
{
    // Gets root
    return this->root;
}

AVLTree::Node::Node(string brand, string model, string year, string price, string tran, string mileage, string fuelType, string tax, string mpg, string engineSize, long ID)
{
    // (Overloaded constructor) Initializes node object
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

int main()
{

    // Start Time 
   
    BST a;

    ifstream file ("cars_shuffled.csv");

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
    a.setRoot(a.insertdataID(nullptr, c, d, e, f, g, h, i, j, k, l, stoi(b)));

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
        a.insertdataID(a.getRoot(), c, d, e, f, g, h, i, j, k, l, stoi(b));
    }

    file.close();

    // End Time

    string brand = "Toyota";

    for (int i = 0; i < brand.size(); i++)
    {
        if(brand.at(i) >= 65 && brand.at(i) <= 90)
            brand.at(i) = brand.at(i) + 32;
    }

    string price = "50000";
    string model = "Yaris";
    string mileage = "75000";
    a.searchBrand(brand, a.getRoot(), price, model, mileage);


   

    

}
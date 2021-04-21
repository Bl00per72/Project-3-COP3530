#include "avltree.h"

AVLTree::AVLTree()
{
    // Initializes all tree properties and create AVLTree object
    this->root = nullptr;
    this->containsdata = false;
    this->numNodes = 0;
    this->compareNodes = 0;
}

vector<string> AVLTree::searchCar(string brand, Node* root, string price, string mileage, vector<string> &s)
{
    // If tree is empty, print unsuccessful
    if (this->root == nullptr)
    {
        return s;
    }
    // If current node is null, return
    else if (root == nullptr)
    {
        return s;
    }
    // Current node exists
    else
    {
        // If current node's data is equal to target data, print ID and keep traversing through tree
        if (root->brand == brand && stoi(root->price) <= stoi(price) && stoi(root->mileage) <= stoi(mileage))
        {
            s.push_back(root->brand + "\t" + root->model + "\t" + root->year + "\t" + root->price + "\t"
                + root->tran + "\t\t" + root->mileage + "\t" + root-> fuelType + "\t" + root->mpg + "\t" + root->engineSize);

            //s.push_back(root->brand + " " + root->model + ", Year: " + root->year + " Price: " + root->price + " Transmission: "
            //    + root->tran + " Mileage: " + root->mileage + " Fuel Type: " + root-> fuelType + " MPG: " + root->mpg + " Engine Size: " + root->engineSize);


            this->containsdata = true;
            searchCar(brand, root->left, price, mileage, s);
            searchCar(brand, root->right, price, mileage, s);
        }
        // If current node's data is not equal to target data, keep traversing through tree
        else
        {
            searchCar(brand, root->left, price, mileage, s);
            searchCar(brand, root->right, price, mileage, s);
        }
    }

    return s;
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

#include "bst.h"


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

bool BST::searchCar(string brand, Node* root, string price, string mileage)
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
        if (root->brand == brand && stoi(root->price) <= stoi(price) && stoi(root->mileage) <= stoi(mileage))
        {
            cout << root->brand << " " << root->model << ", Year: " << root->year << " Price: " << root->price << " Transmission: "
                << root->tran << " Mileage: " << root->mileage << " Fuel Type: " << root->fuelType << " MPG: " << root->mpg << " Engine Size: " << root->engineSize << endl;
            //cout << endl;
            searchCar(brand, root->left, price, mileage);
            searchCar(brand, root->right, price, mileage);
        }
        // If current node's data is not equal to target data, keep traversing through tree
        else
        {
            searchCar(brand, root->left, price, mileage);
            searchCar(brand, root->right, price, mileage);
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

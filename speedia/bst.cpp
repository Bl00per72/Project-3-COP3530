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

vector<string> BST::searchCar(string brand, Node* root, string price, string mileage, vector<string> &s)
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

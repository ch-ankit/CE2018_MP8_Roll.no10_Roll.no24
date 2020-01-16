#include <iostream>
#include "bst.h"
//Function Definations
LinkedBST::LinkedBST()
{
    root = NULL;
}

LinkedBST::~LinkedBST() {}

void LinkedBST::printPreorder(Node *root)
{
    if (root == NULL)
    {
        std::cout << "There is no value to show" << std::endl;
        return;
    }
    std::cout << root->data << " ";
    if (root->left != NULL)
    {
        printPreorder(root->left);
    }
    if (root->right != NULL)
    {
        printPreorder(root->right);
    }
}

//Itterative Search
bool LinkedBST::searchBST(Node *root, int targetKey)
{
    if (root == NULL)
    {
        std::cout << "It is a Null tree" << std::endl;
    }
    else
    {
        Node *p = new Node();
        p = root;
        while (p != NULL)
        {
            if (targetKey > p->data)
            {
                p = p->right;
            }
            else if (targetKey < p->data)
            {
                p = p->left;
            }
            else if (targetKey == p->data)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

//Adding a Node to BST
void LinkedBST::addBST(Node *root, Node *newNode)
{
    if (root == NULL)
    {
        this->root = newNode;
    }
    else
    {
        if (root->data > newNode->data)
        {
            if (root->left != NULL)
            {
                addBST(root->left, newNode);
            }
            else
            {
                root->left = newNode;
            }
        }
        else
        {
            if (root->right != NULL)
            {
                addBST(root->right, newNode);
            }
            else
            {
                root->right = newNode;
            }
        }
    }
}

//Deleting Node recursive way.
void LinkedBST::deleteBST(Node *root, int keytoDelete)
{
    int dat;
    if (root == NULL)
    {
        std::cout << "tree is empty" << std::endl;
        return;
    }
    if (keytoDelete < root->data)
    {
        Node *temp = new Node();
        temp = root->left;
        if (root->left->data == keytoDelete && root->left->left == NULL && root->left->right == NULL)
        {
            root->left = NULL;
        }
        deleteBST(temp, keytoDelete);
        return;
    }
    else if (keytoDelete > root->data)
    {
        Node *temp = new Node();
        temp = root->right;
        if (root->right->data == keytoDelete && root->right->left == NULL && root->right->right == NULL)
        {
            root->right = NULL;
        }
        deleteBST(temp, keytoDelete);
        return;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            return;
        }
        else if (root->left == NULL)
        {
            Node *temp = new Node();
            temp = root->right;
            root->data = root->right->data;
            root->right = root->right->right;
            delete temp;
            return;
        }
        else if (root->right == NULL)
        {
            Node *temp = new Node();
            temp = root->left;
            root->data = root->left->data;
            root->left = root->left->left;
            delete temp;
            return;
        }
        else
        {
            Node *nodetoDelete = new Node();
            nodetoDelete = root;
            Node *newNode = new Node();
            newNode = root->left;
            while (newNode->right != NULL)
            {
                newNode = newNode->right;
            }
            dat = newNode->data;
            deleteBST(nodetoDelete, newNode->data);
            root->data = dat;

            return;
        }
    }
}
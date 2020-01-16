#ifndef BinarySearchTree_h
#define BinarySearchTree_h

//Implementing using linked list

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    friend class LinkedBST;
    Node()
    {
        data = 0;
        left = right = NULL;
    }
};

class LinkedBST
{
public:
    Node *root = new Node();
    LinkedBST();
    ~LinkedBST();
    bool searchBST(Node *root, int targetKey);
    void addBST(Node *root, Node *newNode);
    void deleteBST(Node *root, int keyToDelete);
    void printPreorder(Node *node);
};

#endif /*BinarySearchTree_h*/
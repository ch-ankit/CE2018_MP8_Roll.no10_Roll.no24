#include "bst.cpp"
int main()
{
    LinkedBST tree;
    //Creating nodes to add in tree
    Node *newNode1 = new Node();
    newNode1->data = 45;
    Node *newNode2 = new Node();
    newNode2->data = 50;
    Node *newNode3 = new Node();
    newNode3->data = 20;
    Node *newNode4 = new Node();
    newNode4->data = 60;
    Node *newNode5 = new Node();
    newNode5->data = 10;
    Node *newNode6 = new Node();
    newNode6->data = 46;
    //adding the nodes
    tree.addBST(tree.root, newNode1);
    tree.addBST(tree.root, newNode2);
    tree.addBST(tree.root, newNode3);
    tree.addBST(tree.root, newNode4);
    tree.addBST(tree.root, newNode5);
    tree.addBST(tree.root, newNode6);
    tree.printPreorder(tree.root);
    std::cout << "\n";
    if (tree.searchBST(tree.root, 10))
    {
        std::cout << "Number Found" << std::endl;
    }
    else
    {
        std::cout << "Not Found" << std::endl;
    }
    tree.deleteBST(tree.root, 10);
    if (tree.searchBST(tree.root, 10))
    {
        std::cout << "Number Found" << std::endl;
    }
    else
    {
        std::cout << "Not Found" << std::endl;
    }
    tree.printPreorder(tree.root);
}
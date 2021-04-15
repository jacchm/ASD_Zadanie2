#include <iostream>
#include "BinaryTree.h"

using namespace std;
int main() {
    std::cout << "To jest imlementacja drzewa binarnego" << std::endl;

    cout << endl << endl;

    auto* tree = new BinaryTree();

    tree->insertKey(10);
    tree->insertKey(5);
    tree->insertKey(4);
    tree->insertKey(8);
    tree->insertKey(7);
    tree->insertKey(12);
    tree->insertKey(11);
    tree->insertKey(15);
    tree->insertKey(17);
    tree->insertKey(9);

    tree->print();

    tree->preorder();
    tree->inorder();
    tree->postorder();

    return 0;
}

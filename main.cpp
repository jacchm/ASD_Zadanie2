#include <iostream>
#include "BinaryTree.h"

using namespace std;
int main() {
    cout << "Binary tree implementation:" << endl << endl;

    auto* tree = new BinaryTree();

    cout << "Size: " << tree->getSizeOfTree() << endl;

    tree->insertValue(10);
    tree->insertValue(5);
    tree->insertValue(4);
    tree->insertValue(8);
    tree->insertValue(7);
    tree->insertValue(12);
    tree->insertValue(11);
    tree->insertValue(15);
    tree->insertValue(17);
    tree->insertValue(9);
    tree->insertValue(2);
    tree->insertValue(3);
    tree->insertValue(22);
    tree->print();

    cout << "Size: " << tree->getSizeOfTree();

    return 0;
}

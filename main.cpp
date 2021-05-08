#include <iostream>
#include "BinaryTree.h"

using namespace std;
int main() {
    std::cout << "To jest imlementacja drzewa binarnego" << std::endl;

    cout << endl << endl;

    auto* tree = new BinaryTree();

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

    tree->print();

    return 0;
}

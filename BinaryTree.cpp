#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree() {
    top = nullptr;
}

BinaryTree::TreeNode *BinaryTree::createVertex(const int value) {
    TreeNode *v = new TreeNode();
    v->value = value;
    v->left = nullptr;
    v->right = nullptr;
    return v;
}

BinaryTree::TreeNode *BinaryTree::insertValue(TreeNode *parent, const int value) {
    // if there is no root
    if (parent == nullptr) {
        return createVertex(value);
    }
    // new value is smaller than parent's value -> insert on the left
    if (value < parent->value) {
        parent->left = insertValue(parent->left, value);
    }
        // new value is greater than parent's value -> insert on the right
    else {
        parent->right = insertValue(parent->right, value);
    }
    return parent;
}

void BinaryTree::insertValue(const int key) {
    top = insertValue(top, key);
}

void BinaryTree::print(const string &prefix,
                       const TreeNode *v,
                       const bool isLeft,
                       const bool isTop) {

    if (v != nullptr) {
        cout << prefix;
        cout << (isTop ? "--------" : (isLeft ? "|--(L)--" : "|__(R)__"));

        // wypisz wartosc wierzcholka
        cout << "[" << v->value << "] " << endl;

        // wypisz nastepny poziom - lewa i praw galaz
        print(prefix + (isLeft ? "|        " : "         "),
              v->left,
              true,
              false);

        print(prefix + (isLeft ? "|        " : "         "),
              v->right,
              false,
              false);
    }
}

void BinaryTree::print() {
    print(EMPTY_STRING, top, false, true);
}

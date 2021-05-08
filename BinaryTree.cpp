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

int BinaryTree::getSizeOfTree() {
    // if the tree is empty
    if (top == nullptr) {
        return 0;
    }

    int leftSize = countNodes(top->left);
    int rightSize = countNodes(top->right);

    return leftSize + rightSize + 1;
}

int BinaryTree::countNodes(TreeNode *node) {
    if (node == nullptr) {
        return 0;
    }
    int leftSize = countNodes(node->left);
    int rightSize = countNodes(node->right);

    return leftSize + rightSize + 1;
}

void BinaryTree::print(const string &prefix,
                       const TreeNode *node,
                       const bool isLeft,
                       const bool isTop) {

    if (node != nullptr) {
        cout << prefix;
        cout << (isTop ? "--------" : (isLeft ? "|--(L)--" : "|__(R)__"));

        // wypisz wartosc wierzcholka
        cout << "[" << node->value << "] " << endl;

        // wypisz nastepny poziom - lewa i praw galaz
        print(prefix + (isLeft ? "|        " : "         "),
              node->left,
              true,
              false);

        print(prefix + (isLeft ? "|        " : "         "),
              node->right,
              false,
              false);
    }
}

void BinaryTree::print() {
    print(EMPTY_STRING, top, false, true);
}

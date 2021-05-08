#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree() {
    top = nullptr;
}

BinaryTree::TreeNode *BinaryTree::createVertex(const int key) {
    TreeNode *v = new TreeNode();
    v->key = key;
    v->left = nullptr;
    v->right = nullptr;
    return v;
}

BinaryTree::TreeNode *BinaryTree::insertKey(TreeNode *parent, const int key) {
    // if there is no root
    if (parent == nullptr) {
        return createVertex(key);
    }
    // new value is smaller than parent's value -> insert on the left
    if (key < parent->key) {
        parent->left = insertKey(parent->left, key);
    }
        // new value is greater than parent's value -> insert on the right
    else {
        parent->right = insertKey(parent->right, key);
    }
    return parent;
}

void BinaryTree::insertKey(const int key) {
    top = insertKey(top, key);
}

void BinaryTree::print(const string &prefix,
                       const TreeNode *v,
                       const bool isLeft,
                       const bool isTop) {

    if (v != nullptr) {
        cout << prefix;
        cout << (isTop ? "--------" : (isLeft ? "|--(L)--" : "|__(R)__"));

        // wypisz wartosc wierzcholka
        cout << "[" << v->key << "] " << endl;

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

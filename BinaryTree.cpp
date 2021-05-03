#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree() {
    top = nullptr;
}

BinaryTree::~BinaryTree() {
    delete top;
}

BinaryTree::Vertex* BinaryTree::createVertex(const int key) {
    Vertex* v = new Vertex();
    v->key = key;
    v->left = nullptr;
    v->right = nullptr;
    return v;
}

BinaryTree::Vertex* BinaryTree::insertKey(Vertex * parent,
                                          const int key) {
    if(parent == nullptr) {
        return createVertex(key);
    }

    if(key < parent->key) {
        parent->left = insertKey(parent->left, key);
    }
    else {
        parent->right = insertKey(parent->right, key);
    }
    return parent;
}

void BinaryTree::insertKey(const int key) {
    top = insertKey(top, key);
}

void BinaryTree::preorder() {
    cout << endl << "PREORDER: " << endl;
    preorder(top);
}

void BinaryTree::preorder(const Vertex* v) {
    printVertex(v);
    if(v->left != nullptr) {
        preorder(v->left);
    }
    if(v->right != nullptr) {
        preorder(v->right);
    }
}

void BinaryTree::postorder() {
    cout << endl << "POSTORDER: " << endl;
    postorder(top);
}

void BinaryTree::postorder(const Vertex * v) {
    if(v->left != nullptr) {
        postorder(v->left);
    }
    if(v->right != nullptr) {
        postorder(v->right);
    }
    printVertex(v);
}

void BinaryTree::inorder() {
    cout << endl << "INORDER: " << endl;
    inorder(top);
}

void BinaryTree::inorder(const Vertex * v) {
    if(v->left != nullptr) {
        inorder(v->left);
    }
    printVertex(v);
    if(v->right != nullptr) {
        inorder(v->right);
    }
}

void BinaryTree::print(const string &prefix,
                       const Vertex* v,
                       const bool isLeft,
                       const bool isTop) {

    if(v != nullptr) {
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

void BinaryTree::printVertex(const Vertex * v) {
    cout << v->key << ", ";
}

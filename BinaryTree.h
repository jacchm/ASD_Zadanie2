#include <iostream>

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H
#define EMPTY_STRING ""

using namespace std;
class BinaryTree {

private:
    struct Vertex {
        int key;
        Vertex* left;
        Vertex* right;
    };
    Vertex* top;

    void print(const string &prefix,
               const Vertex *v,
               bool isLeft,
               bool isTop);

    Vertex * insertKey(Vertex *, int);

public:
    BinaryTree();
    ~BinaryTree();
    static Vertex* createVertex(int);
    void insertKey(int);
    void preorder();
    static void preorder(const Vertex*);
    void postorder();
    static void postorder(const Vertex*);
    void inorder();
    static void inorder(const Vertex*);
    void print();
    static void printVertex(const Vertex *);
};
#endif //BINARYTREE_BINARYTREE_H

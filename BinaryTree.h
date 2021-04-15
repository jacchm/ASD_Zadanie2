#include <iostream>

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H
#define EMPTY_STRING ""


class BinaryTree {

private:
    struct Vertex {
        int key;
        Vertex* left;
        Vertex* right;
    };
    Vertex* top;

    void print(const std::string &prefix, const Vertex *v, bool isLeft, bool isTop);
    Vertex * insertKey(Vertex *, int);

public:
    BinaryTree();
    ~BinaryTree();
    static Vertex* createVertex(int);
    void insertKey(int);
    void preorder();
    static void preorder(Vertex*);
    void postorder();
    static void postorder(Vertex*);
    void inorder();
    static void inorder(Vertex*);
    void print();
    static void printVertex(Vertex *);
};


#endif //BINARYTREE_BINARYTREE_H

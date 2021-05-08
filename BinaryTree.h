#include <iostream>

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H
#define EMPTY_STRING ""

using namespace std;
class BinaryTree {

private:
    struct TreeNode {
        int key;
        TreeNode* left;
        TreeNode* right;
    };
    TreeNode* top;

    void print(const string &prefix,
               const TreeNode *v,
               bool isLeft,
               bool isTop);

    TreeNode * insertKey(TreeNode *, int);

public:
    BinaryTree();
    static TreeNode* createVertex(int);
    void insertKey(int);
    void print();
};
#endif //BINARYTREE_BINARYTREE_H

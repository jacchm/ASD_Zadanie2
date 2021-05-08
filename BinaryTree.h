#include <iostream>

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H
#define EMPTY_STRING ""

using namespace std;
class BinaryTree {

private:
    struct TreeNode {
        int value;
        TreeNode* left;
        TreeNode* right;
    };
    TreeNode* top;

    void print(const string &prefix, const TreeNode *node, bool isLeft, bool isTop);

    TreeNode * insertValue(TreeNode *, int);
    int countNodes(TreeNode *node);

public:
    BinaryTree();
    static TreeNode* createVertex(int);
    int getSizeOfTree();
    void insertValue(int);
    void print();
};
#endif

#ifndef TREE_NODE_H
#define TREE_NODE_H

class TreeNode
{
public:
    TreeNode(double x1, double y1, TreeNode* left1, TreeNode* right1);
    double x;
    double y;
    TreeNode* left  = nullptr;
    TreeNode* right = nullptr;
};

#endif // TREE_NODE_H

#ifndef TREE_H
#define TREE_H
#include <utility>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <QDebug>
#include "time.h"
#include <chrono>
using namespace std;

class Tree
{
public:
    Tree(double* arr, int n, double _min, double _max)
    {
        auto start = chrono::high_resolution_clock::now();
        srand(time(0));
        for(int i = 0; i < n; i++)
        {
            insert_node(arr[i], _min, _max);
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float> duration = end - start;
        qDebug() << "Duration: " << duration.count() << "s";
    }
    void insert_node(double key, double _min, double _max)
    {
        pair <TreeNode*, TreeNode*> p = split(head, key);
        TreeNode* t = new TreeNode(key, random_double(_min, _max), NULL, NULL);
        head = marge(marge(p.first, t), p.second);
    }
    void delete_node(double key)
    {
        TreeNode* H = head;
        int son = -1;
        TreeNode* parent = NULL;
        while(H)
        {
            if(H->x == key)
            {
                TreeNode* H2 = marge(H->left, H->right);
                if(H2)
                {
                    H->x = H2->x;
                    H->y = H2->y;
                    H->left = H2->left;
                    H->right = H2->right;
                    delete H2;
                }
                else
                {
                    delete H;
                    if(parent)
                    {
                        if(son == 0)
                        {
                            parent->left = NULL;
                        }
                        else
                        {
                            parent->right = NULL;
                        }
                    }
                    else
                    {
                        head = NULL;
                    }
                }
                return;
            }
            else
            if(H->x > key)
            {
                parent = H;
                H = H->left;
                son = 0;
            }
            else
            {
                parent = H;
                H = H->right;
                son = 1;
            }
        }
    }
    vector <vector <pair <double, double> > > get_points()
    {
        vector <vector <pair <double, double> > > v;
        get_points_recurse(head, &v);
        return v;
    }
    double min_node()
    {
        if(head)
        {
            TreeNode* H = head;
            while(H->left)
            {
                H = H->left;
            }
            return H->x;
        }
        return 0;
    }
    double max_node()
    {
        if(head)
        {
            TreeNode* H = head;
            while(H->right)
            {
                H = H->right;
            }
            return H->x;
        }
        return 1;
    }
private:
    struct TreeNode
    {
        double x;
        double y;
        TreeNode* left  = NULL;
        TreeNode* right = NULL;
        TreeNode(double x1, double y1, TreeNode* left1, TreeNode* right1)
        {
            x = x1;
            y = y1;
            left = left1;
            right = right1;
        }
    };
    TreeNode* head = NULL;
    TreeNode* marge(TreeNode* LTree, TreeNode* RTree)
    {
        if(LTree == NULL) return RTree;
        if(RTree == NULL) return LTree;
        if(LTree->y > RTree->y)
        {
            LTree->right = marge(LTree->right, RTree);
            return LTree;
        }
        else
        {
            RTree->left = marge(LTree, RTree->left);
            return RTree;
        }
    }
    pair <TreeNode*, TreeNode*> split(TreeNode* tree, double key)
    {
        if(tree == NULL)
            return pair <TreeNode*, TreeNode*> (NULL, NULL);
        if(key > tree->x)
        {
            pair <TreeNode*, TreeNode*> p = split(tree->right, key);
            tree->right = p.first;
            return pair <TreeNode*, TreeNode*> (tree, p.second);
        }
        else
        {
            pair <TreeNode*, TreeNode*> p = split(tree->left, key);
            tree->left = p.second;
            return pair <TreeNode*, TreeNode*> (p.first, tree);
        }
    }
    void get_points_recurse(TreeNode* H, vector <vector <pair <double, double> > >* v2)
    {
        if(H)
        {
            get_points_recurse(H->left, v2);
            pair <double, double> p1(H->x, H->y);
            pair <double, double> p2;
            pair <double, double> p3;
            if(H->left)
            {
               p2.first = H->left->x;
               p2.second = H->left->y;
            }
            else
            {
                p2.first = p2.second = -1;
            }
            if(H->right)
            {
               p3.first = H->right->x;
               p3.second = H->right->y;
            }
            else
            {
                p3.first = p3.second = -1;
            }
            vector<pair <double, double> > v1 = {p1, p2, p3};
            v2->push_back(v1);
            get_points_recurse(H->right, v2);
        }
    }
    double random_double(double _min, double _max)
    {
        return _min + double(rand()) / RAND_MAX * (_max - _min);
    }
};

#endif // TREE_H

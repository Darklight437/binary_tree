#pragma once

#include "TreeNode.h"

class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();

    //returns true if the tree has no root
    bool isEmpty() const;

    //places new node based on binary system
    void insert(int Value);
    //removes and reconnects relevant nodes
    void remove(int Value);
    //finds nodes with specified value
    TreeNode* find(int Value);


private:
    //find the node with the specified value
    bool findNode(int a_nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent);

    //the root node
    TreeNode* m_pRoot;
};


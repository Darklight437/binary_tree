#pragma once

typedef TreeNode*   TreePtr;



class TreeNode
{
public:

    
    
    TreeNode(int value);
    ~TreeNode();


    //bool isRightNode() { return m_rightNode; }
    bool hasLeft();
    bool hasRight();
    int getData();
    TreePtr getLeft();
    TreePtr getRight();
    TreePtr getParent();
    void setData(int value);
    void setLeft(TreePtr node);
    void setRight(TreePtr node);
    void setParent(TreePtr node);

private:
    TreePtr m_parent;
    TreePtr m_left;
    TreePtr m_right;
    int m_value;
    //we'll see about you
    //bool m_rightNode;

};


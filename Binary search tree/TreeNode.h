#pragma once

typedef TreeNode*   TreePtr;



class TreeNode
{
public:

    
    
    TreeNode(int value);
    ~TreeNode();



    bool hasLeft() { return (m_left != nullptr);}
    bool hasRight() { return (m_right != nullptr);}
    int getData() { return m_value; }
    TreePtr getLeft() { return m_left; }
    TreePtr getRight() { return m_right; }
    void setData(int value) { m_value = value; }
    void setLeft(TreePtr node) { m_left = node; }
    void setRight(TreePtr node) { m_right = node; }


private:
    TreePtr m_parent;
    TreePtr m_left;
    TreePtr m_right;
    int m_value;


};


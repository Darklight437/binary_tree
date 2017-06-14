#pragma once
class TreeNode
{
public:


    TreeNode(int value);
    ~TreeNode();

    void insertNode(int value);
    void deleteNode(TreeNode);


    bool hasLeft() { return (m_left != nullptr);}
    bool hasRight() { return (m_right != nullptr);}
    int getData() { return m_value; }
    TreeNode* getLeft() { return m_left; }
    TreeNode* getRight() { return m_right; }

private:
    TreeNode* p_parent;
    TreeNode* m_left;
    TreeNode* m_right;
    int m_value;


};


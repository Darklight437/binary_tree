#pragma once
class TreeNode
{
public:
    TreeNode();
    ~TreeNode();

    void insert(int value);
    void deleteNode(TreeNode);


private:
    TreeNode* p_parent;
    TreeNode* p_left;
    TreeNode* p_right;



};


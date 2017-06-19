#include "TreeNode.h"



TreeNode::TreeNode(int value)
{
    m_value = value;
}

TreeNode::TreeNode()
{

}

TreeNode::~TreeNode()
{
}

bool TreeNode::hasLeft()
{
     return (m_left != nullptr); 
}

bool TreeNode::hasRight()
{
     return (m_right != nullptr); 
}

int TreeNode::getData()
{
     return m_value; 
}

TreePtr TreeNode::getLeft()
{
    return m_left;
}

TreePtr TreeNode::getRight()
{
    return m_right;
}

TreePtr TreeNode::getParent()
{
    return m_parent;
}

void TreeNode::setData(int value)
{
    m_value = value;
}

void TreeNode::setLeft(TreePtr node)
{
    m_left = node;
}

void TreeNode::setRight(TreePtr node)
{
    m_right = node;
}

void TreeNode::setParent(TreePtr node)
{
    m_parent = node;
}











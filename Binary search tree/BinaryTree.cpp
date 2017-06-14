#include "BinaryTree.h"



BinaryTree::BinaryTree()
{
    m_pRoot = nullptr;
}


BinaryTree::~BinaryTree()
{

}

bool BinaryTree::isEmpty() const
{
    if (m_pRoot == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BinaryTree::insert(int Value)
{
    TreeNode* newNode = new TreeNode(Value); 
    TreeNode* currentNode = m_pRoot;
    TreeNode* tempNode;
    if (m_pRoot == nullptr)
    {
        m_pRoot = newNode;
    }
    while (currentNode != nullptr)
    {
        //if the value is less than the value of the current node
        (newNode->getData < currentNode->getData) ? (currentNode = currentNode->getLeft()) : (currentNode = currentNode->getRight());
        if (currentNode->getLeft == nullptr || currentNode->getRight == nullptr)
        {
            tempNode = currentNode;
        }
        if (newNode->getData == currentNode->getData)
        {
            //the value is already in the tree exit out
            return;
        }
    }
    //set newnode's parent to tempnode
    
    if (newNode->getData < tempNode->getData)
    {
        tempNode->getLeft = newNode;
    }
    


}

void BinaryTree::remove(int Value)
{

}

TreeNode * BinaryTree::find(int Value)
{
    return nullptr;
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode ** ppOutNode, TreeNode ** ppOutParent)
{
    return false;
}

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
    return false;
}

void BinaryTree::insert(int Value)
{
    TreeNode* newNode = new TreeNode(Value); 
    TreeNode* currentNode = m_pRoot;
    if (m_pRoot == nullptr)
    {
        m_pRoot = newNode;
    }
    while (newNode != nullptr)
    {
        //if the value is less than the value of the current node
        (newNode->getData < currentNode->getData) ? (currentNode = currentNode->getLeft()) : (currentNode = currentNode->getRight());
        if (newNode->getData == currentNode->getData)
        {
            //the value is already in the tree exit out
            return;
        }


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

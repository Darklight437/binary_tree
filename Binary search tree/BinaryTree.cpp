#include "BinaryTree.h"



BinaryTree::BinaryTree()
{
    m_Root = nullptr;
}


BinaryTree::~BinaryTree()
{

}

bool BinaryTree::isEmpty() const
{
    if (m_Root == nullptr)
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
    TreePtr newNode = new TreeNode(Value); 
    TreePtr currentNode = m_Root;
    TreePtr tempNode;
    if (m_Root == nullptr)
    {
        m_Root = newNode;
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
    else
    {
        tempNode->getRight = newNode;
    }
    


}

void BinaryTree::remove(int Value)
{
    TreePtr parentNode;
    TreePtr deletNode;
    //TreePtr searchNode;
    findNode(Value, deletNode, parentNode);
    //no child case
    if (deletNode->getRight == nullptr && deletNode-> getLeft == nullptr)
    {
        //set the correct side pointer to null
        (parentNode->getLeft() == deletNode) ? (parentNode->setLeft(nullptr)) : (parentNode->setRight(nullptr));
        delete deletNode;
    }


    //one child case
    //sick XOR operator here for one child case
    if (deletNode->getLeft() != nullptr ^ deletNode->getRight() != nullptr)
    {
        if (deletNode == m_Root)
        {
            //make the child node the root and delete the current root
            (deletNode->getLeft() != nullptr) ? (m_Root = deletNode->getRight()) : (m_Root = deletNode->getLeft());
            delete deletNode;
            
        }
        else
        {

            //find out where the child of deletNode is
            //which side of parent is delet on
            if (parentNode->getRight() == deletNode)
            {

                //get the relevant pointer to deletNode
                
                //set pointer to deletNode to child instead and delet deletNode
            }
            else
            {

            }

        }

        
    }

}

TreeNode * BinaryTree::find(int Value)
{
    //panic at the disco
    return nullptr;
}

bool BinaryTree::findNode(int SearchValue, TreePtr & outNode, TreePtr & outParent)
{
    TreePtr currentNode;
    //search the tree for an object
    while (currentNode != nullptr)    
    {
        if (SearchValue == currentNode->getData)
        {
            outNode = currentNode;
            outParent = currentNode->getParent();
        }
        else if(SearchValue < currentNode->getData)
        {
            currentNode = currentNode->getLeft();
        }
        else
        {
            currentNode = currentNode->getRight();
        }
    }


    return false;
}

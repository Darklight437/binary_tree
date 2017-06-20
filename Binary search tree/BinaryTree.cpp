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
        return;
    }
    while (currentNode != tempNode)
    {


        if (newNode->getData() == currentNode->getData())
        {
            //the value is already in the tree exit out
            return;
        }


        //if the value is less than the value of the current node go left else go right
        (newNode->getData() < currentNode->getData()) ? (currentNode = currentNode->getLeft()) : (currentNode = currentNode->getRight());


        //if at the end of the tree
        if (currentNode->getLeft() == nullptr || currentNode->getRight() == nullptr)
        {
            tempNode = currentNode;
        }
        
    }
    //set newnode's parent to tempnode
    
    if (newNode->getData() < tempNode->getData())
    {
        tempNode->setLeft(newNode);
    }
    else
    {
        tempNode->setRight(newNode);
    }
    


}

void BinaryTree::remove(int Value)
{
    TreePtr parentNode;
    TreePtr deletNode;
    TreePtr searchNode;
    findNode(Value, deletNode, parentNode);
    //no child case
    if (deletNode->getRight() == nullptr && deletNode-> getLeft() == nullptr)
    {
        //set the correct side pointer to null
        (parentNode->getLeft() == deletNode) ? (parentNode->setLeft(nullptr)) : (parentNode->setRight(nullptr));
        delete deletNode;
    }


    //one child case
    //sick XOR operator here for one child case
    if ((deletNode->getLeft() != nullptr) ^ (deletNode->getRight() != nullptr))
    {
        if (deletNode == m_Root)
        {
            //make the child node the root and delete the current root
            (deletNode->getLeft() != nullptr) ? (m_Root = deletNode->getRight()) : (m_Root = deletNode->getLeft());
            delete deletNode;
            
        }
        else
        {
            TreePtr childNode;
            //find out where the child of deletNode is
            (deletNode->getLeft() != nullptr) ? (childNode = deletNode->getLeft()) : (childNode = deletNode->getRight());
            //which side of parent is delet on
            if (parentNode->getRight() == deletNode)
            {
                parentNode->setRight(childNode);
                delete deletNode;
            }
            else
            {
                parentNode->setLeft(childNode);
                delete deletNode;
            }

        }

        
    }

    //2 childeren case
    if (deletNode->getLeft() != nullptr && deletNode->getRight() != nullptr)
    {
        TreePtr searchparent;
        searchNode = deletNode->getRight();
        while (searchNode->hasLeft() == true)
        {
            searchNode = searchNode->getLeft();
        }

        deletNode->setData(searchNode->getData());
        //deal with the child node if there is one
        if (searchNode->hasRight() == true)
        {
            TreePtr childNode = searchNode->getRight();
            //find out where the child of deletNode is

            //which side of parent is delet on
            if (searchparent->getRight() == deletNode)
            {
                searchparent->setRight(childNode);
                delete searchNode;
            }
            else
            {
                searchparent->setLeft(childNode);
                delete searchNode;
            }
        }
        else
        {
            searchparent = searchNode->getParent();
            (searchparent->getLeft() == searchNode) ? (searchparent->setLeft(nullptr)) : (searchparent->setRight(nullptr));
            delete searchNode;
        }
        //deleting the minimum

       

        

     
    }

}

TreeNode * BinaryTree::find(int Value)
{
    //panic at the disco
    return nullptr;
}

bool BinaryTree::findNode(int SearchValue, TreePtr & outNode, TreePtr & outParent)
{
    TreePtr currentNode = m_Root;
    //search the tree for an object
    while (currentNode != nullptr)    
    {
        if (SearchValue == currentNode->getData())
        {
            outNode = currentNode;
            outParent = currentNode->getParent();
            return true;
        }
        else if(SearchValue < currentNode->getData())
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

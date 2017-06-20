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
    TreePtr foundNode = nullptr;
    if (m_Root == nullptr)
    {
        m_Root = newNode;
        return;
    }
    while (currentNode != foundNode)
    {


        if (newNode->getData() == currentNode->getData())
        {
            //the value is already in the tree exit out
            return;
        }


        //if the value is less than the value of the current node go left else go right
        
       
        if (newNode->getData()< currentNode->getData())
        {
            
            if (currentNode->getLeft() != nullptr)
            {
                currentNode = currentNode->getLeft();
            }
            else 
            {
                foundNode = currentNode;
            }
        }
        else
        {
            if (currentNode->getRight() != nullptr)
            {
                currentNode = currentNode->getRight();
            }
            else
            {
                foundNode = currentNode;
                
            }
        }


       
        
    }
    //set newnode's parent to foundNode
    
    if (newNode->getData() < foundNode->getData())
    {
        foundNode->setLeft(newNode);
        newNode->setParent(foundNode);
    }
    else
    {
        foundNode->setRight(newNode);
        newNode->setParent(foundNode);
    }
    


}


//TODO make sure all connected pointers are cleaned up correctly
void BinaryTree::remove(int Value)
{
    TreePtr parentNode;
    TreePtr deletNode;
    TreePtr searchNode;
    
    if (findNode(Value, deletNode, parentNode) == true)
    {

    
    //no child case
        if (deletNode->getRight() == nullptr && deletNode-> getLeft() == nullptr)
        {
        //set the correct side pointer to null
        (parentNode->getLeft() == deletNode) ? (parentNode->setLeft(nullptr)) : (parentNode->setRight(nullptr));
        delete deletNode;
        //pointers == good
        }


        //one child case
        //sick XOR operator here for one child case
        if ((deletNode->getLeft() != nullptr) ^ (deletNode->getRight() != nullptr))
        {
            if (deletNode == m_Root)
            {
                //make the child node the root and delete the current root
                (deletNode->getLeft() != nullptr) ? (m_Root = deletNode->getRight()) : (m_Root = deletNode->getLeft());
                m_Root->setParent(nullptr);
                delete deletNode;
                return;
                //pointers == good
            
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
                childNode->setParent(parentNode);
                delete deletNode;
                return;
                //ptr == good
            }
            else
            {
                parentNode->setLeft(childNode);
                childNode->setParent(parentNode);
                delete deletNode;
                return;
                //ptr == good
            }

        }
        }
    

        //2 childeren case
        if (deletNode->getLeft() != nullptr && deletNode->getRight() != nullptr)
        {
        
            searchNode = deletNode->getRight();
            TreePtr searchparent = searchNode->getParent();
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
                    return;
                }
                else
                {
                    searchparent->setLeft(childNode);
                    delete searchNode;
                    return;
                }
            }
            else
            {
                searchparent = searchNode->getParent();
                (searchparent->getLeft() == searchNode) ? (searchparent->setLeft(nullptr)) : (searchparent->setRight(nullptr));
                delete searchNode;
                return;
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

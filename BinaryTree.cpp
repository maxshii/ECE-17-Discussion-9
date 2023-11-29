#include<iostream>
#include "BinaryTree.h"

BinaryTree::Node::Node(int aVal, Node* leftPtr = nullptr, Node* rightPtr = nullptr)
{
    val = aVal;
    left = leftPtr;
    right = rightPtr;
}

BinaryTree::BinaryTree()
{
    root = nullptr;
}

void BinaryTree::insert(Node* &aNodePtr, Node* &aNewNodePtr)
{
    if(aNodePtr == nullptr)
    {
        aNodePtr = aNewNodePtr;
    }
    else if(aNodePtr->val < aNewNodePtr->val)
    {
        insert(aNodePtr->left, aNewNodePtr);
    }
    else
    {
        insert(aNodePtr->right, aNewNodePtr);
    }
}

void BinaryTree::deleteNode(int aVal, Node* &aNodePtr)
{
    if(aVal < aNodePtr->val)
    {
        deleteNode(aVal, aNodePtr->left);
    }
    else if(aVal > aNodePtr->val)
    {
        deleteNode(aVal, aNodePtr->right);
    }
    else
    {
        makeDeletion(aNodePtr);
    }
}

void BinaryTree::makeDeletion(Node* &aNodePtr)
{
    Node* tempNodePtr = nullptr;

    if(aNodePtr == nullptr)
    {
        std::cout << "Cannot remove empty Node" << std::endl;

    }
    else if(aNodePtr->right == nullptr)
    {
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->right;
        delete tempNodePtr;
    }
    else if(aNodePtr->left == nullptr)
    {
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->left;
        delete tempNodePtr;
    }
    else
    {
        tempNodePtr = aNodePtr->right;
    
        while(tempNodePtr->left)
        {
            tempNodePtr = tempNodePtr->left;
        }

        tempNodePtr->left = aNodePtr->left;

        tempNodePtr = aNodePtr;
        aNodePtr = tempNodePtr->right;
        delete tempNodePtr;
    }
}

void BinaryTree::insertNode(int aVal)
{
    Node* newNode = new Node(aVal);
    insert(root, newNode);
}

bool BinaryTree::searchNode(int aVal)
{
    Node* nodePtr = root;
    while(nodePtr != nullptr)
    {
        if(aVal < nodePtr->val)
        {
            nodePtr = nodePtr->left;
        }
        else if(aVal > nodePtr->val)
        {
            nodePtr = nodePtr->right;
        }
        else
        {
            return true;
        }
    }

    return false;
}

void BinaryTree::remove(int aVal)
{
    deleteNode(aVal, root);
}
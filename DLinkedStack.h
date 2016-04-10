#pragma once

#include "StackInterface.h"
#include "Node.h"
#include <vector>
#include <cassert>

using namespace std;

template<class ItemType>
class DLinkedStack : public StackInterface<ItemType> {
private:
    Node<ItemType> *headPtr;    // Pointer to first node in the chain;
    Node<ItemType> *topPtr;    // Pointer to (last) node in the chain that contains the stack's top
public:

    DLinkedStack();

    DLinkedStack(const DLinkedStack<ItemType> &aStack);    // Copy constructor

    virtual ~ DLinkedStack();    // Destructor

    Node<ItemType> *getPointerTo(const ItemType &target) const;

    bool isEmpty() const;

    bool push(const ItemType &newItem);

    bool pop();

    ItemType peek() const;

    vector<ItemType> toVector() const;

    Node<ItemType> *getHeadPTR() const;

    Node<ItemType> *getTopPTR() const;
};

template<class ItemType>
DLinkedStack<ItemType>::DLinkedStack() : headPtr(nullptr), topPtr(nullptr) {
}

template<class ItemType>
DLinkedStack<ItemType>::DLinkedStack(const DLinkedStack<ItemType> &aStack) {
    //TODO - Implement the copy constructor
    /*Node<ItemType> *originalStackNode = aStack.topPtr;

    if( originalStackNode == nullptr )
    {
        headPtr = nullptr;
        topPtr = nullptr;
    } else {

        //first Node copied from original
        headPtr = new Node<ItemType>();
        headPtr->setItem( originalStackNode->getItem() );
        topPtr = headPtr;
        originalStackNode = originalStackNode->getNext();

        while ( originalStackNode != nullptr )
        {
            ItemType nextItem = originalStackNode->getItem();
            Node<ItemType> *nextNode = new Node<ItemType>( nextItem );

            if( originalStackNode->getNext() == nullptr )
            {
                topPtr->setNext( nextNode );
                topPtr = topPtr->getNext();
                originalStackNode = originalStackNode->getNext();
            }

            topPtr->setNext( nullptr );
            headPtr->setPrev( nullptr );

        }

    }*/
}

template<class ItemType>
DLinkedStack<ItemType>::~DLinkedStack() {
    //TODO - Implement the destructor
    while( headPtr != nullptr )
    {
        Node<ItemType> *nodeToDelete = headPtr;
        headPtr = headPtr->getNext();
        nodeToDelete = nullptr;
    }

    headPtr = nullptr;

}

template<class ItemType>
Node<ItemType> *DLinkedStack<ItemType>::getPointerTo(const ItemType &target) const {
    //TODO - Return the Node pointer that contains the target(return nullptr if not found)

    bool isFound = false;
    Node<ItemType> *traverseNode = headPtr;

    while( !isFound && traverseNode != nullptr )
    {
        if( traverseNode->getItem() == target )
            isFound = true;
        else
            traverseNode = traverseNode->getNext();
    }

    return traverseNode;
}

template<class ItemType>
bool DLinkedStack<ItemType>::isEmpty() const {
    //TODO - Return True if the list is empty

    return headPtr == nullptr;
}

template<class ItemType>
bool DLinkedStack<ItemType>::push(const ItemType &newItem) {
    //TODO - Push an item on the Doubly Linked Stack

    if ( headPtr == nullptr )
    {
        headPtr = new Node<ItemType>( newItem );
        topPtr = headPtr;
        return true;
    } else {
        Node<ItemType> *nodeToAdd = new Node<ItemType>( newItem );
        topPtr->setNext( nodeToAdd );
        nodeToAdd->setPrev( topPtr );
        nodeToAdd->setNext( nullptr );
        topPtr = nodeToAdd;

        return true;
    }

}

template<class ItemType>
bool DLinkedStack<ItemType>::pop() {
    //TODO - Pop an item from the stack - Return true if successful

    bool canPop = false;
    if( !isEmpty() )
    {
        Node<ItemType> *nodeToDelete = topPtr;
        topPtr = topPtr->getPrev();
        delete nodeToDelete;
        canPop = true;
    }

    return canPop;
}

template<class ItemType>
ItemType DLinkedStack<ItemType>::peek() const {//Assume this never fails.
    //TODO - return the element stored at the top of the stack (topPtr)
    return topPtr->getItem();//garbage
}

template<class ItemType>
vector<ItemType> DLinkedStack<ItemType>::toVector() const {
    // DO NOT MODIFY THIS FUNCTION
    vector<ItemType> returnVector;
    // Put stack items into a vector in top to bottom order
    Node<ItemType> *curPtr = topPtr;
    while (curPtr != nullptr) {
        returnVector.push_back(curPtr->getItem());
        curPtr = curPtr->getPrev();
    }
    return returnVector;
}

template<class ItemType>
Node<ItemType> *DLinkedStack<ItemType>::getHeadPTR() const {
    // DO NOT MODIFY THIS FUNCTION
    return headPtr;
}

template<class ItemType>
Node<ItemType> *DLinkedStack<ItemType>::getTopPTR() const {
    // DO NOT MODIFY THIS FUNCTION
    return topPtr;
}
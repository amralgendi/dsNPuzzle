//
//  Queue.cpp
//  Project
//
//  Created by Mohamed Salah on 29/11/2022.
//

#include "Queue.hpp"
#include "Tree.hpp"

//--- Definition of Queue constructor

template <typename ElementType>
Queue<ElementType>:: Queue(): myFront(0), myBack(0) { }

//--- Definition of Queue copy constructor
template <typename ElementType>
Queue<ElementType>:: Queue(const Queue<ElementType> & original) {
    myFront = myBack = 0;
    if (original.empty()) {
        return;
    }
    
    // Copy first node
    myBack = myFront = new QueueNode<ElementType>(*original.myFront);
    
    // Set pointer to run through original's linked list
    QueueNodePointer origPtr = original.myFront->next;
    while (origPtr != 0) {
        myBack->next = new QueueNode<ElementType>(*origPtr);
        myBack = myBack->next;
        origPtr = origPtr->next;
    }
}

//--- Definition of Queue destructor
template <typename ElementType>
Queue<ElementType>::~Queue() {
    // Set pointer to run through the queue
    QueueNodePointer prev = myFront, ptr;
    while (prev != 0) {
        ptr = prev->next;
        (prev->data).~ElementType();
        delete prev;
        prev = ptr;
    }
}

//--- Definition of assignment operator
template <typename ElementType>
const Queue<ElementType> & Queue<ElementType>::operator=(const Queue<ElementType> & rightHandSide) {
    if (this == &rightHandSide) {
        return *this;
    }
    
    this->~Queue(); // destroy current linked list
    if (rightHandSide.empty()) { // empty queue
        myFront = myBack = 0;
        return *this;
    }
    
    // Copy first node
    myFront = myBack = new QueueNode<ElementType>(*rightHandSide.myFront);
    
    // Set pointer to run through rightHandSide's linked list
    QueueNodePointer rhsPtr = rightHandSide.myFront->next;
    while (rhsPtr != 0) {
        myBack->next = new QueueNode<ElementType>(*rhsPtr);
        myBack = myBack->next;
        rhsPtr = rhsPtr->next;
    }
    
    return *this;
}

//--- Definition of empty()
template <typename ElementType>
bool Queue<ElementType>::empty() const {
    return (myFront == 0);
}

//--- Definition of enqueue()
template <typename ElementType>
void Queue<ElementType>::enqueue(ElementType & value, int key) {
    QueueNodePointer newptr = new QueueNode<ElementType>(value, key);
    if (empty()) {
        myFront = myBack = newptr;
        return;
    }
    
    QueueNodePointer ptr = myFront;
    while (ptr != 0 && ptr->key >= key) {
        ptr = ptr->next;
    }
    myBack->next = newptr;
    myBack = newptr;
}

//--- Definition of display()
template <typename ElementType>
void Queue<ElementType>::display(ostream & out) const {
    QueueNodePointer ptr;
    for (ptr = myFront; ptr != 0; ptr = ptr->next)
        out << ptr->data << "  ";
    out << endl;
    
}

//--- Definition of output operator
template <typename ElementType>
ostream & operator<< (ostream & out, const Queue<ElementType> & aQueue) {
    aQueue.display(out);
    return out;
}

//--- Definition of front()
template <typename ElementType>
ElementType Queue<ElementType>::front() const {
    if (!empty()) {
        return (myFront->data);
    }
    
    cerr << "*** Queue is empty "
    " -- returning garbage ***\n";
    ElementType * temp = new(ElementType);
    ElementType garbage = *temp;     // "Garbage" value
    delete temp;
    return garbage;
}

//--- Definition of dequeue()
template <typename ElementType>
void Queue<ElementType>::dequeue() {
    if (empty()) {
        cerr << "*** Queue is empty -- can't remove a value ***\n";
        return;
    }
    
    Queue<ElementType>::QueueNodePointer ptr = myFront;
    myFront = myFront->next;
    delete ptr;
    if (myFront == 0)     // queue is now empty
        myBack = 0;
}


template class Queue<int>;
template class Queue<TreeNode>;

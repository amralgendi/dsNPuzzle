//
//  Tree.cpp
//  Project
//
//  Created by Mohamed Salah on 28/11/2022.
//

#include "Tree.hpp"

template class PriorityQueue<int>;
template class PriorityQueue<TreeNode>;

//--- Definition of Tree constructor
Tree::Tree(): rootNode(0) { }

//--- Definition of Tree copy constructor
Tree::Tree(const Tree & original) {
    rootNode = 0;
    if (original.empty()) {
        return;
    }
    // Copy first node
    rootNode = new TreeNode(*original.rootNode);
    
    queue = original.queue; // copy queue
}

//--- Definition of Queue destructor
Tree::~Tree() {
    // Not required because queue destructor is called automatically
    // queue.~PriorityQueue();
}

//--- Definition of assignment operator
const Tree & Tree::operator=(const Tree & rightHandSide) {
    if (this == &rightHandSide) {
        return *this;
    }
    
    this->~Tree();                  // destroy current Tree
    if (rightHandSide.empty()) {
        rootNode = 0;
        return *this;
    }
    
    // Copy root node
    rootNode = new TreeNode(*rightHandSide.rootNode);
    
    queue = rightHandSide.queue; // copy queues
    
    return *this;
}

//--- Definition of empty()
bool Tree::empty() const {
    return (rootNode == 0);
}

//--- Definition of adding to tree
void Tree::add(TreeNode & value) {
    queue.enqueue(value, value.cost + value.level);
}

//--- Definition of display()
void Tree::display(ostream & out) const {
    queue.display(out);
}

//--- Definition of output operator
ostream & operator<< (ostream & out, const Tree & aTree) {
    aTree.display(out);
    return out;
}

//--- Definition of getNodeWithLargestCost()
TreeNode Tree::getNodeWithLargestCost() const {
    if (!empty()) {
        return queue.front();
    }
    
    cerr << "*** Tree is empty "
    " -- returning garbage ***\n";
    TreeNode * temp = new(TreeNode);
    TreeNode garbage = *temp;     // "Garbage" value
    delete temp;
    return garbage;
}

//--- Definition of removeNodeWithLargestCost()
void Tree::removeNodeWithLargestCost() {
    if (empty()) {
        cerr << "*** Tree is empty -- can't remove a value ***\n";
        return;
    }
    
    queue.dequeue();
}


ostream & operator<< (ostream & out, const TreeNode & aTreeNode){
//    for (int i = 0; i < aTreeNode.N; i++) {
//        for (int j = 0; j < aTreeNode.N; j++)
//            out << aTreeNode.mat[i][j] << endl;
//    }
    out << aTreeNode.level << endl;
    return out;
}

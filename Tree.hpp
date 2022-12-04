//
//  Tree.hpp
//  Project
//
//  Created by Mohamed Salah on 28/11/2022.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <iostream>

#include "PriorityQueue.hpp"

using namespace std;

class TreeNode {
public:
    // MARK: - Data Members
    
    TreeNode * parent;
    
    /// stores matrix
    int ** mat; // dynamic 2d array
    int N;
    
    /// stores blank tile coordinates
    int x, y;
    
    /// stores the number of misplaced tiles
    int cost;
    
    /// stores the number of moves so far
    int level;
    
    // MARK: - Constructor
    
    TreeNode(TreeNode * _parent, int ** _value, int _N, int _x, int _y, int _cost, int _level): parent(_parent), mat(_value), N(_N), x(_x), y(_y), cost(_cost), level(_level) {
    }
    
    TreeNode(TreeNode & copy) {
        parent = copy.parent;
        mat = copy.mat;
        N = copy.N;
        x = copy.x;
        y = copy.y;
        cost = copy.cost;
        level = copy.level;
    }
    
    TreeNode() { }
};

typedef TreeNode * TreeNodePointer;

/// Tree class is a tree wrapped in priority queue where the first node is always the node with least cost
class Tree {
public:
    
    /***** Function Members *****/
    /***** Constructors *****/
    
    Tree();
    /*-----------------------------------------------------------------------
     Construct a Tree object.
     
     Precondition:  None.
     Postcondition: An empty Tree object has been constructed.
     (rootNode is initialized to null pointer).
     -----------------------------------------------------------------------*/
    
    Tree(const Tree & original);
    /*-----------------------------------------------------------------------
     Copy Constructor
     
     Precondition:  original is the tree to be copied and is received
     as a const reference parameter.
     Postcondition: A copy of original has been constructed.
     -----------------------------------------------------------------------*/
    
    /***** Destructor *****/
    ~Tree();
    /*-----------------------------------------------------------------------
     Class destructor
     
     Precondition:  None.
     Postcondition: The linked list in the tree's queue has been deallocated.
     -----------------------------------------------------------------------*/
    
    /***** Assignment *****/
    const Tree & operator= (const Tree & rightHandSide);
    /*-----------------------------------------------------------------------
     Assignment Operator
     
     Precondition:  rightHandSide is the tree to be assigned and is
     received as a const reference parameter.
     Postcondition: The current tree becomes a copy of rightHandSide
     and a reference to it is returned.
     -----------------------------------------------------------------------*/
    
    bool empty() const;
    /*-----------------------------------------------------------------------
     Check if queue is empty.
     
     Precondition:  None.
     Postcondition: Returns true if tree is empty and false otherwise.
     -----------------------------------------------------------------------*/
    
    void add(TreeNode & value);
    /*-----------------------------------------------------------------------
     Add a value to a tree.
     
     Precondition:  value is to be added to this tree. TreeNode should contain a reference to its parent node
     Postcondition: value is added accoding to its key(cost function).
     -----------------------------------------------------------------------*/
    
    void display(ostream & out) const;
    /*-----------------------------------------------------------------------
     Display values stored in the tree's queue.
     
     Precondition:  ostream out is open.
     Postcondition: Tree Queue's contents, from front to back, have been
     output to out.
     -----------------------------------------------------------------------*/
    
    TreeNode getNodeWithLargestCost() const;
    /*-----------------------------------------------------------------------
     Retrieve node at which its cost function is the greatest.
     
     Precondition:  Tree is nonempty.
     Postcondition: Node at which its cost function is the greatest is returned, unless the tree
     is empty; in that case, an error message is displayed and a
     "garbage value" is returned.
     -----------------------------------------------------------------------*/
    
    void removeNodeWithLargestCost();
    /*-----------------------------------------------------------------------
     Remove node at which its cost function is the greatest.
     
     Precondition:  Tree is nonempty.
     Postcondition: Node at which its cost function is the greatest has been removed, unless
     tree is empty; in that case, an error message is displayed
     and execution allowed to proceed.
     -----------------------------------------------------------------------*/
    
private:
    
    // MARK: - Data Members
    
    PriorityQueue<TreeNode> queue;
    TreeNodePointer rootNode;
    
}; // end of class declaration

ostream & operator<< (ostream & out, const TreeNode & aTreeNode);

#endif /* Tree_hpp */

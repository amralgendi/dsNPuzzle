//
//  PuzzleState.hpp
//  Project
//
//  Created by Mohamed Salah on 05/12/2022.
//

#ifndef PuzzleState_hpp
#define PuzzleState_hpp

#include <stdio.h>
#include <limits.h>
#include <iostream>

using namespace std;

// Class that stores data of an individual puzzle state
class PuzzleState {
public:
    /// dynamic 2d array of puzzle state
    int ** mat;
    
    int N;
    
    /// stores blank tile coordinates
    int x, y;
    
    /// stores the number of misplaced tiles
    int cost;
    
    /// stores the number of moves so far
    int level;
    
    // MARK: - Constructor
    
    PuzzleState(int ** _parentMat, int _N, int _x, int _y, int _newX, int _newY, int _level, int _cost = INT_MAX);
    
    PuzzleState(PuzzleState & copy);
    
    PuzzleState();
    
    void printMatrix() const;
};

ostream & operator<< (ostream & out, const PuzzleState & puzzleState);

#endif /* PuzzleState_hpp */

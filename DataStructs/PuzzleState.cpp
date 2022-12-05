//
//  PuzzleState.cpp
//  Project
//
//  Created by Mohamed Salah on 05/12/2022.
//

#include "PuzzleState.hpp"
#include "stdio.h"
#include <cstring>
#include <limits.h>
#include <iostream>

using namespace std;

// MARK: - Constructors

/// Constructor for initlizing the puzzle state
/// @param _parentMat parent matrix to generate from new state by swapping location of empty space
/// @param _N dynamic 2d array size
/// @param _x parent blank tile x coordinate
/// @param _y parent blank tile y coordinate
/// @param _newX  current state blank tile x coordinate
/// @param _newY current state blank tile y coordinate
/// @param _level current state level
/// @param _cost default val(INT_MAX) the number of moves so far in the tree of states
PuzzleState:: PuzzleState(int ** _parentMat,
                          int _N,
                          int _x, int _y,
                          int _newX, int _newY,
                          int _level, int _cost): x(_newX), y(_newY), N(_N), cost(_cost), level(_level) {
    
    mat = new int*[N];
    for (int i = 0; i < N; i++) {
        mat[i] = new int[N];
        for (int j = 0; j < N; j++)
            mat[i][j] = _parentMat[i][j];
    }
    
    swap(mat[_x][_y], mat[_newX][_newY]);
}

PuzzleState:: PuzzleState() { }

// MARK: - Main Methods

/// Print current state's matrix
void PuzzleState:: printMatrix() const {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

/// << operator overloading
ostream & operator<< (ostream & out, const PuzzleState & puzzleState) {
    puzzleState.printMatrix();
    return out;
}

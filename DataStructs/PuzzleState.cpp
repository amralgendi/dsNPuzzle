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

// MARK: - Constructor

PuzzleState:: PuzzleState(int ** _parentMat, int _N, int _x, int _y, int _newX, int _newY, int _level, int _cost): x(_newX), y(_newY), N(_N), cost(_cost), level(_level) {
    
    mat = new int*[N];
    for (int i = 0; i < N; i++) {
        mat[i] = new int[N];
        for (int j = 0; j < N; j++)
            mat[i][j] = _parentMat[i][j];
    }
    
    swap(mat[_x][_y], mat[_newX][_newY]);
}

PuzzleState:: PuzzleState(PuzzleState & copy) {
    mat = copy.mat;
    N = copy.N;
    x = copy.x;
    y = copy.y;
    cost = copy.cost;
    level = copy.level;
}

PuzzleState:: PuzzleState() { }


void PuzzleState:: printMatrix() const {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

ostream & operator<< (ostream & out, const PuzzleState & puzzleState) {
    puzzleState.printMatrix();
    return out;
}

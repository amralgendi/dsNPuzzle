//
//  main.cpp
//  Project
//
//  Created by Mohamed Salah on 28/11/2022.
//

#include "PuzzleSolver.hpp"
#include "stdio.h"
#include <cstring>
#include <limits.h>
#include <iostream>

using namespace std;

template <const size_t N, size_t N2>
int ** getTestCase(int (&array)[N][N2]) {
    int **dynamicState = new int*[N];
    for(int i = 0; i < N; ++i) {
        dynamicState[i] = new int[N];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            dynamicState[i][j] = array[i][j];
        printf("\n");
    }
    
    return dynamicState;
}

/// Testing Unit for 3x3 Puzzle Solver
void test3N() {
    const int N = 3;
    
    int initialMat[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {0, 7, 8}
    };
    
    int finalMat[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    
    
    int ** dynamicFirstState = getTestCase(initialMat);
    int ** dynamicFinalState = getTestCase(finalMat);
    
    PuzzleState * initialState = new PuzzleState(dynamicFirstState, N, 2, 0, 2, 0, 0);
    PuzzleState * finalState = new PuzzleState(dynamicFinalState, N, 2, 2, 2, 2, -1);
    
    solve(*initialState, *finalState);
}


/// Testing Unit for 4x4 Puzzle Solver
void test4N() {
    const int N = 4;
    
    int initialMat[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {0, 13, 14, 15}
    };
    
    int finalMat[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0}
    };
    
    
    int ** dynamicFirstState = getTestCase(initialMat);
    int ** dynamicFinalState = getTestCase(finalMat);
    
    PuzzleState * initialState = new PuzzleState(dynamicFirstState, N, 3, 0, 2, 0, 0);
    PuzzleState * finalState = new PuzzleState(dynamicFinalState, N, 3, 3, 3, 3, -1);
    
    solve(*initialState, *finalState);
}

int main() {
    
    test3N();
    
    return 0;
}


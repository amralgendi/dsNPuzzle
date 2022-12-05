//
//  PuzzleSolver.hpp
//  Project
//
//  Created by Mohamed Salah on 05/12/2022.
//

#ifndef PuzzleSolver_hpp
#define PuzzleSolver_hpp

#include <stdio.h>
#include "PuzzleState.hpp"

/// Function to calculate the number of misplaced tiles. This returns the number of non-blank tiles not in their goal final position.
/// @param state the state to calculate for the cost
/// @param finalState the final ending state
int calculateCost(PuzzleState & state, PuzzleState & finalState);

/// Function to check if (x, y) is a valid matrix coordinate. Used to check if the random generated move is in bounds.
/// @param x newX value
/// @param y newY Value
/// @param N  Dynamic array size
int isSafe(int x, int y, int N);

/// The main solving function.
/// @param initialState  the state of the puzlle in which the algorithm starts from.
/// @param finalState the state of the puzzle in which the user must match to win the game.
void solve(PuzzleState & initialState, PuzzleState & finalState);


// MARK: - IsSolvable Utils

/// <#Description#>
/// @param arr <#arr description#>
/// @param N <#N description#>
int getInvCount(int arr[], int N);

// find Position of blank from bottom

/// <#Description#>
/// @param puzzle <#puzzle description#>
/// @param N <#N description#>
int findXPosition(int ** puzzle, int N);

// This function returns true if given
// instance of N*N - 1 puzzle is solvable

/// <#Description#>
/// @param puzzle <#puzzle description#>
/// @param N <#N description#>
bool isSolvable(int ** puzzle, int N);

#endif /* PuzzleSolver_hpp */

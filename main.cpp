//
//  main.cpp
//  Project
//
//  Created by Mohamed Salah on 28/11/2022.
//

#include "PriorityQueue.hpp"
#include "stdio.h"
#include <cstring>
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
    
    PuzzleState(int ** _parentMat, int _N, int _x, int _y, int _newX, int _newY, int _level, int _cost = INT_MAX): N(_N), x(_newX), y(_newY), cost(_cost), level(_level) {
        
        memcpy(mat, _parentMat, sizeof mat);
        swap(mat[_x][_y], mat[_newX][_newY]);
    }
    
    PuzzleState(PuzzleState & copy) {
        mat = copy.mat;
        N = copy.N;
        x = copy.x;
        y = copy.y;
        cost = copy.cost;
        level = copy.level;
    }
    
    PuzzleState() { }
    
};

// 1 2 3
// 4 5 6
// 7 8 _


/// Function to calculate the number of misplaced tiles. This returns the number of non-blank tiles not in their goal final position
/// @param state the state to calculate for the cost
/// @param finalState the final ending state
int calculateCost(PuzzleState & state, PuzzleState & finalState) {
    int count = 0;
    for (int i = 0; i < state.N; i++)
        for (int j = 0; j < state.N; j++)
            if (state.mat[i][j] && state.mat[i][j] != finalState.mat[i][j])
                count++;
    return count;
}

// Function to check if (x, y) is a valid matrix coordinate

int isSafe(int x, int y, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// MARK: - Solving Algorithm

// cost = cost + level

// bottom, left, top, right
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

// Function to solve N*N - 1 puzzle algorithm using
// Branch and Bound. x and y are blank tile coordinates
// in initial state
void solve(PuzzleState & initialState,
           PuzzleState & finalState) {
    // Create a priority queue to store live nodes of
    // search tree;
    PriorityQueue<PuzzleState> pq;
    
    // create a root node and calculate its cost
//    PuzzleState* root = newNode(initial, x, y, x, y, 0, NULL);
    initialState.cost = calculateCost(initialState, finalState);
    
    // Add root to list of live nodes;
    pq.enqueue(initialState, initialState.cost + initialState.level);
    
    // Finds a live node with least cost,
    // add its childrens to list of live nodes and
    // finally deletes it from the list.
    
    while (!pq.empty()) {
        // Find a live node with least estimated cost
        PuzzleState min = pq.front();
        
        // The found node is deleted from the list of
        // live nodes
        
        pq.dequeue();
        
        // if min is an answer node
        if (min.cost == 0) {
            return;
        }
        
        // do for each child of min
        // max 4 children for a node
        for (int i = 0; i < 4; i++) {
            if (isSafe(min.x + row[i], min.y + col[i], min.N)) {
                // create a child node and calculate
                // its cost
                int newX = min.x + row[i];
                int newY = min.y + col[i];
                PuzzleState* child = new PuzzleState(min.mat, min.N, min.x, min.y, newX, newY, min.level + 1);
                child->cost = calculateCost(*child, finalState);
                
                // Add child to list of live nodes
                pq.enqueue(*child, child->cost + child->level);
            }
        }
    }
}

// MARK: - IsSolvable Utils

int getInvCount(int arr[], int N) {
    int inv_count = 0;
    for (int i = 0; i < N * N - 1; i++) {
        for (int j = i + 1; j < N * N; j++) {
            // count pairs(arr[i], arr[j]) such that
            // i < j but arr[i] > arr[j]
            if (arr[j] && arr[i] && arr[i] > arr[j])
                inv_count++;
        }
    }
    return inv_count;
}

// find Position of blank from bottom
int findXPosition(int ** puzzle, int N) {
    // start from bottom-right corner of matrix
    for (int i = N - 1; i >= 0; i--)
        for (int j = N - 1; j >= 0; j--)
            if (puzzle[i][j] == 0)
                return N - i;
    return -1;
}

// This function returns true if given
// instance of N*N - 1 puzzle is solvable
bool isSolvable(int ** puzzle, int N) {
    // Count inversions in given puzzle
    int invCount = getInvCount((int*)puzzle, N);
    
    // If grid is odd, return true if inversion
    // count is even.
    if (N & 1)
        return !(invCount & 1);
    else {     // grid is even
        int pos = findXPosition(puzzle, N);
        if (pos & 1)
            return !(invCount & 1);
        else
            return invCount & 1;
    }
}

int ** getTestCase(int N, int test[N][N]) {
    int **dynamicState = new int*[N];
    for(int i = 0; i < N; ++i) {
        dynamicState[i] = new int[N];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            dynamicState[i][j];
        printf("\n");
    }
    
    return dynamicState;
}

// Driver code
int main() {
    // Initial configuration
    // Value 0 is used for empty space
    
    const int N = 3;
    
    int initialMat[N][N] = {
        {3, 5, 2},
        {7, 4, 6},
        {0, 1, 5}
    };
    
    // Solvable Final configuration
    // Value 0 is used for empty space
    int finalMat[N][N] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    
    PuzzleState initialState =
    
//    solve(<#PuzzleState &initialState#>, <#PuzzleState &finalState#>)
    return 0;
}


#include <queue>
#include "stdio.h"
#include <cstring>
#include <limits.h>
#include <iostream>

using namespace std;
#define N 3
 
// state space tree nodes
struct Node
{
    // stores the parent node of the current node
    // helps in tracing path when the answer is found
    Node* parent;
 
    // stores matrix
    int mat[N][N];
 
    // stores blank tile coordinates
    int x, y;
 
    // stores the number of misplaced tiles
    int cost;
 
    // stores the number of moves so far
    int level;
};
// Function to print N x N matrix
int printMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    return 0;
}
 
// Function to allocate a new node
Node* newNode(int mat[N][N], int x, int y, int newX,
              int newY, int level, Node* parent)
{
    Node* node = new Node;
 
    // set pointer for path to root
    node->parent = parent;
 
    // copy data from parent node to current node
    memcpy(node->mat, mat, sizeof node->mat);
 
    // move tile by 1 position
    swap(node->mat[x][y], node->mat[newX][newY]);
 
    // set number of misplaced tiles
    node->cost = INT_MAX;
 
    // set number of moves so far
    node->level = level;
 
    // update new blank tile coordinates
    node->x = newX;
    node->y = newY;
 
    return node;
}
 
// bottom, left, top, right
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };
 
// Function to calculate the number of misplaced tiles
// ie. number of non-blank tiles not in their goal position
int calculateCost(int initial[N][N], int final[N][N])
{
    int count = 0;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        if (initial[i][j] && initial[i][j] != final[i][j])
           count++;
    return count;
}
 
// Function to check if (x, y) is a valid matrix coordinate
int isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}
 
// print path from root node to destination node
void printPath(Node* root)
{
    if (root == NULL)
        return;
    printPath(root->parent);
    printMatrix(root->mat);
 
    printf("\n");
}
 
// Comparison object to be used to order the heap
struct comp
{
    bool operator()(const Node* lhs, const Node* rhs) const
    {
        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
    }
};
 
// Function to solve N*N - 1 puzzle algorithm using
// Branch and Bound. x and y are blank tile coordinates
// in initial state
void solve(int initial[N][N], int x, int y,
           int final[N][N])
{
    // Create a priority queue to store live nodes of
    // search tree;
    priority_queue<Node*, std::vector<Node*>, comp> pq;
 
    // create a root node and calculate its cost
    Node* root = newNode(initial, x, y, x, y, 0, NULL);
    root->cost = calculateCost(initial, final);
 
    // Add root to list of live nodes;
    pq.push(root);
 
    int i = 0;
    // Finds a live node with least cost,
    // add its childrens to list of live nodes and
    // finally deletes it from the list.
    while (/*i++ < 100 && */!pq.empty())
    {
        // Find a live node with least estimated cost
        Node* min = pq.top();
 
        // The found node is deleted from the list of
        // live nodes

        cout << "cost: "<< min->cost << "level: " << min -> level << endl;
        printMatrix(min -> mat);
        cout << '\n';
        pq.pop();

        // if min is an answer node
        if (min->cost == 0)
        {
            // print the path from root to destination;
            // printPath(min);


            return;
        }
 
        // do for each child of min
        // max 4 children for a node
        for (int i = 0; i < 4; i++)
        {
            if (isSafe(min->x + row[i], min->y + col[i]))
            {
                // create a child node and calculate
                // its cost
                Node* child = newNode(min->mat, min->x,
                              min->y, min->x + row[i],
                              min->y + col[i],
                              min->level + 1, min);
                child->cost = calculateCost(child->mat, final);
 
                // Add child to list of live nodes
                pq.push(child);
            }
        }
    }
}

int getInvCount(int arr[])
{
    int inv_count = 0;
    for (int i = 0; i < N * N - 1; i++)
    {
        for (int j = i + 1; j < N * N; j++)
        {
            // count pairs(arr[i], arr[j]) such that
              // i < j but arr[i] > arr[j]
            if (arr[j] && arr[i] && arr[i] > arr[j])
                inv_count++;
        }
    }
    return inv_count;
}
 
// find Position of blank from bottom
int findXPosition(int puzzle[N][N])
{
    // start from bottom-right corner of matrix
    for (int i = N - 1; i >= 0; i--)
        for (int j = N - 1; j >= 0; j--)
            if (puzzle[i][j] == 0)
                return N - i;     
    return 0; 
}
 
// This function returns true if given
// instance of N*N - 1 puzzle is solvable
bool isSolvable(int puzzle[N][N])
{
    // Count inversions in given puzzle
    int invCount = getInvCount((int*)puzzle);
 
    // If grid is odd, return true if inversion
    // count is even.
    if (N & 1)
        return !(invCount & 1);
 
    else     // grid is even
    {
        int pos = findXPosition(puzzle);
        if (pos & 1)
            return !(invCount & 1);
        else
            return invCount & 1;
    }
}
 
// Driver code
int main()
{
        // Initial configuration
        // Value 0 is used for empty space
        int initialMat[N][N] =
        {
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
      
        // Blank tile coordinates in initial
        // configuration
        int x = 2, y = 0;
        if(!isSolvable(initialMat)) {
            cout << "WROOOOOONGG" << endl;
            return 0;
        } 
        solve(initialMat, x, y, finalMat);
    return 0;
}
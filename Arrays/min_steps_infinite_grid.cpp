// Min Steps in Infinite Grid

// You are in an infinite 2D grid where you can move in any of the 8 directions
// You are given a sequence of points and the order in which you need to cover the points.. 
// Give the minimum number of steps in which you can achieve it. You start from the first point.

// Input Format
// Given two integer arrays A and B, where A[i] is x coordinate and B[i] is y coordinate of ith point respectively.

// Output Format
// Return an Integer, i.e minimum number of steps.

// Example Input
// Input 1:

//  A = [0, 1, 1]
//  B = [0, 1, 2]

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int len = A.size();
    int sum = 0;
    
    for(int i = 1; i<len; i++ )
    {
        sum = sum + min(abs(A[i]-A[i-1]),abs(B[i]-B[i-1])) + abs(abs(A[i]-A[i-1]) - abs(B[i]-B[i-1]));
    }
    
    return sum;
}

// Solution 
// Between two points, the minimum steps is the isoceles diagonal + remaining straight distance
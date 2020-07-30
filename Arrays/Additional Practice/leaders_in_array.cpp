// Leaders in an array

// Given an integer array A containing N distinct integers, you have to find all the leaders in the array A.
// An element is leader if it is strictly greater than all the elements to its right side.
// NOTE:The rightmost element is always a leader.
// Return an integer array denoting all the leader elements of the array.
// NOTE: Ordering in the output doesn't matter.

// Input A = [16, 17, 4, 3, 5, 2]
// Output = [17, 2, 5]

vector<int> Solution::solve(vector<int> &A) {
    int len = A.size();
    vector<int> result;
    int i = len-2;
    int curr_max = A[len-1];
    result.push_back(A[len-1]);
    
    while(i>=0)
    {
        if(A[i] > curr_max)
        {
            result.push_back(A[i]);
            curr_max = A[i];
        }
        
        i--;
    }
    
    return result;
}

// Solution
// Reverse Traversal and keep track of maximum element encountered till now.
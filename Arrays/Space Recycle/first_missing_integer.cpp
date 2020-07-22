// First Missing Integer

// Given an unsorted integer array, find the first missing positive integer.

// Example:
// Given [1,2,0] return 3,
// [3,4,-1,1] return 2,
// [-8, -7, -6] returns 1

// Your algorithm should run in O(n) time and use constant space.

int Solution::firstMissingPositive(vector<int> &A) {
    int len = A.size();
    // largest possible answer is len+1 (all numbers from 1 to n)
    // Therefore answer is from 1 to len+1
    int j = 0;
    for(int i = 0; i<len;i++)
    {
        if(A[i] <= 0)
        {
            swap(A[i],A[j]);
            j++; // count of non positive integers
        }
    }
    
    for(int i = 0; i<j;i++)
        A[i] = 1;
        
    for(int i = j; i<len;i++)
    {
        int val = abs(A[i]);
        if(val <= len)
            A[val-1] = min(A[val-1],0-A[val-1]);
    }
    
    for(int i = 0; i<len;i++)
    {
        if(A[i] > 0)
            return i+1;
    }
    
    return len+1;
}

// Solution
// largest possible answer is len+1 (all numbers from 1 to n) Therefore answer is from 1 to len+1
// N - size of array 
// Bring all negative numbers to the left of the array. Set them all to 1 (They dont matter)
// Now use index of array(o to n-1) to check if numbers from 1 to n have occured. 

// Main Trick - Array itself used to track.
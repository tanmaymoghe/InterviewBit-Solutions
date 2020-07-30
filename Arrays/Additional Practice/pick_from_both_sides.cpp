// Pick from both sides!

// Given an integer array A of size N.
// You can pick B elements from either left or right end of the array A to get maximum sum.
// Find and return this maximum possible sum.
// NOTE: Suppose B = 4 and array A contains 10 elements then:
// You can pick first four elements or can pick last four elements or can pick 1 from front and 3 from back etc. 
// You need to return the maximum possible sum of elements you can pick.

// A = [5, -2, 3 , 1, 2]
// B = 3
// Output - 8

int Solution::solve(vector<int> &A, int B) {
    int len = A.size();
    int suffixsum[len];
    suffixsum[len-1] = 0;
    int sum = A[len-1];
    int i = len-2;
    while(i>=0)
    {
        suffixsum[i] = sum;
        sum = sum + A[i];
        i--;
    }
    
    if(len==B) return sum;
    
    int maxsum = INT_MIN;
    i = 0;
    int sum_till_here = 0;
    int tempsum;
    
    while(i<=B)
    {
        tempsum = sum_till_here + suffixsum[len - B - 1 + i];
        maxsum = max(tempsum,maxsum);
        sum_till_here = sum_till_here + A[i];
        i++;
    }
    
    return maxsum;
}

// Solution 
// One can choose B-i elements from one side and i elements from other side. 
// i ranges from 0 to B. 
// For the left side sum, keep a sum variable and as you traverse, keep incrementing it. 
// For the right sum, use a preprocessed suffixsum array.
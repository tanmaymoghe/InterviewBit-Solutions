// Noble Integer

// Given an integer array A, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p.
// Return 1 if any such integer p is found else return -1.

int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    int len = A.size();
    
    for(int i=0; i<len;i++)
    {
        if(i!=len-1)
        {
            if(A[i] == A[i+1])
                continue;
        }
        
        if(A[i] == len - i - 1)
            return 1;
    }
    
    return -1;
}

// Solution
// Sort the array and then go on checking
// Edge case - equal elements in the array.
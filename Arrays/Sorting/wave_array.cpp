// Wave Array

// Given an array of integers, sort the array into a wave like array and return it,
// In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(),A.end());
    
    int len = A.size();
    for(int i = 0; i<len-1;i=i+2)
        swap(A[i],A[i+1]);
    
    return A;
}

// Solution 
// Sort and then swap pairs
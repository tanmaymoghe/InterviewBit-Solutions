// Max Min

// Given an array A of size N. You need to find the sum of Maximum and Minimum element in the given array.
// NOTE: You should make minimum number of comparisons.

// input -  A = [-2, 1, -4, 5, 3]
// output - 1
// Maximum Element is 5 and Minimum element is -4. (5 + (-4)) = 1. 

// Solution 1
// Find max and min element linearly
// Total number of comparisons = 2n 
// Time Complexity - O(n)
// Space Complexity - O(n)

int Solution::solve(vector<int> &A) {
    int len = A.size();
    int maxarr = A[0];
    int minarr = A[0];
    
    for(int i = 1; i<len;i++)
    {
        maxarr = max(maxarr,A[i]);
        minarr = min(minarr,A[i]);
    }
    
    return maxarr+minarr;
}

// Solution 2
// Recursion
// If array length 1, max and min same element
// If array length 2, one comparison for max and min. 
// If array length more than 2, divide into two equal parts and we get two pairs of max and min. 
// Now two comparisons required for finding the absolute max and min. 
// Therefore, T(n) = 2T(n/2) + 2
// Solve using master recursion theorem. (less than 2n)

pair<int,int> maxmin(vector<int> &A,int start, int end);

int Solution::solve(vector<int> &A) {
    pair<int,int> p = maxmin(A,0,(int)(A.size()-1));
    return p.first+p.second;
}

pair<int,int> maxmin(vector<int> &A,int start, int end)
{
    int len = end - start + 1;
    if(len==1)
        return make_pair(A[start],A[start]);    
    
    if(len==2)
    {
        if(A[start]>=A[end])
            return make_pair(A[start],A[end]);
            
        else
            return make_pair(A[end],A[start]);
    }
    
    int mid = (end+start)/2;
    pair<int,int> p1 = maxmin(A,start,mid);
    pair<int,int> p2 = maxmin(A,mid+1,end);
    return make_pair(max(p1.first,p2.first),min(p1.second,p2.second));
}
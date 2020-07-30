// Perfect Peak of Array

// Given an integer array A of size N.
// You need to check that whether there exist a element which is strictly greater than all the elements on left of it and strictly smaller than all the elements on right of it.
// If it exists return 1 else return 0.
// NOTE: Do not consider the corner elements i.e A[0] and A[N-1] as the answer.
// Return 1 if there exist a element that is strictly greater than all the elements on left of it and strictly smaller than all the elements on right of it else return 0.

// Input -  A = [5, 1, 4, 3, 6, 8, 10, 7, 9]
// Output -  1
// A[4] = 6 is the element we are looking for.
// All elements on left of A[4] are smaller than it and all elements on right are greater.

int Solution::perfectPeak(vector<int> &A) {
    int len = A.size();
    int min_suffix[len];
    int max_prefix[len];
    
    int tempmax = A[0];
    for(int i = 1; i<len;i++)
    {
        max_prefix[i] = tempmax;
        tempmax = max(A[i],tempmax);
    }
    
    int tempmin = A[len-1];
    for(int i = len-2; i>=0; i--)
    {
        min_suffix[i] = tempmin;
        tempmin = min(A[i],tempmin);
    }
    
    for(int i = 1; i<len-1;i++)
    {
        if(A[i] > max_prefix[i] && A[i] < min_suffix[i])
            return 1;
    }
    
    return 0;
}

// Solution 
// Use two preprocessing arrays - min_suffix and max_prefix
// min_suffix -> minimum element in the suffix 
// max_prefix -> maximum element in the prefix 
// A single traversal is needed (forward for max_prefix and reverse from min_suffix) to fill these arrays. Keep track of the tempmin and tempmax at each step.
// For each element from index 1 to index len-2, check if that element is greater than max_prefix[i] and less than min_suffix[i].
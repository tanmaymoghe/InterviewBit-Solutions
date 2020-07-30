// Maximum Sum Triplet

// Given an array A containing N integers.
// You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.
// If no such triplet exist return 0.

// Input - A = [2, 5, 3, 1, 4, 9]
// Output - 16
// All possible triplets are:-
// 2 3 4 => sum = 9
// 2 5 9 => sum = 16
// 2 3 9 => sum = 14
// 3 4 9 => sum = 16
// 1 4 9 => sum = 14
// Maximum sum = 16

int Solution::solve(vector<int> &A) {
    int len = A.size();
    if(len<3) return 0;
    
    int max_suffix_arr[len-1]; // preprocessed array to check maximum element in the suffix
    int max_ele = A[len-1]; // maximum element encountered till now
    int i = len-2;
    while(i>=0)
    {
        max_suffix_arr[i] = max_ele;
        max_ele = max(A[i],max_ele);
        i--;
    }
    
    set<int> sorted; // a set of sorted elements encountered till now
    sorted.insert(A[0]); 
    int max_sum = INT_MIN;
    
    for(int i = 1; i<len-1;i++) // check considering each of these is the middle element
    {
        int middle = A[i];
        int lower, upper;
        auto it = sorted.lower_bound(middle);
        if(*it>=middle || it==sorted.end()) // this if statement is not needed, just put for understanding. It includes all possible cases
                                            // it==sorted.end() => middle is greater than all the elements in the sorted array
                                            // *it==middle => middle is present in set, the previous value is the one which is the greatest value less than middle
                                            // *it>middle => middle is not present in set, pointer to value just greater than middle is returned. The required value is the previous value
        {
            if(it==sorted.begin()) // middle is the smallest value in the set or even less than the smallest value. Hence, no triplet can be formed.
            {
                sorted.insert(middle);
                continue;
            }
            it--;
            lower = *it; // lower value assigned
        }
        
        upper = max_suffix_arr[i];
        
        if(upper <= middle)
            continue;
        max_sum = max(max_sum,upper+lower+middle);
        sorted.insert(middle);
    }
    
    return max_sum;
}

// Solution
// From each element from index 1 to index len-2, check assuming each element is the middle element. 
// For the lower element, maintain a list of sorted elements (a set) encountered till now and use binary search (lower_bound) to find just smaller element.
// For the upper element, use a preprocessed maximum element in suffix array. 
// Time complexity - O(nlogn) 
// Space complexity - O(n)
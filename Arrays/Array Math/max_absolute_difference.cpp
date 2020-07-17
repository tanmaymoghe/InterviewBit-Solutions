// Maximum Absolute Difference

// You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
// f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

int Solution::maxArr(vector<int> &arr) {
    int max1 = INT_MIN;
    int min1 = INT_MAX;
    
    int max2 = INT_MIN;
    int min2 = INT_MAX;
    
    for(int i = 0; i<arr.size();i++)
    {
        max1 = max(max1,arr[i] + i);
        min1 = min(min1,arr[i] + i);
        
        max2 = max(max2,arr[i] - i);
        min2 = min(min2,arr[i] - i);
    }
    
    return max(max1-min1,max2-min2);
}

// Solution 
// Remove the modulus sign, equation can be written in 4 ways (+- for first and +- for second)
// 1. (A[i] + i) - (A[j] + j)
// 2. (-A[i] - i) + (A[j] + j) = -(A[i] + i) + (A[j] + j)
// 3. -(A[i] - i) + (A[j] - j) 
// 4. (A[i] - i) - (A[j] - j) 
// 1 and 4 are equivalent, 2 and 3 are equivalent.
// A[i] + i, A[i] - i => max and min value of these across the array (store)
// return greater diff between max and min (two above cases)
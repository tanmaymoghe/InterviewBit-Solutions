// Max Sum Contiguous Subarray

// Find the contiguous subarray within an array, A of length N which has the largest sum.

// Input Format:
// The first and the only argument contains an integer array, A.

// Output Format:
// Return an integer representing the maximum possible sum of the contiguous subarray.

int Solution::maxSubArray(const vector<int> &A) {
    int len = A.size();
    if(len<=0)
        return 0;
    
    int maxsum = A[0];
    int tempsum = A[0];
    
    for(int i = 1; i<len;i++)
    {
        if(tempsum < 0)  // previous number is negative
            tempsum = A[i];
        else
        {
            if(tempsum + A[i] >= 0) //  previous number positive, after adding to current pos number sum also positive
                tempsum = tempsum + A[i];
            else
                tempsum = A[i]; // sum negative, hence starting a new subarray
        }
            
        maxsum = max(maxsum,tempsum); // comparison at each stage of subarray
    }
    
    return maxsum;
}


// Solution
// if A[i] to A[j] is the max_sum_contiguous_subarr, any prefix of this subarray will not have a negative sum 
// (Proof by contradiction)
// Hence, for optimal solution, include prefix with positive sum. 
// Traverse the array, if sum becomes negative, start a new subarray 
// One edge case is when all numbers are negative.
// Maximum Consecutive Gap

// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
// Try to solve it in linear time/space.

// Return 0 if the array contains less than 2 elements.

// You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
// You may also assume that the difference will not overflow.

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
        
        if(n<2)
            return 0;
        
        int minVal = A[0];
        int maxVal = A[0];
        
        for(int i = 1; i<n; i++)
        {
            maxVal = max(maxVal,A[i]);
            minVal = min(minVal,A[i]);
        }
        
        float bucketSize = (float)(maxVal - minVal) / (float)(n-1);
        
        int maxBucket[n-1];
        int minBucket[n-1];
        fill_n(maxBucket,n-1,INT_MIN);
        fill_n(minBucket,n-1,INT_MAX);
        
        for(int i = 0; i<n;i++)
        {
            if(A[i] == maxVal || A[i] == minVal)
                continue;
            
            int index = (float)(A[i] - minVal) / bucketSize;
            
            maxBucket[index] = max(maxBucket[index],A[i]);
            minBucket[index] = min(minBucket[index],A[i]);            
        }
        
        
        int maxGap = 0;
        int prevVal = minVal;
        
        for(int i = 0; i<n-1;i++)
        {
            if(minBucket[i] == INT_MAX)
                continue;
            
            maxGap = max(maxGap,minBucket[i] - prevVal);
            prevVal = maxBucket[i];
        }
        
        maxGap = max(maxGap,maxVal - prevVal);
        
        return maxGap;
}

// Solution 
// A bucketing approach is used. 
// First overall minimum and maximum is calculated.
//     The Pigeonhole Principle states that if nn items are put into mm containers, with n > mn>m, 
//     then at least one container must contain more than one item. 
// If array is sorted and uniform gaps are there, width t = (max-min)/(n-1). 
// Divide into n-1 buckets , for each bucket store minimum and maximum value of elements in required range.
// In a bucket, the difference betwwen two sorted elements will always be less than the minimum max difference.
// Hence we only have to check the diffrences between max of current bucket and min of next bucket. 
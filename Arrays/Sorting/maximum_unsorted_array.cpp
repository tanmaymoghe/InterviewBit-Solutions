// Maximum Unsorted Subarray

// You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
// Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
// If A is already sorted, output -1.

vector<int> Solution::subUnsort(vector<int> &A) {
    int start = -1;
    int end = -1;
    
    int len = A.size();
    int i = 0;
    vector<int> result;
    
    while(i<len-1)
    {
        if(A[i] > A[i+1])
        {
            start = i;
            break;
        }
        
        i++;
    }
    
    if(i==len-1)
    {
        result.push_back(-1);
        return result;
    }
    
    i=len-1;
    
    while(i>0)
    {
        if(A[i-1] > A[i])
        {
            end = i;
            break;
        }
        
        i--;
    }
    
    int tempMax = A[start];
    for(i = start+1; i<=end;i++)
        tempMax = max(tempMax,A[i]);
    
    int tempMin = A[start];
    for(i = start+1; i<=end;i++)
        tempMin = min(tempMin,A[i]);
        
    for(i=0; i<start;i++)
    {
        if(A[i] > tempMin)
        {
            start = i;
            break;
        }
    }
    
    for(i=len-1; i>end;i--)
    {
        if(A[i] < tempMax)
        {
            end = i;
            break;
        }
    }
    
    result.push_back(start);
    result.push_back(end);
    return result;
}

// Solution
// 1. Check from both sides for increasing and descreasing elements. Check the violation. 
// 2. A subarray will be found besides which both arrays are sorted. 
// 3. However after sorting this subarray, the work is not done. 
// 4. To the left, first element greater than subarray minimum (if it exists) and to the right first element smaller than subarray maximum (if it exists) has to be found.
// 5. Now return required subarray. 
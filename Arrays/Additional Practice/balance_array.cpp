// Balance Array

// Given an integer array A of size N. You need to count the number of special elements in the given array.
// A element is special if removal of that element make the array balanced.
// Array will be balanced if sum of even index element equal to sum of odd index element.
// Return an integer denoting the count of special elements.

// Input - A = [5, 5, 2, 5, 8]
// Output - 2
// If we delete A[0] or A[1] , array will be balanced
// (5+5) = (2+8)
// So A[0] and A[1] are special elements, so count is 2.

int Solution::solve(vector<int> &A) {
    int len = A.size();
    if(len==0 || len==1)
        return len;
    
    int sum1 = 0; // sum of odd index terms
    int sum2 = 0; // sum of even index terms
    for(int i = 0; i<len;i++)
    {
        if(i%2==0)
            sum2 = sum2 + A[i];
        else
            sum1 = sum1 + A[i];
    }
    
    int count = 0;
    
    int prevsum2 = 0; // sum of even index terms till the element encounterd
    int prevsum1 = 0; // sum of odd index terms till the element encounterd
    
    for(int i = 0; i<len;i++) //When one element is removed, the odd index terms after it become even index terms and vice versa.
    {
        if(i%2==0) // current index even
        {
            if(prevsum2 + sum1 == prevsum1 + sum2 - A[i])
                count++;
                
            prevsum2 = prevsum2 + A[i];
            sum2 = sum2 - A[i];
            nextsum1 = false;
        }
        else // current index odd
        {
            if(prevsum2 + sum1 - A[i] == prevsum1 + sum2)
                count++;
                
            prevsum1 = prevsum1 + A[i];
            sum1 = sum1 - A[i];
            nextsum1 = true;
        }
    }
    
    return count;
}

// Solution 
// HINT - When one element is removed, the odd index terms after it become even index terms and vice versa.
// Preprocess two sums - one of even indices and one of odd. 
// Now as we traverse through the array, keep on subtracting the elements from these sums and adding to prevsum variables (these variables keep track of the dual sums of the previous elements). 
// Also check for special elements while traversing.
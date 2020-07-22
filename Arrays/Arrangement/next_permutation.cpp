// Next Permutation

// Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.
// If such arrangement is not possible, it must be rearranged as the lowest possible order i.e., sorted in an ascending order.

// 1. The replacement must be in-place, do **not** allocate extra memory.
// 2. DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use of Library functions will disqualify your submission retroactively and will give you penalty points.

// Input Format - The first and the only argument of input has an array of integers, A.
// Output Format - Return an array of integers, representing the next permutation of the given array.

vector<int> Solution::nextPermutation(vector<int> &A) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int len = A.size();
    
    int size = 0;
    int i = len-1;
    
    for(i; i>=1; i--)
    {
        pq.push(A[i]);
        //cout << i << endl;
        
        //cout << A[i-1] << "  " << A[i] <<endl;
        if(A[i-1] < A[i])
            break;
        
    }
    
    if(i==0)
    {
        reverse(A.begin(),A.end());
        return A;
    }
    
    int comp = A[i-1];
    //cout << comp << endl;
    int j = i;
    for(i; i<len;i++)
    {
        int temp = pq.top();
        pq.pop();
        
        if(temp>comp)
        {
            A[j-1] = temp;
            A[i] = comp;
            break;
        }
        else
            A[i] = temp;
    }
    i++;
    for(i;i<len;i++)
    {
        int temp = pq.top();
        pq.pop();
        A[i] = temp;
    }
    
    return A;
}

// Solution 
// The suffix which gets affected is in descending order.
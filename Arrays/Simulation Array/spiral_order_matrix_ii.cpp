// Spiral Order Matrix II

// Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.

// Input Format - The first and the only argument contains an integer, A.
// Output Format - Return a 2-d matrix of size A x A satisfying the spiral order.

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> result(A);
    
    //int n = A*A;
    
    for(int i = 0; i<A;i++)
        result[i].resize(A);
        
    int top = 0;
    int bottom = A-1;
    int left = 0; 
    int right = A-1;
    
    int n = 1;
    while(n<=A*A)
    {
        for(int i = left; i<=right;i++)
        {
            result[top][i] = n;
            n++;
        }
        top++;
        
        for(int i = top ; i<=bottom;i++)
        {
            result[i][right] = n;
            n++;
        }
        right--;
        
        for(int i = right ; i>=left;i--)
        {
            result[bottom][i] = n;
            n++;
        }
        bottom--;
        
        for(int i = bottom; i<=top; i--)
        {
            result[i][left] = n;
            n++;
        }
        left++;
    }
    
    return result;
}

// Solution
// Implementation
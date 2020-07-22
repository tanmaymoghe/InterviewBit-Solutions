// Set Matrix Zeros 

// Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
// Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.

// Input Format -The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
// Output Format - Return a 2-d matrix that satisfies the given conditions.

void Solution::setZeroes(vector<vector<int> > &A) {
    int rows = A.size();
    int columns = A[0].size();
    
    bool changeRows[rows]; // if corresponding row has zero or not
    bool changeColumns[columns]; // if corresponding column has zero or not
    memset(changeRows,false,sizeof(bool)*rows);
    memset(changeColumns,false,sizeof(bool)*columns);
    
    for(int i = 0;i<rows;i++)
    {
        for(int j = 0; j<columns; j++)
        {
            if(A[i][j] == 0)
            {
                changeRows[i] = true;
                changeColumns[j] = true;
            }
        }
    }
    
    for(int i = 0; i<rows;i++)
    {
        if(changeRows[i])
        {
            for(int j = 0;j<columns;j++)
                A[i][j] = 0;
        }
    }
    
    for(int i = 0; i<columns;i++)
    {
        if(changeColumns[i])
        {
            for(int j = 0; j<rows;j++)
                A[j][i] = 0;
        }
    }
}

// Solution
// Two boolean arrays - number of rows and number of columns.
// If zero encountered - set to true so as to change the entire row/column. Else if false, not to change.

// One optimization -
// No need to use boolean arrays for rows and columns.
// Use the first row and first columns to store whether that row or column has zeros or not.
// Use two other booleans R and C to store whether the first row and column have zeros or not. So as to change in the end.
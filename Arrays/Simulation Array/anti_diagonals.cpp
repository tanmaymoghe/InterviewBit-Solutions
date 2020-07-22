// Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

// Input: 	
// 1 2 3
// 4 5 6
// 7 8 9
// Return the following :
// [ 
//   [1],
//   [2, 4],
//   [3, 5, 7],
//   [6, 8],
//   [9]
// ]

bool inMatrix(int rows, int columns, int i, int j);

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int>> result;
    
    int rows = A.size();
    int columns = A[0].size();
    
    //cout << "boo";
    for(int i = 0; i<columns;i++)
    {
        vector<int> antiDiag;
        antiDiag.push_back(A[0][i]);
        
        int xindex = 0;
        int yindex = i;
        
        bool temp = inMatrix(rows,columns,xindex+1,yindex-1);
        
        while(temp)
        {
            xindex = xindex+1;
            yindex = yindex-1;
            
            antiDiag.push_back(A[xindex][yindex]);
            
            temp = inMatrix(rows,columns,xindex+1,yindex-1);
        }
        
        result.push_back(antiDiag);
    }
    
    for(int i = 1; i<rows;i++)
    {
        vector<int> antiDiag;
        antiDiag.push_back(A[i][columns-1]);
        
        int xindex = i;
        int yindex = columns-1;
        
        bool temp = inMatrix(rows,columns,xindex+1,yindex-1);
        
        while(temp)
        {
            xindex = xindex+1;
            yindex = yindex-1;
            
            antiDiag.push_back(A[xindex][yindex]);
            
            temp = inMatrix(rows,columns,xindex+1,yindex-1);
        }
        
        result.push_back(antiDiag);
    }
    
    return result;
}

bool inMatrix(int rows, int columns, int i, int j)
{
    bool t1,t2;
    if(i>=0&&i<rows)
        t1 = true;
    else
        t1 = false;
    if(j>=0&&j<columns)
        t2 = true;
    else
        t1 = false;
    
    if(t1&&t2)
        return true;
    else
        return false;
}

// Solution - Implementation
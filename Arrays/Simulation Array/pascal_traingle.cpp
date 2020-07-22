// Pascal Triangle

// Given numRows, generate the first numRows of Pascal’s triangle.
// Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> result;
    
    if(A==0)
        return result;
    
    vector<int> one;
    one.push_back(1);
    result.push_back(one);
    
    if(A==1)
        return result;
        
    for(int i = 1; i<A; i++)
    {
        
        vector<int> temp = result[i-1];
        vector<int> topush;
        
        topush.push_back(1);
        
        for(int j = 0; j<temp.size()-1;j++)
        {
            int sum = temp[j] + temp[j+1];
            topush.push_back(sum);
        }
        
        topush.push_back(1);
        
        result.push_back(topush);
    }
    
    return result;
}

// Solution
// Initialize with one.
// Make temp array, push one at begin, traverse the last array and push reqd elements, again push one.
// Push this array to result.
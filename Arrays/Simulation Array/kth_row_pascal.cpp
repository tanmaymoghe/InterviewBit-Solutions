// Kth Row of Pascal's Triangle

// Given an index k, return the kth row of the Pascal’s triangle.
// Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

vector<int> Solution::getRow(int A) {
    vector<int> result;
    result.push_back(1);
    
    for(int i = 1; i<=A;i++)
    {
        vector<int> temp;
        temp.push_back(1);
        for(int i = 0; i<result.size()-1;i++)
            temp.push_back(result[i]+result[i+1]);
        temp.push_back(1);
        result = temp;
    }
    
    return result;
}

// Solution - Implementation
// Only use two arrays, one temporary.
// Find Permutation

// Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.
// D means the next number is smaller, while I means the next number is greater.

// 1. Length of given string s will always equal to n - 1
// 2. Your solution should run in linear time and space

// Input 1: n = 3 s = ID
// Return: [1, 3, 2]

vector<int> Solution::findPerm(const string A, int B) {
    vector<int> result;
    int I = 0;
    int D = 0;
    
    for(int i = 0; i<B-1;i++)
    {
        if(A[i] == 'I')
            I++;
        else
            D++;
    }
    
    I = D+1;
    D = D+1;
    
    result.push_back(I);
    for(int i = 0; i<B-1;i++)
    {
        if(A[i] == 'I')
        {
            I++;
            result.push_back(I);
        }
        
        if(A[i] == 'D')
        {
            D--;
            result.push_back(D);
        }
    }
    
    return result;
}

// Solution
// Fund suitable midpoint. Go on pushing according to I or D then (from both sides of custom partition).
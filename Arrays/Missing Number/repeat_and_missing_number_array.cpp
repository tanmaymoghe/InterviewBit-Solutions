// Repeat and Missing Number Array

// You are given a read only array of n integers from 1 to n.
// Each integer appears exactly once except A which appears twice and B which is missing.
// Return A and B.

// Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
// Note that in your output A should precede B.

// Input:[3 1 2 5 3] 
// Output:[3, 4] 
// A = 3, B = 4

// There are certain problems which are asked in the interview to also check how you take care of overflows in your problem.
// This is one of those problems.
// Please take extra care to make sure that you are type-casting your ints to long properly and at all places. 
// Try to verify if your solution works if number of elements is as large as 105

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    
    long sum = 0;
    long sumsquare = 0;
    
    for(int i = 0; i<n;i++)
    {
        long num = i + 1;
        
        sum = sum + num;
        sumsquare = sumsquare + num*num;
        
        num = A[i];
        
        sum = sum - num;
        sumsquare = sumsquare - num*num;
    }
    
    vector<int> result;
    
    long bplusa = sumsquare/sum;
    
    long b = (bplusa + sum)/2;
    long a = bplusa - b;
    
    result.push_back((int)a);
    result.push_back((int)b);
    
    return result;
    
}

// Solution
// Two equations, two unknowns - sum and sum of squares.
// Take care of typecasting 
// One more solution below, if the vector is not constant (index val made negative if index encountered)

vector<int> Solution::repeatedNumber1(const vector<int> &A) {
    int len = A.size();
    for(int i = 0; i<len; i++)
    {
        if(A[i] > 0)
            A[A[i]] = -A[A[i]];
        else
        {
            int j = -A[i];
            A[j] = -A[j];
        }
    }
    vector<int> result;
    for(int i = 0; i<)
}
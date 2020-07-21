// Triplets with Sum between given range

// Given an array of real numbers greater than zero in form of strings.
// Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
// Return 1 for true or 0 for false.

// Given [0.6, 0.7, 0.8, 1.2, 0.4] ,
// You should return 1 as
// 0.6+0.7+0.4=1.7, 1<1.7<2

// O(n) solution is expected.

// stof function - converts string to float and returns float

int Solution::solve(vector<string> &A) {
    int len = A.size();
    
    if(len<3)
        return 0;
        
    vector<float> window;
    window.push_back(stof(A[0]));
    window.push_back(stof(A[1]));
    window.push_back(stof(A[2]));
    sort(window.begin(),window.end());

    float sum = stof(A[0]) + stof(A[1]) + stof(A[2]);
    
    for(int i = 3; i<len; i++)
    {
        if(sum>1.0 && sum<2.0)
            return 1;
        
        if(sum < 1.0)
            window.erase(window.begin());
        
        else
            window.pop_back();
            
        window.push_back(stof(A[i]));
        sort(window.begin(),window.end());
        sum = window[0] + window[1] + window[2];
    }
    
    if(sum>1.0 && sum<2.0)
        return 1;
        
    return 0;
    
}

// Solution 
// A sliding window technique is used. 
// A sorted window with the first three elements is made. 
// At each iteration, sum is calculated. 
//     If between 1 and 2, problem solved. 
//     If less than 1, remove smallest element. 
//     If greater than 2, remove largest element. 
//     Add next element to the window. 

// This approach works for any range of sum.
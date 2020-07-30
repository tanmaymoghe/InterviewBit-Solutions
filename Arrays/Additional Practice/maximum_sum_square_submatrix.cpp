// Maximum Sum Square SubMatrix

// Given a 2D integer matrix A of size N x N find a B x B submatrix where B<= N and B>= 1, 
// such that sum of all the elements in submatrix is maximum.
// Return the sum 

int Solution::solve(vector<vector<int> > &A, int B) {
    int len = A.size();
    int sumarr[len-B+1][len-B+1]; // dp array to maintain sums
    int maxsum = INT_MIN;
    
    int blen[len-B+1][len]; // preprocessed array which has sums of b length verticals.
    for(int i = 0; i<len;i++) // First row of blen computed
    {
        int temp = 0;
        for(int j = 0; j<B;j++)
            temp += A[j][i];
        blen[0][i] = temp;
    }
    
    for(int i = 1; i<len-B+1;i++) // DP used to compute next levels
    { 
        for(int j = 0; j<len;j++)
            blen[i][j] = blen[i-1][j] + A[i+B-1][j] - A[i-1][j];
    }
    
    for(int i = 0; i<len-B+1;i++) // first level of sumarr computed by adding sums
    {
        int temp = 0;
        for(int j = 0; j<B; j++)
            temp += blen[i][j];
            sumarr[i][0] = temp;
            maxsum = max(maxsum,sumarr[i][0]);
    }
    
    
    for(int i = 0; i<len-B+1;i++) // dp used to calculate next levels
    {
        for(int j = 1; j<len-B+1;j++)
        {
            sumarr[i][j] = sumarr[i][j-1] - blen[i][j-1] + blen[i][j+B-1];
            maxsum = max(maxsum,sumarr[i][j]);
        }
    }
    
    return maxsum;
}

// Solution 
// Preprocessing step, calculate sum of all vertical strips of size B x 1.
// calculate sum of first sub-square in a row as sum of first B strips in that row. 
// Remaining sub-squares, we can calculate sum in O(1) time by removing the leftmost strip of previous subsquare and adding the rightmost strip of new square
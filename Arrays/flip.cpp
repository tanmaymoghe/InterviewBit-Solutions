// Flip

// You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. 
// In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. 
// By flipping, we mean change character 0 to 1 and vice-versa.

// Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. 
// If you don’t want to perform the operation, return an empty array. 
// Else, return an array consisting of two elements denoting L and R. 
// If there are multiple solutions, return the lexicographically smallest pair of L and R.

// Notes:
// Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.

// S = 010
// Pair of [L, R] | Final string
// _______________|_____________
// [1 1]          | 110
// [1 2]          | 100
// [1 3]          | 101
// [2 2]          | 000
// [2 3]          | 001
// We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].

// If S = 111
// No operation can give us more than three 1s in final string. So, we return empty array [].

vector<int> Solution::flip(string A) {
    vector<int> result;
    
    int start = -1; // final interval start
    int end = -1; // final interval end
    
    int stemp = -1; // temporary interval start
    int etemp = -1; // temporary interval end
    
    int l = 0; // temporary benefit (after flipping)
    int m = 0; // maximum benefit (after flipping)
    
    int len = A.length();
    
    if(A[0] == '0') // initital conditions if first element is zero
    {
        start = 0;
        end = 0;
        stemp = 0;
        etemp = 0;
        l = 1;
        m = 1;
    }
    
    if(A[0] == '1') // initial condition if first element is one
        l = -1;
        
    for(int i = 1; i<len;i++)
    {
        if(A[i] == '0')
        {
            if(l<0)  // temporary benefit is now negative. Therefore we can start again from zero
            {
                l = 1;
                stemp = i;
                etemp = i;
            }
            else
            {
                l++;
                etemp++;
            }
            
            if(l>m)  // temporary benefit greater than maximum benefit
            {
                m = l;
                start = stemp;
                end = etemp;
            }
        }
        else
        {
            l--;
            etemp++;
        }
        
        //cout << " i = " << i << "  l = " << l << "   m = " << m << endl;
    }
    
    if(m==0)
        return result;
    else
    {
        result.push_back(start+1);
        result.push_back(end+1);
        return result;
    }
}

// Solution 
// Maintain two arrays - temporary and final interval (for maximum contiguous sum)
// Use kadane's algorithm for max contiguous subarray (using positive contiguous subarrays)
// As lexicographically smallest array is to be returned, change absolute maximum only when temporary one is strictly greater.
// Take care of the edge cases:-
// Also take care whether, first element is zero or one  
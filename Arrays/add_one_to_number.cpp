// Add One To Number

// Given a non-negative number represented as an array of digits,
// add 1 to the number ( increment the number represented by the digits ).
// The digits are stored such that the most significant digit is at the head of the list.

// If the vector has [1, 2, 3]
// the returned vector should be [1, 2, 4]
// as 123 + 1 = 124.

vector<int> Solution::plusOne(vector<int> &A) {
    int len = A.size();
    
    for(int i = len-1; i>=0; i--)
    {
        if(A[i] != 9)
        {
            A[i]++;
            return A;
        }
        else
            A[i] = 0;
    }
    
    A.insert(A.begin(),1);
    return A;
}

// Solution
// 1. Take care of zeros before most significant digit in input 
// 2. Take care if 9 is the last digit (make it zero and go one digit back)
// 3. If not 9, add 1 to last digit and return
// 4. If first digit 9, have to add a new 1 at beginning
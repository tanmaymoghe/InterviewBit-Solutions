// Find Duplicate in Array

// Given a read only array of n + 1 integers between 1 and n, 
// find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

// If there are multiple possible answers ( like in the sample case above ), output any one.
// If there is no duplicate, output -1

int Solution::repeatedNumber(const vector<int> &A) {
    int len = A.size();
    
    int i1 = A[0];
    int i2 = A[0];
    
    while(true)
    {
        
        i1 = A[i1];
        i2 = A[A[i2]];
        
        if(i1==i2)
            break;
    }
    
    i1 = A[0];
    
    while(i1!=i2)
    {
        i1 = A[i1];
        i2 = A[i2];
    }
    
    return i1;
}

// Solution 
// Same as hare tortoise algo for detecting loop in a linked list. 

// Another Solution 
// Make sqrt(n) buckets. Atleast one will overflow. Make another pass and use hash table to maintain frequencies.
// Hence, O(n) time complexity (two passes) and O(sqrt(n)) space complexity.
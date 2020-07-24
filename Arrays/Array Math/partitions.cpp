// Partitions

// You are given a 1D integer array B containing A integers.
// Count the number of ways to split all the elements of the array into 3 contiguous parts so that the sum of elements in each part is the same.
// Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n])

// Input Format
// First argument is an integer A.
// Second argument is an 1D integer array B of size A.

// Output Format
// Return a single integer denoting the number of ways to split the array B into three parts with the same sum.

// Solution 1 - O(n^2) - traverse the array, whenever a prefix array with sum/3 is found, solve two partition problem for the remaining array.

int solve2(int sum, vector<int> &A, int size, int start);
 
int Solution::solve(int A, vector<int> &B) {
    if(A<3)
        return 0;
        
    int sum=0;
    for(int i=0; i<A;i++)
        sum = sum + B[i];
        
    if(sum%3 != 0)
        return 0;
        
    int parts = 0;
    sum = sum/3;
    int tempsum = 0;
    
    for(int i = 0; i<A; i++)
    {
        tempsum = tempsum + B[i];
        //cout << tempsum << endl;
        if(tempsum == sum)
            parts = parts + solve2(sum,B,A-i-1,i+1);
            
        //cout << parts << " p "<< endl;
    }
    
    return parts;
}
 
int solve2(int sum, vector<int> &A, int size, int start)
{
    int target_sum = 0;
    int parts = 0;
    for(int i = 0; i<size-1;i++)
    {
        target_sum = target_sum + A[i+start];
        if(target_sum==sum)
            parts++;
    }
    
    return parts;
}

// Solution II :- O(nlogn)
// 1. Make a prefix sum array (for each index)
// 2. Make an array containing indices for which suffix sum is equal to total/3.
// 3. Whenever a prefix sum array (i) entry has entry == total/3, binary search in the indices array to check for indices greater than i+1
// (atleast one element has to be there in the middle)
// 4. add number of indices in array greater than i+1 to the answer. 

int Solution::solve(int A, vector<int> &B) {
    if(A<3)
        return 0;
    
    int prefixsum[A];
    int sum = 0;
    
    for(int i =0; i<A;i++)
    {
        sum = sum + B[i];
        prefixsum[i] = sum;
    }
    
    if(sum%3 != 0)
        return 0;
        
    int revsum = 0;
    vector<int> rev_indices;
    for(int i = A-1; i>=0; i--)
    {
        revsum = revsum + B[i];
        if(revsum == sum/3)
            rev_indices.insert(rev_indices.begin(),i);
    }

    int part = 0;
    for(int i = 0; i<A;i++)
    {
        if(prefixsum[i] == sum/3)
        {
            int current_parts = rev_indices.end() - lower_bound(rev_indices.begin(),rev_indices.end(),i+2); 
            // i+2 and not i+1 as atleast one element has to be there in the middle - the second partition
            part = part + current_parts;
        }
    }
    
    return part;
}

// Solution 3 - O(n)
// 1. First find the total and check if its divisible by 3
// 2. Traverse the array, calculate sum at each step 
// 3. Two variables are maintained, answer(final answer) and temp_count(how many initial partitions till now with sum = total/3)
// 4. If current sum is not (total/3)*2, add the current temp_count to the final answer. (Final partition fixed with permutations of initital partitions)
// In this condition, the index cannot be the first (then total is zero) and last(final partition should have atleast one element)

int Solution::solve(int A, vector<int> &B) {
    if(A<3)
        return 0;
        
    int total = 0;
    for(int i = 0; i<A; i++)
        total = total + B[i];
        
    if(total%3 != 0)
        return 0;
        
    total = total/3;
    int ans = 0;
    int curr_sum = 0;
    int temp = 0;
    
    for(int i = 0; i<A-1; i++) // limit is A-1 and not A as third partition should have atleast one element (if total==0)
    {
        curr_sum = curr_sum + B[i];
        
        if(curr_sum == 2*total && i>0) // i==0 then total is zero and this is the first partition
            ans = ans + temp;
            
        if(curr_sum == total)  // First partition count
            temp++;
    }
    
    return ans;
}
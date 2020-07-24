// N/3 Repeat Number

// You’re given a read only array of n integers. 
// Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.
// If so, return the integer. If not, return -1.
// If there are multiple solutions, return any one.

bool check_for_element(const vector<int> &A, int check, int freq)
{
    int len = A.size();
    int count = 0;
    for(int i = 0; i<len; i++)
    {
        if(A[i] == check)
            count++;
    }
    return (count>=freq)?true:false;
}

int Solution::repeatedNumber(const vector<int> &A) {
    int len = A.size();
    int reqfreq;
    if(len%3==0) reqfreq = len/3 + 1;
    else reqfreq = int(len/3) + 1;
    
    if(len==0) return -1;
    if(len<3) return A[0];
    
    int num1, freq1, num2, freq2;
    num1 = A[0];
    freq1 = 1;
    int numlist = 1;
    
    int i = 1;
    while(i<len)
    {
        int temp = A[i];
        
        if(numlist==0)
        {
            num1 = temp;
            freq1 = 1;
            numlist = 1;
        }
        
        else if(numlist==1)
        {
            if(temp==num1)
                freq1++;

            else
            {
                num2 = temp;
                freq2 = 1;
                numlist = 2;
            }
        }
        
        else if(numlist==2)
        {
            if(temp==num1 || temp==num2)
            {
                if(temp==num1)
                    freq1++;
                else // temp==num2
                    freq2++;
            }
            else // a new number -> three distinct numbers
            {
                freq1--;
                freq2--;
                
                if(freq1==0 && freq2==0)
                    numlist = 0;
                else if(freq1==0 && freq2!=0)
                {
                    numlist = 1;
                    num1 = num2;
                    freq1 = freq2;
                }
                else if(freq1!=0 && freq2==0)
                    numlist = 1;
            }
        }
        i++;
    }
    if(numlist==0) return -1;
    if(numlist==1)
    {
        if(check_for_element(A,num1,reqfreq))
            return num1;
        else
            return -1;
    }
    if(numlist==2)
    {
        if(check_for_element(A,num1,reqfreq))
            return num1;
        
        if(check_for_element(A,num2,reqfreq))
            return num2;
            
        return -1;
    }
}

// Solution 
// If you have 3 distinct element from the array, if you remove them from the array, your answer does not change.
// Maintain two elements and their counts. For every element, two possibilities:
// 1. All three distinct, remove from array (decrease count by one of both, if count becomes zero then remove)
// 2. Same as one (increase that specific count)
// 3. Two elements not there, hence add to list (of two elements)
// Finally check the counts of these two remaining elements

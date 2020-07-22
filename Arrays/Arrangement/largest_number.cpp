// Largest Number

// Given a list of non negative integers, arrange them such that they form the largest number.
// Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

bool compareString(int x1, int x2);

string Solution::largestNumber(const vector<int> &A) {
    vector<int> Acopy;
    
    for(int i = 0; i<A.size();i++)
    {
        Acopy.push_back(A[i]);
        //cout << Acopy[i] << "  ";
    }        
    sort(Acopy.begin(),Acopy.end(),compareString);
    
    string result = "";
    
    int i = 0;
    while(i<Acopy.size() && Acopy[i] == 0)
        i++;
    
    for(i; i<Acopy.size();i++)
        result += to_string(Acopy[i]);
    
    if(result == "")
        result += '0';
        
    return result;
}

bool compareString(int x1, int x2)
{
    string as = to_string(x1) + to_string(x2);
    string bs = to_string(x2) + to_string(x1);
    
    if(as.compare(bs) > 0)
        return true;
    return false;
}

// Solution
// A custom sort function is used. 
// In C++, if f(param1,param2) is the custom function and true is returned if param1>param2 and false if param1<param2 =>ascending sort.
// Else, descending sort.
// In this question, we have used a custom sort to compare strings. 
// Take care of the leading zeros.
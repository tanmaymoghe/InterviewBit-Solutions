// Max Distance

// Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

int Solution::maximumGap(const vector<int> &A) {
    vector<pair<int,int>> pairarr;
    int len = A.size();
    
    if(len==1)
        return 0;
    
    for(int i = 0;i<len;i++)
        pairarr.push_back(make_pair(A[i],i));
    sort(pairarr.begin(),pairarr.end());
    
    int diff = pairarr[1].second - pairarr[0].second;
    int minindex = min(pairarr[1].second,pairarr[0].second);
    
    for(int i=2; i<len;i++)
    {
        minindex = min(minindex,pairarr[i].second);
        diff = max(diff,pairarr[i].second - minindex);
    }
    
    if(diff<=0)  
        return 0;
    else
        return diff;
    
}

// Solution 
// Make index value pair array then sort.
// Now we have to find max index in suffix array.
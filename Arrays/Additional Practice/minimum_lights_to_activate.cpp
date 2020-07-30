// Minimum Lights to Activate

// There is a corridor in a Jail which is N units long. Given an array A of size N. 
// The ith index of this array is 0 if the light at ith position is faulty otherwise it is 1.
// All the lights are of specific power B which if is placed at position X, it can light the corridor from [ X-B+1, X+B-1].
// Initially all lights are off.
// Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.

// A = [ 0, 0, 1, 1, 1, 0, 0, 1].
// B = 3
// Turn on the lights at 3rd and 8th index.
// Light at 3rd index covers from [ 1, 5] and light at 8th index covers [ 6, 8].

// A = [ 0, 0, 0, 1, 0].
// B = 3
// There is no light which can light the first corridor.

int Solution::solve(vector<int> &A, int B) {
    int num_lights = 0;
    int len = A.size();
    vector<pair<int,int>> intervals;
    
    for(int i = 0; i<len;i++)
    {
        if(A[i]==1)
            intervals.push_back(make_pair(max(0,i-B+1),min(len-1,i+B-1)));
    }
    
    int max_end;
    int i = 0;
    int start = 0;
    while(i<intervals.size())
    {
        if(intervals[i].first > start)
            return -1;
            
        max_end = INT_MIN;
        
        while(i<intervals.size() && intervals[i].first<=start)
        {
            if(intervals[i].second >=start)
                max_end = max(intervals[i].second,max_end);
                
            i++;
        }
        
        num_lights++;
        if(max_end >= len-1)
            break;
            
        start = max_end + 1;
    }
    
    if(max_end < len-1) return -1;
    return num_lights;
}

// Solution 
// A variation of the minimum intervals required problem.
// First we make a vector of interval pairs. 
// Traverse the array and for each working light, push the suitable interval [i-B+1,i+B-1] into the intervals vector.
// This intervals vector would be sorted first be start and if equal, by finish. 
// Initialize num_lights to zero.
//     Now traverse the array. For each element that we visit, check all the intervals that can light this element and choose the latest one (furthest end). 
//     Add one to number_lights count. 
//     If any interval cannot light this position, return -1.
//     Now go to the end of this latest interval and repeat the above process from the element after this end. 
// If all intervals are finished and some elements are left at the end of the array, return -1.
// Now return num_lights. 
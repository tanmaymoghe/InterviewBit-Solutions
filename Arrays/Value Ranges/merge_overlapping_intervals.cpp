// Merge Overlapping Intervals

// Given a collection of intervals, merge all overlapping intervals.

// For example:
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].

// Make sure the returned intervals are sorted.

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool compareInterval(Interval i1, Interval i2) 
    return (i1.start < i2.start); 

bool overlap (Interval i1, Interval i2)
    return (i2.start <= i1.end);
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    int len = A.size();
    
    sort(A.begin(),A.end(),compareInterval);

    int s = 0;
    int e = 0;
    int i = 1;
    
    struct Interval sI = A[s];
    struct Interval eI;
    while(i<len)
    {
        eI = A[i];
        if(overlap(sI,eI))
        {
            sI.end = max(sI.end,eI.end);
            e++;
        }
        else
        {
            if(s==e)
            {
                s++;
                e++;
                sI = A[i];
            }
            
            else
            {
                A.erase(A.begin() + s,A.begin()+e+1);
                A.insert(A.begin() + s,sI);
                len = A.size();
                
                i = s;
                sI = A[i];
                s = i;
                e = s;
            }
        }
        i++;
    }
    
    if(e>s)
    {
        A.erase(A.begin() + s,A.begin()+e+1);
        A.insert(A.begin() + s,sI);
    }
    
    return A;
}

// Solution
// Sort the interval array by start.
// One by one, go one overlapping.
// Edge case - two intervals have adjacent end and start (like 8 and 9 - so have to merge)
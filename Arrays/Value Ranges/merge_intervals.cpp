// Merge Intervals

// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
// You may assume that the intervals were initially sorted according to their start times.

// Example 1:
// Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].
// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
// Make sure the returned intervals are also sorted.

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool inInterval(int val, Interval i)
{
    if(val>=i.start && val<=i.end)
        return true;
    return false;
}
 
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    int len = intervals.size();
    
    if(len==0)
    {
        intervals.push_back(newInterval);
        return intervals;
    }
    
    int start = -1;
    int end = -1;
    
    for(int i = 0; i<len;i++)
    {
        if(inInterval(newInterval.start,intervals[i]))
            start = i;
        
        if(inInterval(newInterval.end,intervals[i]))
            end = i;
    }
    
    if(start == end && start>=0)
        return intervals;
    
    //cout << start << " " << end;
    int j;
    int k;
    
    if(end == -1 && start!=-1)
    {
        j = start;
        
        if(j==len-1)
        {
            struct Interval i1 = Interval(intervals[j].start,newInterval.end);
            intervals.pop_back();
            intervals.push_back(i1);
            return intervals;
        }
        
        k = j+1;
        
        int temp = 0;
        while(true)
        {
            if(newInterval.end < intervals[k].start || k == len)
            {
                struct Interval i2 = Interval(intervals[j].start,newInterval.end);
                //cout << i2.start << " " << i2.end << endl;
                intervals.erase(intervals.begin()+j,intervals.begin()+k);
                intervals.insert(intervals.begin() + j,i2);
                return intervals;
            }
            
            k++;
        }
    }
    
    
    if(start == -1 && end!=-1)
    {
        j = 0;
        while(newInterval.start > intervals[j].start)
            j++;
        
        Interval i3 = Interval(newInterval.start,intervals[end].end);
        intervals.erase(intervals.begin()+j,intervals.begin()+end+1);
        intervals.insert(intervals.begin()+j,i3);
        return intervals;
        
    }
    
    if(start>=0 && end>=0)
    {
        Interval i4 = Interval(intervals[start].start,intervals[end].end);
        
        intervals.erase(intervals.begin()+start,intervals.begin()+end+1);
        
        intervals.insert(intervals.begin()+start,i4);
        
        return intervals;
    }
    
    if(start==-1 && end == -1)
    {
        j=0;
        
        while(newInterval.start > intervals[j].start)
        {
            j++;
            if(j==len)
            {
                intervals.push_back(newInterval);
                return intervals;
            }
        }
            
        k = len-1;
        while(newInterval.end < intervals[k].end)
            k--;
            
        Interval i5 = Interval(newInterval.start,newInterval.end);
        
        intervals.erase(intervals.begin()+j,intervals.begin()+k+1);
        
        intervals.insert(intervals.begin()+j,i5);
        
        return intervals;
    }
}

Solution
There are many cases. Each case is considered separately. 

Solution II 
Use a stack. If not overlapping, push else pop merge and push. 

Solution III
Push into array, sort and then merge the overlapping intervals.
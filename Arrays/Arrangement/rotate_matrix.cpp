// Rotate Matrix

// You are given an n x n 2D matrix representing an image.
// Rotate the image by 90 degrees (clockwise).
// You need to do this in place.
// Note that if you end up using an additional array, you will only receive partial score.

// If the array is
// [
//     [1, 2],
//     [3, 4]
// ]
// Then the rotated array becomes:
// [
//     [3, 1],
//     [4, 2]
// ]

pair<int,int> nextCord(int n, pair<int,int> curr, pair<int,int> start);

void Solution::rotate(vector<vector<int> > &A) {
    int n = A.size();
    
    pair<int,int> start = make_pair(0,0);
    pair<int,int> end = make_pair(floor(n/2),floor(n/2));
    
    while(true)
    {
        if(start == end)
            return;
        
        int stop = n - start.first - 1;
        int i = start.first;
        
        while(i<stop)
        {
            pair<int,int> curr = make_pair(i,start.second);
            pair<int,int> next = nextCord(n,curr,start);
            
            int currVal = A[curr.first][curr.second];
            int nextVal = A[next.first][next.second];
            
            int loop = 0;
            while(loop<4)
            {
                A[next.first][next.second] = currVal;
                currVal = nextVal;
                curr = next;
                next = nextCord(n,curr,start);
                nextVal = A[next.first][next.second];
                loop++;
            }
            
            i++;
        }
        
        start.first++;
        start.second++;
    }
    
    return;
}

pair<int,int> nextCord(int n, pair<int,int> curr, pair<int,int> start)
{
    int x = curr.first;
    int y = curr.second;
    
    if(x == start.first)
    {
        x = y;
        y = n - start.first - 1;
        
        return make_pair(x,y);
    }
    
    if(y == n - start.first - 1)
    {
        y = n - x - 1;
        x = n - start.first - 1;
        
        return make_pair(x,y);
    }
    
    if(x == n - start.first - 1)
    {
        x = y;
        y = start.first;
        
        return make_pair(x,y);
    }
    
    if(y == start.first)
    {
        y = n - x - 1;
        x = start.first;
        
        return make_pair(x,y);
    }
}

// Solution 
// Rotate each loop separately. 
// Next coordinate helper function is used.
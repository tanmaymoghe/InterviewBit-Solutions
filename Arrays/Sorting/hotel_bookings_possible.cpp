// Hotel Bookings Possible

// A hotel manager has to process N advance bookings of rooms for the next season. 
// His hotel has C rooms. 
// Bookings contain an arrival date and a departure date. 
// He wants to find out whether there are enough rooms in the hotel to satisfy the demand. 
// Write a program that solves this problem in time O(N log N) .

// Input Format
// First argument is an integer array A containing arrival time of booking.
// Second argument is an integer array B containing departure time of booking.
// Third argument is an integer C denoting the count of rooms.

// Output Format
// Return True if there are enough rooms for N bookings else return False.
// Return 0/1 for C programs.

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int i=0;
    int j=0;
    
    int len = arrive.size();
    int rooms = 0;
    bool loop = true;
    
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    
    while(loop)
    {
        int c1 = arrive[i];
        int c2 = depart[j];
        
        if(c1<c2)
        {
            rooms++;
            i++;
        }
        else if(c1>=c2)
        {
            rooms--;
            j++;
        }
        //cout << " c1 = " << c1 << " , c2 = " << c2 << " , rooms = " << rooms << endl;
        if(rooms>K)
            return false;
            
        loop = (i<len && j<len);
    }
    
    return true;
}

Solution
Sort arrival-dept pairs by arrival date. 
Iterate over them, if start encountered room++ else room--
If room>k exit else continue 

Another Solution - A big array (each element corresponding to a date)
//     int maxtime = 0;
//     int len = arrive.size();
//     for(int i = 0; i<len;i++)
//         maxtime = max(maxtime,depart[i]);
    
//     int arr[maxtime];
//     for(int i = 0; i<maxtime;i++)
//         arr[i] = 0;
    
//     for(int i = 0; i<len;i++)
//     {
//         int start = arrive[i];
//         int end = depart[i];
        
//         for(int j = start;j<end;j++)
//             arr[j]++;
//     }
    
//     int rooms = 0;
//     for(int i = 0; i<maxtime;i++)
//     {
//         //cout << arr[i] << "  ";
//         rooms = max(rooms,arr[i]);
//     }   
//     if(K>=rooms)
//         return true;
//     else
//         return false;
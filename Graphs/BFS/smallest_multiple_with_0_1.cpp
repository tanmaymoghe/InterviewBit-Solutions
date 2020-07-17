// Smallest Multiple With 0 and 1
//
// You are given an integer N.
// You have to find smallest multiple of N which consists of digits 0 and 1 only.
// Since this multiple could be large, return it in form of a string.
// Returned string should not contain leading zeroes.
//
// For example,
// For N = 55, 110 is smallest multiple consisting of digits 0 and 1.
// For N = 2, 10 is the answer.

int remainder_func(string s, int m)
{
    int len = s.length();
    int r = 0;
    for(int i = 0; i<len;i++)
    {
        r = r*10 + (s[i] - '0');
        r = r%m;
    }
    return r;
}

string Solution::multiple(int A) {
    queue<string> q;
    q.push("1");
    set<int> visit;

    while(!q.empty())
    {
        int len = q.size();
        for(int i = 0; i<len;i++)
        {
            string s = q.front();
            q.pop();

            int r = remainder_func(s,A);
            if(r==0)
                return s;
            else
            {
                if(visit.find(r) == visit.end())
                {
                    visit.insert(r);
                    q.push(s+"0");
                    q.push(s+"1");
                }
            }
        }
    }

    return "";
}

// SOLUTION - Consider two strings x and y that give same remainder.
// Let x be the smaller string.
// If by adding string z to y we get a number divisible by N, then by adding the same string to x we get a number divisible by N.
// Hence, we can ignore the string y (and future combinations by adding numbers to y)
// Above solution is like this but slightly inefficient when it comes to memory.

// Below is the efficient solution


string Solution::multiple1(int A) {
    vector<bool> visited(A);
    vector<int> parent(A);
    vector<bool> digit(A);

    queue<int> q;
    int rem = 1%A;
    visited[rem] = 1;
    parent[rem] = -1;
    digit[rem] = 1;
    q.push(rem);

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        if(curr==0) break;

        int mod0 = (curr*10)%A; //Remainder if Next Digit Zero
        int mod1 = (curr*10 + 1)%A; // Remainder if Next Digit One

        if(visited[mod0]==0)
        {
            visited[mod0] = 1;
            parent[mod0] = curr;
            digit[mod0] = 0;
            q.push(mod0);
        }

        if(visited[mod0]==1)
        {
            visited[mod1] = 1;
            parent[mod1] = curr;
            digit[mod1] = 1;
            q.push(mod1);
        }
    }

    int i = 0;
    string ans = "";
    while(i!=-1)
    {
        if(digit[i]) ans = ans + "1";
        else ans = ans + "0";
        i = parent[i];
    }

    return ans;
}

// SOLUTION
// there are N states (remainders from 0 to N-1), where i’th state stores the smallest string which when take modulo with N gives i.
// After reaching a state, store two values
// 1. From which node I arrived at node x from. Say this is node y.
// 2. What(0 or 1) did I append at string at node y to reach node x
// After reaching state 0, backpropagate to construct the string.

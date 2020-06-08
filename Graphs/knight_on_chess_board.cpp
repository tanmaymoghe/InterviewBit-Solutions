// Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.
// If knight can not move from the source point to the destination point, then return -1.
// The first argument of input contains an integer A.
// The second argument of input contains an integer B.
//     => The chessboard is of size A x B.
// The third argument of input contains an integer C.
// The fourth argument of input contains an integer D.
//     => The Knight is initially at position (C, D).
// The fifth argument of input contains an integer E.
// The sixth argument of input contains an integer F.
//     => The Knight wants to reach position (E, F).

// *IMPORTANT ======> 1 <= A, B <= 500

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    bool visited[A+1][B+1];
    memset(visited,false,(A+1)*(B+1));

    vector<int> xmove{2,2,-2,-2,1,-1,1,-1};
    vector<int> ymove{1,-1,1,-1,2,2,-2,-2};

    if(C==E && D==F) return 0;
    queue<int> q1,q2;
    q1.push(C);
    q2.push(D);
    visited[C][D] = true;
    int count = 1;
    while(!q1.empty())
    {
        int len = q1.size();
        for(int i = 0; i<len;i++)
        {
            int x = q1.front();
            int y = q2.front();
            q1.pop();
            q2.pop();

            for(int j = 0; j<8;j++)
            {
                int xnew = x + xmove[j];
                int ynew = y + ymove[j];

                if(xnew>0 && ynew>0 && xnew<=A && ynew<=B)
                {
                    if(xnew==E && ynew==F)
                        return count;

                    if(!visited[xnew][ynew])
                    {
                        visited[xnew][ynew] = true;
                        q1.push(xnew);
                        q2.push(ynew);
                    }
                }
            }
        }
        count++;
    }

    return -1;
}

// SOLUTION
// Standard BFS for shortest path

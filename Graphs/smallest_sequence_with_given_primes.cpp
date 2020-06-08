// Smallest sequence with given Primes
//
// Given three prime number(p1, p2, p3) and an integer k.
// Find the first(smallest) k integers which have only p1, p2, p3 or a combination of them as their prime factors.
// Input :
// Prime numbers : [2,3,5]
// k : 5
// Output: {2,3,4,5,6}

int whichMin(int A, int B, int C)
{
    if(A<=B && A<=C)
        return 1;
    if(B<=A && B<=C)
        return 2;
    else
        return 3;
}

vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> result;
    int product = 1;

    queue<int> q1,q2,q3;
    q1.push(A);
    q2.push(B);
    q3.push(C);

    int i = 0;
    while(i<D)
    {
        int which = whichMin(q1.front(),q2.front(),q3.front());
        int pop;
        if(which==1)
        {
            pop = q1.front();
            q1.pop();
        }
        else if(which==2)
        {
            pop = q2.front();
            q2.pop();
        }
        else if(which==3)
        {
            pop = q3.front();
            q3.pop();
        }

        if(result.size() > 0)
        {
            int last = result.size() - 1;
            if(pop == result[last])
                continue;
        }

        q1.push(pop*A);
        q2.push(pop*B);
        q3.push(pop*C);

        result.push_back(pop);
        i++;
    }

    return result;
}

// SOLUTION 
// There are only 3 possibilities of getting to a new number : Multiply by p1 or p2 or p3.
// Maintain three queues, one for each prime
// take minimum(M) out of the three elements (one at front of each queue) and pop it from the respective queue
// add M to the finalAnswer if last element in finalAnswer != M and push M*p1, M*p2, M*p3 to q1,q2,q3
// if last element in finalAnswer == M, continue with loop

// Sum Of Fibonacci Numbers
//
// How many minimum numbers from fibonacci series are required
// such that sum of numbers should be equal to a given Number N?
// Note : repetition of number is allowed.
//
// N = 4
// Fibonacci numbers : 1 1 2 3 5 .... so on
// here 2 + 2 = 4
// so minimum numbers will be 2

int Solution::fibsum(int A) {
    if(A==0) return 0;
    if(A==1 || A==2) return 1;

    vector<int> fibo;
    fibo.push_back(1);
    fibo.push_back(2);
    int len = 1;
    int curr = 3;
    unordered_set<int> visited;
    while(curr<=A)
    {
        if(curr==A) return 1;
        len++;
        fibo.push_back(curr);
        curr = fibo[len] + fibo[len-1];
    }

    queue<pair<int,int>> q;
    for(int i = len; i>=0;i--)
    {
        q.push(make_pair(fibo[i],1));
        visited.insert(fibo[i]);
    }

    while(!q.empty())
    {
        pair<int,int> temp = q.front();
        q.pop();

        for(int i=0; i<=len;i++)
        {
            int compare = temp.first + fibo[i];

            if(compare==A) return (temp.second+1);

            if(!(visited.find(compare) == visited.end())) continue;

            q.push(make_pair(compare,temp.second+1));
        }
    }

    return 0;
}

// SOLUTION
// Above is a BFS solution.
// DP solution has similar memory and time requirements.
// But a much simpler solution exists.
// 1. Find all Fibonacci Terms less than or equal to K.
// 2. Initialize count = 0.
// 3. j = Index of last calculated Fibonacci Term.
// 4. while K > 0 do:
//     count += K / (fibo[j])     // Note that division is repeated subtraction.
//     K = K % (fibo[j])
//     j--;
// 5. Print count.
// This works because of the fibonacci property (can prove by contradiction)
// i.e. will always converge to the largest fibonacci term

// GREEDY SOLUTION below

int Solution::fibsum1(int A) {
    if(A==0) return 0;
    if(A==1 || A==2) return 1;

    vector<int> fibo;
    fibo.push_back(1);
    fibo.push_back(2);
    int len = 1;
    int curr = 3;
    //unordered_set<int> visited;
    while(curr<=A)
    {
        if(curr==A) return 1;
        len++;
        fibo.push_back(curr);
        curr = fibo[len] + fibo[len-1];
    }

    int count = 0;
    int sum = 0;
    while(A!=0)
    {
        count = count + A/fibo[len];
        A = A%fibo[len];
        len--;
    }

    return count;
}

// Understand why greedy approach works here
// Let fx be a number in fibonacci series
// 2*fx => count=2 (fx + fx)
// Also, 2*fx = fx + fx = fx + fx-1 + fx-2 = fx+1 + fx-2 hence count is still 2 and greedy approach works.
// Also, fx + any fibonacci number less than fx-1 < fx+1
// Also, fx-1 > fx/2
// Biggest chain will go on for alternate fibonacci 

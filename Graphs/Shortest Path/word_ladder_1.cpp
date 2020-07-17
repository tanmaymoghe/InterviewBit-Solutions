// Word Ladder I
//
// Given two words A and B, and a dictionary, C, find the length of shortest transformation sequence from A to B, such that:
// You must change exactly one character in every transformation.
// Each intermediate word must exist in the dictionary.
//
// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
//
// Input 1:
//     A = "hit"
//     B = "cog"
//     C = ["hot", "dot", "dog", "lot", "log"]
// Output 1:
//     5
// Explanation 1:
//     "hit" -> "hot" -> "dot" -> "dog" -> "cog"

int Solution::solve(string A, string B, vector<string> &C) {
    unordered_set<string> dict; // dictionary of words so that constant time lookup can be done
    unordered_set<string> visited; // dictionary of words visited while traversing the graph
    int len = C.size();
    for(int i = 0; i<len;i++)
        dict.insert(C[i]);

    if(dict.find(B)==dict.end()) // The target word also added to dictionary
        dict.insert(B);

    queue<string> q;
    q.push(A);
    visited.insert(A);
    int count = 1; // count of number of steps

    while(!q.empty())
    {
        int qlen = q.size();

        for(int i = 0; i<qlen;i++) // number of words at current level of graph search
        {
            string curr = q.front();
            q.pop();

            if(curr==B)
                return count;

            int str_len = curr.length();
            for(int j = 0; j<str_len; j++) // each valid permutation tested
            {
                char c = curr[j];
                for(char ci = 'a'; ci <= 'z'; ci++)
                {
                    if(ci==c)
                        continue;

                    curr[j] = ci;
                    if(!(dict.find(curr)==dict.end()))
                    {
                        if(visited.find(curr)==visited.end())
                        {
                            visited.insert(curr);
                            q.push(curr);
                        }
                    }
                }
                curr[j] = c;
            }
        }
        count++;
    }

    return 0;
}

// SOLUTION 
// Use BFS.
// Start from the given start word, traverse all words that adjacent (differ by one character) to it.
// Keep doing so until we find the target word or we have traversed all words.

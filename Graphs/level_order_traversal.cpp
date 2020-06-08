// Level Order
//
// Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).
// Example : Given binary tree
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]
// Also think about a version of the question where you are asked to do a level order traversal
// of the tree when depth of the tree is much greater than number of nodes on a level.
//
// (This is the version implemented here.
// The memory must be proportional to number of nodes on a level.
// A queue is maintained and an approach similar to BFS is done.)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> result;
    if(A==NULL)
        return result;

    queue<TreeNode*> q;
    q.push(A);
    TreeNode* trav;

    while(!q.empty())
    {
        int len = q.size();
        vector<int> current_level;
        for(int i = 0; i<len;i++)
        {
            trav = q.front();
            q.pop();

            current_level.push_back(trav->val);
            if(trav->left) q.push(trav->left);
            if(trav->right) q.push(trav->right);
        }

        result.push_back(current_level);
    }

    return result;
}

// SOLUTION
// Standard BFS.

// Clone Graph
//
// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(node==NULL)
        return NULL;

    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> visited;
    // A hash map which contains pairs (node in old graph, node in new graph)

    UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
    visited[node] = root;

    queue<UndirectedGraphNode*> q; // A queue for standard BFS of old graph
    q.push(node);

    while(!q.empty())
    {
        UndirectedGraphNode* temp = q.front();
        UndirectedGraphNode* cloned_node = visited[temp];
        q.pop();

        UndirectedGraphNode* trav;
        int neigh_len = temp->neighbors.size();
        for(int i = 0; i<neigh_len;i++)
        {
            trav = temp->neighbors[i];
            if(visited.find(trav)==visited.end()) // first encounter of a neighbour, hence need to clone it
            {
                UndirectedGraphNode* new_node = new UndirectedGraphNode(trav->label);
                cloned_node->neighbors.push_back(new_node);
                visited[trav] = new_node;
                q.push(trav);
            }
            else // neighbour node already cloned
            {
                cloned_node->neighbors.push_back(visited[trav]);
            }
        }
    }

    return root;
}

// SOLUTION
// Standard BFS traversal followed by cloning.
// Maintaining a hash map in order to track which nodes have already been cloned.

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V+1, false);
        vector<int> bfs;
        
            if(vis[0] == false) {
                vis[0] = true;
                queue<int> q;
                q.push(0);
                
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    bfs.push_back(node);
                    
                    for(auto it : adj[node]) {
                        if(vis[it] == false) {
                            q.push(it);
                            vis[it] = true;
                        }
                    }
                }
            }
        
        return bfs;
    }
};

class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& storedfs) {
        storedfs.push_back(node);
        vis[node] = 1;
        
        for(auto v : adj[node]) {
            if(vis[v] == 0) {
                dfs(v, adj, vis, storedfs);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> storedfs;
        vector<int> vis(V+1, 0);
        
        for(int i = 0; i < V; i++) {
            if(vis[i] == 0) {
                dfs(i, adj, vis, storedfs);
            }
        }
        
        return storedfs;
    }
};

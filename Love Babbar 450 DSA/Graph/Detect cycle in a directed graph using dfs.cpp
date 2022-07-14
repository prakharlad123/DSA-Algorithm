class Solution {
  public:
    bool checkCycle(int src, vector<int> adj[], vector<int>& vis, vector<int>& dfsvis) {
        vis[src] = 1;
        dfsvis[src] = 1;
        
        for(auto it : adj[src]) {
            if(vis[it] == 0) {
                if(checkCycle(it, adj, vis, dfsvis)) {
                    return true;
                }
            }
            else if(dfsvis[it] == 1) {
                return true;
            }
        }
        
        dfsvis[src] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V+1, 0);
        vector<int> dfsvis(V+1, 0);
        
        for(int i = 0; i < V; i++) {
            if(vis[i] == 0) {
                if(checkCycle(i, adj, vis, dfsvis)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

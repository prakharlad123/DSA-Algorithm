//Using DFS

class Solution {
  public:
    bool checkCycle(int s, int par, vector<int> adj[], vector<int>& vis) {
        vis[s] = 1;
        
        for(auto it : adj[s]) {
            if(vis[it] == 0) {
                if(checkCycle(it, s, adj, vis)) {
                    return true;
                }
            }
            else if(par != it) {
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V+1, 0);
        
        for(int i = 0; i < V; i++) {
            if(vis[i] == 0) {
                if(checkCycle(i, -1, adj, vis)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

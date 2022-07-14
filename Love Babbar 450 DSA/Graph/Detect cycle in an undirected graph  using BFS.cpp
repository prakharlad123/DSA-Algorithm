//Using BFS

class Solution {
  public:
    bool checkCycle(int s, int V, vector<int> adj[], vector<int>& vis) {
        queue<pair<int, int>> q;
        q.push({s, -1});
        vis[s] = 1;
        
        while(!q.empty()) {
            int node = q.front(). first;
            int par = q.front().second;
            q.pop();
            
            for(auto it : adj[node]) {
                if(vis[it] == 0) {
                    q.push({it, node});
                    vis[it] = 1;
                }
                else if(par != it) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(vis[i] == 0) {    
                if(checkCycle(i, V, adj, vis)) return true;        
            }
        }
        
        return false;
    }
};

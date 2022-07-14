class Solution {
  public:
    int numProvinces(vector<vector<int>> aj, int n) {
        vector<int> adj[n];
    
        for(int i = 0; i < aj.size(); i++) {
            for(int j = 0; j < aj[i].size(); j++) {
                if(aj[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<int> vis(n, 0);
        int components = 0;
        
        for(int i = 0; i<n; i++) {
            if(vis[i] == 0) {
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for(auto v : adj[node]) {
                        if(vis[v] == 0) {
                            q.push(v);
                            vis[v] = 1;
                        }
                    }
                }
                components++;
            }
        }
        
        return components;
    }
};

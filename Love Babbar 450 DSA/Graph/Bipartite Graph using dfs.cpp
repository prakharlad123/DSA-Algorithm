class Solution {
public:
    bool checkBipartite(int src, vector<int> adj[], vector<int>& color) {
        if(color[src] == -1) {
            color[src] = 1;
        }
        
        for(auto it : adj[src]) {
            if(color[it] == -1) {
                color[it] = 1 - color[src];
                if(!checkBipartite(it, adj, color)) {
                    return false;
                }
            }
            else if(color[it] == color[src]) {
                    return false;
            }
        }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V+1, -1);
	    
	    for(int i = 0; i < V; i++) {
	        if(color[i] == -1) {
	            if(!checkBipartite(i, adj,  color)) {
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};

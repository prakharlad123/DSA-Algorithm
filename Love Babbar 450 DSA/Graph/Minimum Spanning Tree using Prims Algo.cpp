class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> wt(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<int> mst(V, false);
        
        int cost = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        wt[0] = 0;
        parent[0] = -1;
        
        pq.push({0, 0});
        
        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            mst[u] = true;
            
            for(auto it : adj[u]) {
                int v = it[0];
                int weight = it[1];
                
                if(mst[v] == false && weight < wt[v]) {
                    wt[v] = weight;
                    pq.push({wt[v], v});
                    parent[v] = u;
                }
            }
        }
        
        for(int i = 0; i < V; i++) {
            cost += wt[i];
        }
        
        return cost;
    }
};

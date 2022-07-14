class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void findTopoSort(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
	    vis[node] = 1;
	    
	    for(auto it : adj[node]) {
	        if(vis[it] == 0) {
	            findTopoSort(it, adj, vis, st);
	        }
	    }
	    
	    st.push(node);
	    return ;
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> vis(V+1, 0);
	    stack<int> st;
	    vector<int> ans;
	    
	    for(int i = 0; i < V; i++) {
	        if(vis[i] == 0) {
	            findTopoSort(i, adj, vis, st);
	        }
	    }
	    
	    while(!st.empty()) {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};

class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    vector<int> adj[N];
	    vector<int> ans;
	    vector<int> indegree(N, 0);
	    
	    for(auto it : pre) {
	        adj[it.second].push_back(it.first);
	        indegree[it.first]++;
	    }
	    
	    queue<int> q;
	    
	    for(int i = 0; i < N; i++) {
	        if(indegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()) {
	       int node = q.front();
	       q.pop();
	       
	       ans.push_back(node);
	       
	       for(auto it : adj[node]) {
	           indegree[it]--;
	           if(indegree[it] == 0) {
	               q.push(it);
	           }
	       }
	    }
	    
	    
	    if(ans.size() == N) {
	        return true;
	    }
	    
	    return false;
	}
};

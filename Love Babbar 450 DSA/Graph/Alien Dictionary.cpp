class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        
        for(int i = 0; i < N-1; i++) {
            string fir = dict[i];
            string sec = dict[i+1];
            
            for(int j = 0; j < min(fir.length(), sec.length()); j++) {
                if(fir[j] != sec[j]) {
                    adj[fir[j] - 'a'].push_back(sec[j] - 'a');
                    break;
                }
            }
        }
        
        vector<int> indegree(K, 0);
        string ans = "";
        
        for(int i = 0; i < K; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < K; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            ans += ('a' + node);
            
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
};

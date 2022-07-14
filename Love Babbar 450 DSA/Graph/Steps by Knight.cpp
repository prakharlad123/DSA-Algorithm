class Solution 
{
    public:
	int minStepToReachTarget(vector<int>& Kn, vector<int>& Tar, int N) {
	    queue<pair<int, int>> q;
	    int cnt = 0;
	    int r[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	    int c[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	    
	    vector<vector<int>> vis(N, vector<int>(N, 0));
	    q.push({Kn[0]-1, Kn[1]-1});
	    vis[Kn[0]-1][Kn[1]-1] = 1;
	    
	    while(!q.empty()) {
	        int size = q.size();
	        while(size--) {
	            int x = q.front().first;
	            int y = q.front().second;
	            
	            q.pop();
	            
	            if(x == Tar[0]-1 && y == Tar[1]-1) {
	                return cnt;
	            }
	            
	            for(int i = 0; i < 8; i++) {
	                int cx = x + r[i];
	                int cy = y + c[i];
	                
	                if(cx >= 0 && cx < N && cy >= 0 && cy < N && !vis[cx][cy]) {
	                    q.push({cx, cy});
	                    vis[cx][cy] = 1;
	                }
	            }
	        }
	        cnt++;
	    }
	    
	    return -1;
	}
};

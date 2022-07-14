class Solution{
    public:
    int r[4] = {-1, 1, 0, 0};
    int c[4] = {0, 0, -1, 1};
    char dir[4] = {'U', 'D', 'L', 'R'};
    
    void solve(vector<vector<int>>& m, int n, int x, int y, string str, vector<string>& ans) {
        if(x == n-1 && y == n-1) {
            ans.push_back(str);
            return ;
        }
        
        if(m[x][y] == 1) {
            for(int i = 0; i < 4; i++) {
                int rx = x + r[i];
                int cy = y + c[i];
                
                if(rx >= 0 && rx < n && cy >= 0 && cy < n && m[rx][cy] == 1) {
                    m[x][y] = 0;
                    solve(m, n, rx, cy, str+dir[i], ans);
                    m[x][y] = 1;
                }
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0] == 0) {
            return {"-1"};
        }
        vector<string> ans;
        
        solve(m, n, 0, 0, "", ans);
        
        if(ans.size() == 0) {
            return {"-1"};
        }
        
        return ans;
    }
};

class Solution {
public:
	string FirstNonRepeating(string A){
		queue<char> q;
		vector<int> vis(26, 0);
		string ans = "";
		
		for(int i = 0; i < A.length(); i++) {
		    vis[A[i] - 'a']++;
		    q.push(A[i]);
		    
		    while(q.size() > 0 && vis[q.front() - 'a'] > 1) {
		        q.pop();
		    }
		    
		    if(q.size() > 0) {
		        ans.push_back(q.front());
		    }
		    else {
		        ans.push_back('#');
		    }
		}
		
		return ans;
	}
};

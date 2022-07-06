class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> ans;
        
        if(root == NULL) {
            return ans;
        }
        
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int x = it.second;
            Node* tmp = it.first;
            
            if(tmp->left) {
                q.push({tmp->left, x-1});
            }
            
            if(tmp->right) {
                q.push({tmp->right, x+1});
            }
            
            if(mp.find(x) == mp.end()) {
                mp[x] = tmp->data;
            }
        }
        
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }

};

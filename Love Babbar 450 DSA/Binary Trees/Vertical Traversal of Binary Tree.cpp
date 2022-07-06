class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root) {
        vector<int> ans;
        
        if(root == NULL) {
            return ans;
        }
        
        map<int, map<int, vector<int>>> mp;
        queue<pair<Node*, pair<int, int>>> q;
        
        q.push({root, {0, 0}});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int ver = it.second.first;
            int lev = it.second.second;
            Node *tmp = it.first;
            
            mp[ver][lev].push_back(tmp->data);
            
            if(tmp->left) {
                q.push({tmp->left, {ver-1, lev+1}});
            }
            
            if(tmp->right) {
                q.push({tmp->right, {ver+1, lev+1}});
            }
        }
        
        for(auto k : mp) {
            for(auto l : k.second) {
                ans.insert(ans.end(), l.second.begin(), l.second.end());
            }
        }
        
        return ans;
    }
};

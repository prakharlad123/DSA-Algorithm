class Solution {
  public:
    unordered_map<string, int> occ;
    
    string solve(Node *root) {
        if(root == NULL) {
            return "#";
        }
        
        string s;
        
        if(root->left == NULL && root->right == NULL) {
            s += to_string(root->data);
            return s;
        }
        
        s += to_string(root->data);
        s += solve(root->left);
        s += solve(root->right);
        
        occ[s]++;
        
        return s;
    }
    
    int dupSub(Node *root) {
        occ.clear();
        solve(root);
        
        for(auto it : occ) {
            if(it.second >= 2) {
                return 1;
            }
        }
        
        return 0;
    }
};

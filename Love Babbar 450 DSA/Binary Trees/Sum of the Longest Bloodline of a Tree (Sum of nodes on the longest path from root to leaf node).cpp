class Solution
{
public:
    vector<int> solve(Node* root) {
        if(root == NULL) {
            return {0, 0};
        }
        
        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);
        
        if(l[0] > r[0]) {
            return {l[0]+1, l[1] + root->data};
        }
        else if(r[0] > l[0]) {
            return {r[0]+1, r[1] + root->data};
        }
        
        else {
            return {l[0]+1, max(l[1], r[1]) + root->data};
        }
    }
    
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        if(root == NULL) {
            return 0;
        }
        
        vector<int> ans;
        ans = solve(root);
        
        return ans[1];
    }
};

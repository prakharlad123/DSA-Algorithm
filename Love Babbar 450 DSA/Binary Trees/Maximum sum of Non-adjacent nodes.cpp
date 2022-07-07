class Solution{
  public:
    unordered_map<Node*, int> dp;
    
    int getMaxSum(Node *root) {
        if(root == NULL) {
            return 0;
        }
        
        if(dp.find(root) != dp.end()) {
            return dp[root];
        }
        
        int take = root->data;
        
        if(root->left) {
            take += getMaxSum(root->left->left);
            take += getMaxSum(root->left->right);
        }
        
        if(root->right) {
            take += getMaxSum(root->right->left);
            take += getMaxSum(root->right->right);
        }
        
        int nottake = getMaxSum(root->left) + getMaxSum(root->right);
        
        return dp[root] = max(take, nottake);
    }
};

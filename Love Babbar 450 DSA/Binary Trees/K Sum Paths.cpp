class Solution{
  public:
    void solve(Node* root, int k, vector<int>& path, int& count) {
        if(root == NULL) {
            return ;
        }
        
        path.push_back(root->data);
        solve(root->left, k, path, count);
        solve(root->right, k, path, count);
        
        int sum = 0;
        for(int j = path.size()-1; j>=0; j--) {
            sum += path[j];
            if(sum == k) {
                count++;
            }
        }
        
        path.pop_back();
    }
  
    int sumK(Node *root, int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, k, path, count);
        
        return count;
    }
};

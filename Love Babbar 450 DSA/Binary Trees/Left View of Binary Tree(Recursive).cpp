void getLeftView(Node* root, int level, vector<int>& ans) {
    if(root == NULL) {
        return ;
    }
    
    if(level == ans.size()) {
        ans.push_back(root->data);
    }
    
    getLeftView(root->left, level+1, ans);
    getLeftView(root->right, level+1, ans);
} 

vector<int> leftView(Node *root) {
   vector<int> ans;
   
   if(root == NULL) {
      return ans;
   }
   
   int level = 0;
   
   getLeftView(root, level, ans);
   
   return ans;
}

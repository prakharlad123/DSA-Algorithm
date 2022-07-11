class Solution {
  public:
    void inorder(Node* root, int& i, int K, int& ans) {
        if(root == NULL) {
            return ;
        }
        
        if(i == K) {
            return ;
        }
        
        inorder(root->left, i, K, ans);
        i++;
        if(i == K) {
            ans = root->data;
            return;
        }
        inorder(root->right, i, K, ans);
    }
    int KthSmallestElement(Node *root, int K) {
        int ans = -1;
        int i = 0;
        inorder(root, i, K, ans);
        
        return ans;
    }
};

class Solution {
  public:
    int findHeight(Node* node) {
        if(node == NULL) {
            return 0;
        }
        
        int left = findHeight(node->left);
        int right = findHeight(node->right);
        
        int tmp = node->data;
        node->data = left + right;
        
        return tmp + left + right;
    }
    
    void toSumTree(Node *node) {
        if(node == NULL) {
            return ;
        }
        
        findHeight(node);
    }
};

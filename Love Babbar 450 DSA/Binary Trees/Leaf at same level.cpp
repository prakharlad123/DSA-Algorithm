class Solution{
  public:
    /*You are required to complete this method*/
    int findHeight(Node* node) {
        if(node == NULL) {
            return 0;
        } 
        
        int lh = findHeight(node->left);
        int rh = findHeight(node->right);
        
        if(lh == -1 || rh == -1) {
            return -1;
        }
        
        if(lh != 0 && rh != 0 && lh != rh) {
            return -1;
        }
        
        return 1 + max(lh, rh);
    }
    
    bool check(Node *root) {
        if(root == NULL) {
            return true;
        }
        if(findHeight(root) == -1) {
            return false;
        }
        
        return true;
    }
};

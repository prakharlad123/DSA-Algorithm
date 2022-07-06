class Solution{
    public:
    int findHeight(Node *node) {
        if(node == NULL) {
            return 0;
        }
        
        int lh = findHeight(node->left);
        int rh = findHeight(node->right);
        
        if(lh == -1 || rh == -1) {
            return -1;
        }
        
        if(abs(lh - rh) > 1) {
            return -1;
        }
        
        return 1+max(lh, rh);
    }
    
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root == NULL) {
            return true;
        }
        
        if(findHeight(root) == -1) {
            return false;
        }
        
        return true;
    }
};

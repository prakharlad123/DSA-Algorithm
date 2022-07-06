class Solution
{
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
        
        if(lh != 0 || rh != 0) {
            if(lh + rh != node->data) {
                return -1;
            }
        }
        
        return node->data + lh + rh;
    }
    
    bool isSumTree(Node* root) {
        if(root == NULL) {
            return true;
        }
        
        if(findHeight(root) == -1) {
            return false;
        }
        
        return true;
    }
};

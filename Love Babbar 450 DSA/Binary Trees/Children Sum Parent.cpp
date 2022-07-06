class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        if(root == NULL) {
            return true;
        }
        
        int l = 0, r = 0;
        
        bool left = isSumProperty(root->left);
        bool right = isSumProperty(root->right);
        
        if(root->left) {
            l = root->left->data;
        }
        
        if(root->right) {
            r = root->right->data;
        }
        
        if(l != 0 || r != 0) {
            return ((l + r) == root->data) && left && right;
        }
        
        return left && right;
    }
};

class Solution{
    public:
    int findHeight(struct Node* node) {
        if(node == NULL)
            return 0;
            
        int l = findHeight(node->left);
        int r = findHeight(node->right);
        
        return 1 + max(l, r);
    }
    
    int height(struct Node* node){
        if(node == NULL) 
            return 0;
            
        return findHeight(node);
    }
};

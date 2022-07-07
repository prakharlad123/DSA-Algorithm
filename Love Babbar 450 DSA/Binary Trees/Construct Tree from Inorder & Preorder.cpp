class Solution{
    public:
    Node* build_tree(int preorder[], int preStart, int preEnd, int inorder[], int inStart, int inEnd, map<int, int>& in) {
        if(preStart > preEnd || inStart > inEnd) {
            return NULL;
        }
        
        Node* root = new Node(preorder[preStart]);
        
        int ind = in[preorder[preStart]];
        int num_left = ind - inStart;
        
        root->left = build_tree(preorder, preStart+1, preStart+num_left, inorder, inStart, ind-1, in);
        root->right = build_tree(preorder, preStart+num_left+1, preEnd, inorder, ind+1, inEnd, in);
        
        return root;
    }
    
    Node* buildTree(int inorder[], int preorder[], int n) {
        map<int, int> in;
        
        for(int i = 0; i < n; i++) {
            in[inorder[i]] = i;
        }
        
        return build_tree(preorder, 0, n-1, inorder, 0, n-1, in);
    }
};

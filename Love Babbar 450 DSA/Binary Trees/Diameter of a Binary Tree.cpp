class Solution {
  public:
    int findHeight(Node* node, int& dia) {
        if(node == NULL)
            return 0;
            
        int lh = findHeight(node->left, dia);
        int rh = findHeight(node->right, dia);
        
        dia = max(dia, 1 + lh + rh);
        
        return 1 + max(lh, rh);
    }
  
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(root == NULL) {
            return 0;
        }
        
        int dia = 0;
        findHeight(root, dia);
        
        return dia;
    }
};

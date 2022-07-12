class Nodevalue {
    public:
    int maxNode, minNode, maxSize;
    
    Nodevalue(int mi, int mx, int s) {
        minNode = mi;
        maxNode = mx;
        maxSize = s;
    }
};

class Solution{
    private:
    Nodevalue solve(Node* root) {
        //A empty tree is a BST pf size 0
        if(root == NULL) {
            return Nodevalue(INT_MAX, INT_MIN, 0);
        }
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        if(left.maxNode < root->data && right.minNode > root->data) {
            return Nodevalue(min(root->data, left.minNode), max(root->data, right.maxNode), 1+left.maxSize+right.maxSize);
        }
        else {
            return Nodevalue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
        }
    }
    
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	return solve(root).maxSize;
    }
};

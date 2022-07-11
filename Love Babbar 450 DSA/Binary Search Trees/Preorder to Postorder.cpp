class Solution{
public:
    //Function that constructs BST from its preorder traversal.
    Node *build_tree(int pre[], int i, int n) {
        if(i > n) {
            return NULL;
        }
        
        Node *node = newNode(pre[i]);
        int j;
        for(j = i+1; j <= n; j++) {
            if(pre[j] < pre[i]) {
                continue;
            }
            else {
                break;
            }
        }
        
        // cout << j << endl;
        
        node->left = build_tree(pre, i+1, j-1);
        node->right = build_tree(pre, j, n);
        
        return node;
    }
    
    Node* post_order(int pre[], int size)
    {
        if(size == 0) {
            return NULL;
        }
        
        return build_tree(pre, 0, size-1);
    }
};

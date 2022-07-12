void countNode(struct Node* root, int& n) {
    if(root == NULL) {
        return ;
    }
    countNode(root->left, n);
    n++;
    countNode(root->right, n);
}

void getKNode(struct Node* root, int& i, int k, int& node) {
    if(root == NULL) {
        return ;
    }
    
    if(i == k) {
        return ;
    }
    
    getKNode(root->left, i, k, node);
    i++;
    if(i == k) {
        node = root->data;
        return ;
    }
    getKNode(root->right, i, k, node);
}

float findMedian(struct Node *root)
{
    int n = 0;
    
    countNode(root, n);
    
    if(n % 2 != 0) {
        int k = (n+1)/2;
        int i = 0, node;
        getKNode(root, i, k, node);
        
        return node * 1.0;
    }
    else {
        int k1 = n/2;
        int k2 = k1+1, i = 0, node1, node2;
        getKNode(root, i, k1, node1);
        i = 0;
        getKNode(root, i, k2, node2);
        
        float ans = (node1 + node2) * 1.0;
        return ans/2.0;
    }
}

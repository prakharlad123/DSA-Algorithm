void inorder(Node* root, vector<int>& in) {
    if(root == NULL) {
        return;
    }
    
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node* build_tree(vector<int>& in, int start, int end) {
    if(start > end) {
        return NULL;
    }
    
    int mid = start + (end-start)/2;
    
    Node *node = new Node(in[mid]);
    node->left = build_tree(in, start, mid-1);
    node->right = build_tree(in, mid+1, end);
    
    return node;
}

Node* buildBalancedTree(Node* root) {
	vector<int> in;
	
	inorder(root, in);
	
	Node *new_root = build_tree(in, 0, in.size()-1);
	
	return new_root;
}

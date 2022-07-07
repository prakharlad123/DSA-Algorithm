Node* build_tree(int post[], int ps, int pe, int in[], int is, int ie, map<int, int>& mp) {
    if(is > ie || ps > pe)
        return NULL;
    
    Node* root = new Node(post[pe]);
    int ind = mp[post[pe]];
    int num_left = ind - is;
    
    root->left = build_tree(post, ps, ps+num_left-1, in, is, ind-1, mp);
    root->right = build_tree(post, ps+num_left, pe-1, in, ind+1, ie, mp);
    
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    map<int, int> mp;
    
    for(int i = 0; i < n; i++) {
        mp[in[i]] = i;
    }
    
    return build_tree(post, 0, n-1, in, 0, n-1, mp);
}

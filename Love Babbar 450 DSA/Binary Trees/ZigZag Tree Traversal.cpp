class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root) {
    	vector<int> ans;
    	
    	if(root == NULL) {
    	    return ans;
    	}
    	
    	queue<Node*> q;
    	q.push(root);
    	bool flag = true;
    	while(!q.empty()) {
    	    int size = q.size();
    	    vector<int> level(size);
    	    for(int i = 0; i < size; i++) {
    	        int ind = flag ? i : size-i-1;
    	        Node *tmp = q.front();
    	        q.pop();
    	        
    	        if(tmp->left) {
    	            q.push(tmp->left);
    	        }
    	        
    	        if(tmp->right) {
    	            q.push(tmp->right);
    	        }
    	        
    	        level[ind] = tmp->data;
    	    }
    	    
    	    for(auto& it : level) {
    	        ans.push_back(it);
    	    }
    	    
    	    flag = !flag;
    	}
    	
    	return ans;
    }
};

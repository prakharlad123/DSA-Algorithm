class Solution {
public:
    bool isLeaf(Node *node) {
        if(node->left != NULL || node->right != NULL) {
            return false;
        }
        
        return true;
    }
    
    void addLeftBoundary(Node *root, vector<int>& res) {
        Node *cur = root->left;
        
        while(cur) {
            if(!isLeaf(cur)) {
                res.push_back(cur->data);
            }
            
            if(cur->left) {
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }
    }
    
    void addLeaves(Node *root, vector<int>& res) {
        if(isLeaf(root)) {
            res.push_back(root->data);
            return ;
        }
        
        if(root->left) {
            addLeaves(root->left, res);
        }
        
        if(root->right) {
            addLeaves(root->right, res);
        }
    }
    
    void addRightBoundary(Node *root, vector<int> &res) {
        vector<int> r;
        
        Node *cur = root->right;
        
        while(cur) {
            if(!isLeaf(cur)) {
                r.push_back(cur->data);
            }
            
            if(cur->right) {
                cur = cur->right;
            }
            else {
                cur = cur->left;
            }
        }
        
        for(int i = r.size()-1; i>=0; i--) {
            res.push_back(r[i]);
        }
    }

    vector<int> boundary(Node *root) {
        vector<int> res;
        
        if(root == NULL) {
            return res;
        }
        
        if(!isLeaf(root)) {
            res.push_back(root->data);
        }
        
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        
        return res;
    }
};

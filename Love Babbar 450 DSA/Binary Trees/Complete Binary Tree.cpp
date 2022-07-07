class Solution{
public:    
    bool isCompleteBT(Node* root){
        if(root == NULL) {
            return true;
        }
        
        bool end = false;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();
            
            if(cur == NULL) {
                end = true;
            }
            else {
                if(end) {
                    return false;
                }
                
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        
        return true;
        
    }
};

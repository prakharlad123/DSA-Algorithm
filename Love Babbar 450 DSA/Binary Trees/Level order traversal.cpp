class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node) {
        vector<int> level;
        
        if(node == NULL) {
            return level;
        }
        
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                Node *temp = q.front();
                q.pop();
                level.push_back(temp->data);
                
                if(temp->left) {
                    q.push(temp->left);
                }
                
                if(temp->right) {
                    q.push(temp->right);
                }
            }
        }
        
        return level;
    }
};

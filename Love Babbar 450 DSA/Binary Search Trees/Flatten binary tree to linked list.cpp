class Solution
{
    public:
    void flatten(Node *root)
    {
        if(root == NULL) {
            return ;
        }
        
        stack<Node*> st;
        
        st.push(root);
        
        while(!st.empty()) {
            Node *cur = st.top();
            st.pop();
            
            if(cur->right) {
                st.push(cur->right);
            }
            
            if(cur->left) {
                st.push(cur->left);
            }
            
            if(!st.empty()) {
                cur->right = st.top();
            }
            
            cur->left = NULL;
        }
    }
};

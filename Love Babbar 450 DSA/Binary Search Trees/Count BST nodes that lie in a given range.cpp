class Solution{
public:
    void countNode(Node* root, int& count, int l, int h) {
        if(root == NULL) {
            return ;
        }
        
        if(root->data >= l && root->data <= h) {
            count++;
        }
        
        countNode(root->left, count, l, h);
        countNode(root->right, count, l, h);
    }

    int getCount(Node *root, int l, int h) {
        int count = 0;
        
        countNode(root, count, l, h);
        
        return count;
    }
};

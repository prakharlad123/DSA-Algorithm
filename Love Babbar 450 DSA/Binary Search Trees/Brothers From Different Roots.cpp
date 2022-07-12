class Solution
{
public:
    bool find_node(Node* root2, int f) {
        if(root2 == NULL) {
            return false;
        }
        
        if(root2->data == f) {
            return true;
        }
        
        if(root2->data > f) {
            return find_node(root2->left, f);
        }
        else {
            return find_node(root2->right, f);
        }
    }

    void inorder(Node* root1, Node* root2, int &count, int x) {
        if(root1 == NULL) {
            return ;
        }
        
        int f = x - root1->data;
        if(f < 0) {
            inorder(root1->left, root2, count, x);
        }
        else {
            if(find_node(root2, f)) {
                count++;
            }    
            inorder(root1->left, root2, count, x);
            inorder(root1->right, root2, count, x);
        }
    }

    int countPairs(Node* root1, Node* root2, int x) {
        int count  = 0;
        inorder(root1, root2, count, x);
        
        return count;
    }
};

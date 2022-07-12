struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    
    
    Node* insert(Node* root, int data, Node*& suc) {
        if(root == NULL) {
            Node* node = new Node(data);
            return node;
        }
        
        if(root->data > data) {
            suc = root;
            root->left = insert(root->left, data, suc);
        }
        else if(root->data <= data) {
            root->right = insert(root->right, data, suc);
        }
        
        return root;
    }
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        Node* root = NULL;
        
        for(int i = n-1; i>=0; i--) {
            Node *suc = NULL;
            root = insert(root, arr[i], suc);
            
            if(suc) {
                arr[i] = suc->data;
            }
            else {
                arr[i] = -1;
            }
        }
        
        return arr;
    }
};

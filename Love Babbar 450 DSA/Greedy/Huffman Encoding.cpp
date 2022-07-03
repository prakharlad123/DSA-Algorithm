class Solution
{
	public:
	    struct Node {
	        int data;
	        Node *left;
	        Node *right;
	        
	        Node(int val) {
	            this->data = val;
	            this->left = NULL;
	            this->right = NULL;
	        }
	    };
	    
	    struct cmp {
	        bool operator()(Node *l, Node* r) {
	            return (l->data > r->data);
	        }
	    };
	    
	    void preorder(Node* root, string s, vector<string>& ans) {
	        if(root == NULL) {
	            return;
	        }
	        
	        if(root->left == NULL && root->right == NULL) {
	            ans.push_back(s);
	        }
	        
	        preorder(root->left, s + '0', ans);
	        preorder(root->right, s + '1', ans);
	    }
	
		vector<string> huffmanCodes(string S,vector<int> f,int n) {
		    // creating a min heap to store all the node of the huffman tree
		    priority_queue<Node*, vector<Node*>, cmp> q;  
		    
		    // creating all the node a leaf node
		    for(int i = 0; i < n; i++) {
		        Node *temp = new Node(f[i]);
		        q.push(temp);
		    }
		    
		    while(q.size() != 1) {
		        Node *left = q.top();
		        q.pop();
		        Node *right = q.top();
		        q.pop();
		        
		        Node *parent = new Node(left->data + right->data);
		        parent->left = left;
		        parent->right = right;
		        q.push(parent);
		    }
		    
		    Node *root = q.top();
		    q.pop();
		    vector<string> ans;
		    preorder(root, "", ans);
		    
		    return ans;
		}
};

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        Node *prev = NULL, *cur = head, *nex = head->next;
        
        while(cur != NULL) {
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        
        int carry = 1, sum = 0;
        
        cur = prev, nex = NULL;
        
        while(prev != NULL) {
            nex = prev;
            sum = carry + prev->data; 
            prev->data = sum%10;
            prev = prev->next;
            
            carry = sum/10;
        }
        
        while(carry > 0) {
            Node *node = new Node(carry%10);
            nex->next = node;
            nex = node;
            carry /= 10;
        }
        
        prev = NULL, nex = cur->next;
        
        while(cur != NULL) {
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        
        return prev;
    }
};

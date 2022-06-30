class Solution
{
    public:
    int length(struct node* head) {
        int len = 0;
        while(head) {
            len++;
            head = head->next;
        }
        
        return len;
    }
    
    struct node *reverse (struct node *head, int k) { 
        if(head == NULL || k == 1) {
            return head;
        } 
        
        int len = length(head);
        struct node *dummy = new struct node(0);
        dummy->next = head;
        
        struct node *prev = dummy, *cur = dummy, *nex = dummy;
        
        while(len > 0) {
            cur = prev->next;
            nex = cur->next;
            for(int i = 1; i < min(k, len); i++) {
                cur->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = cur->next;
            }
            prev = cur;
            len -= k;
        }
        
        return dummy->next;
    }
};

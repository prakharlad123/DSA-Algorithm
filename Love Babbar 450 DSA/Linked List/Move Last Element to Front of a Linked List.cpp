class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode *prev_last = head;
        
        while(prev_last->next->next != NULL) {
            prev_last = prev_last->next;
        }
        
        int v = prev_last->next->val;
        prev_last->next = NULL;
        
        ListNode *node = new ListNode(v);
        
        node->next = head;
        
        return node;
        
    }
};

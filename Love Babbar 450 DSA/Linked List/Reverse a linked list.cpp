class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        struct Node *prev = NULL, *cur = head, *nex = head->next;
        
        while(cur != NULL) {
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        
        return prev;
    }
    
};

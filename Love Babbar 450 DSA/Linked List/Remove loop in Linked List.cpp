class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node *slow = head, *fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow) {
                break;
            }
        }
        
        if(fast == NULL || fast->next == NULL) {
            // no cycle
            return;
        }
        
        //find the entry point
        fast = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        while(fast->next != slow) {
            fast = fast->next;
        }
        
        fast->next = NULL;
    }
};

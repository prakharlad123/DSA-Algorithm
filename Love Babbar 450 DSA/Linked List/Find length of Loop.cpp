int countNodesinLoop(struct Node *head)
{
    struct Node *slow = head, *fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) {
            break;
        }
    }
    
    if(fast == NULL || fast->next == NULL) {
        return 0;
    }
    
    fast = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    int len = 1;
    
    while(fast->next != slow) {
        len++;
        fast = fast->next;
    }
    
    return len;
}

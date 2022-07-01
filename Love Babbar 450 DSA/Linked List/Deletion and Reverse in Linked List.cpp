/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key) {
    struct Node *prev = *head;
    struct Node *cur = prev->next;
    
    while(cur->data != key) {
        prev = cur;
        cur = cur->next;
    }
    
    prev->next = cur->next;
    delete cur;
}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref) {
    struct Node *tmp = *head_ref;
    if(tmp == NULL || tmp->next == tmp) {
        return ;
    }
    
    struct Node *cur = *head_ref, *prev = NULL, *nex = cur->next;
    
    while(cur->next != tmp) {
        nex = cur ->next;
        cur->next = prev;
        prev = cur;
        cur = nex;
    }
    cur->next = prev;
    prev = cur;
    
    tmp->next = prev;
    
    *head_ref = prev;
    
}

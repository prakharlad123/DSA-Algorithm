Node* reverse(Node *head) {
    Node *prev = NULL, *cur = head, *nex = cur->next;
    
    while(cur) {
        nex = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nex;
    }
    
    return prev;
}

int getNthFromLast(Node *head, int n) {
    if(head == NULL || n == 0) return -1;
    
    Node *rev = reverse(head);
    
    for(int i = 1; i < n && rev != NULL; i++) {
        rev = rev->next;
    }
    
    if(rev == NULL) return -1;
    
    return rev->data;
}

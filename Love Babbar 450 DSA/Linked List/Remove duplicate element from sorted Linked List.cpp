Node *removeDuplicates(Node *head) {
    Node *dummy = new Node(0);
    
    dummy->next = head;
    
    while(head != NULL) {
        if(head->next != NULL && head->data == head->next->data) {
            head->next = head->next->next;
        }
        else {
            head = head->next;
        }
    }
    
    return dummy->next;
}

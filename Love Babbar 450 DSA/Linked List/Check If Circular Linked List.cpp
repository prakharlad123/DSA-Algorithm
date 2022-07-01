bool isCircular(struct Node *head){
    if(head == NULL || head->next == NULL) {
        return false;
    }
    
    struct Node* tmp = head->next;
    
    while(true) {
        if(tmp == head) {
            return true;
        }
        else if(tmp == NULL) {
            return false;
        }
        
        tmp = tmp->next;
    }
}

int length(Node* head) {
    int len  = 0;
    
    while(head != NULL) {
        len++;
        head = head->next;
    }
    
    return len;
}

int intersectPoint(Node* head1, Node* head2)
{
    if(head1 == NULL || head2 == NULL) {
        return -1;
    }
    
    int len1 = length(head1);
    int len2 = length(head2);
    
    Node *p = head1, *q = head2;
    
    if(len1 > len2) {
        while(len1 > len2) {
            p = p->next;
            len1--;
        }
    }
    else {
        while(len2 > len1) {
            q = q->next;
            len2--;
        }
    }
    
    while(p != NULL && q != NULL) {
        if(p == q) {
            return p->data;
        }
        
        p = p -> next;
        q = q -> next;
    }
    
    return -1;
}

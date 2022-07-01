Node* reverseDLL(Node * head)
{
    Node *cur = head, *prev = NULL, *nex = cur->next;
    
    while(cur != NULL) {
        nex = cur->next;
        cur->next = prev;
        cur->prev= nex; //line that we have to add
        prev= cur;
        cur = nex;
    }
    
    return prev;
    
}

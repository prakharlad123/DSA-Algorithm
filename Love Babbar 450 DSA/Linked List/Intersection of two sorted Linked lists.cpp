Node* findIntersection(Node* head1, Node* head2)
{
    Node* head = new Node(0);
    Node* temp = head;
    
    while(head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data) {
            head1 = head1->next;
        }
        else if(head2->data < head1->data) {
            head2 = head2->next;
        }
        else if(head1->data == head2->data) {
            Node* node = new Node(head1->data);
            temp->next = node;
            temp = node;
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    
    return head->next;
}

class Solution{
  public:
    Node *merge(Node* l1, Node* l2) {
        if(l1==NULL) {
            return l2;
        }
        
        if(l2==NULL) {
            return l1;
        }
        
        if(l1->data > l2->data) {
            l2->next = merge(l1,l2->next);
            return l2;
        }
        else {
            l1->next = merge(l1->next,l2);
            return l1;
        }
    }
        
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(head==NULL || head->next==NULL) return head;
        
        Node *temp = NULL;
        Node *slow = head;
        Node *fast = head;
        
        while(fast && fast -> next)
        {
            temp = slow;
            slow = slow->next;          
            fast = fast ->next ->next;  
            
        }   
        temp -> next = NULL;  
        Node *l1 = mergeSort(head);
        Node *l2 = mergeSort(slow);
        return merge(l1,l2);
    }
};

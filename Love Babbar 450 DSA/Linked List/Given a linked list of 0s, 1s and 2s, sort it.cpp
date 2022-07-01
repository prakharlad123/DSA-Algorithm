class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        int zero = 0, one = 0, two = 0;
        Node *tmp = head;
        
        while(tmp != NULL) {
            if(tmp->data == 0) {
                zero++;
            }
            else if(tmp->data == 1) {
                one++;
            }
            else {
                two++;
            }
            tmp = tmp->next;
        }
        
        tmp = head;
        while(zero--) {
            tmp->data = 0;
            tmp = tmp->next;
        }
        
        while(one--) {
            tmp->data = 1;
            tmp = tmp->next;
        }
        
        while(two--) {
            tmp->data = 2;
            tmp = tmp->next;
        }
        
        return head;
    }
};

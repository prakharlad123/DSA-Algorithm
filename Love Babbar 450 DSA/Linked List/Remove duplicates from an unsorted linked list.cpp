class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_set<int> st;
     
        Node *p = head;
     
        while(p != NULL) {
            st.insert(p->data);
            p = p -> next;
        }
        
        Node* cur = head;
        Node* prev = NULL;
        
        while(cur != NULL) {
            if(st.find(cur->data) != st.end()) {
                st.erase(st.find(cur->data));
                prev = cur;
            }
            else {
                Node* temp = cur;
                prev -> next = temp -> next;
                delete temp;
            }
         
            cur = cur -> next;
        }
     
        return head;
    }
};

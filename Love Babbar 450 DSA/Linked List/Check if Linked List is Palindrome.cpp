class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        long long num = 0;
        
        Node *tmp = head;
        
        while(tmp != NULL) {
            num = (num * 10) + tmp->data;
            tmp = tmp->next;
        }
        
        tmp = head;
        while(num) {
            int rem = num %10;
            
            if(tmp->data != rem) {
                return false;
            }
            
            num /= 10;
            tmp = tmp->next;
        }
        
        return true;
    }
};

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // Read the GFG question carefully.
        // It is already given that doubly linbked list is sorted.
        
        vector<pair<int, int>> ans;
        Node *start = head, *end = head;
        
        while(end->next != NULL) {
            end = end->next;
        }
        
        while(start->prev != end && start != end) {
            if(start->data + end->data == target) {
                ans.push_back({start->data, end->data});
                start = start ->next;
                end = end->prev;
            }
            else if(start->data + end->data < target) {
                start = start->next;
            }
            else {
                end = end->prev;
            }
            
        }
        
        return ans;
    }
};

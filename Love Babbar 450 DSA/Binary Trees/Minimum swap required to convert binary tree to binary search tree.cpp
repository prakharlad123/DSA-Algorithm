class Solution{
  public:
    void inorder(vector<int>& A, vector<int>& in, int i, int n) {
        if(i >= n) {
            return ;
        }
        
        inorder(A, in, 2*i+1, n);
        in.push_back(A[i]);
        inorder(A, in, 2*i+2, n);
    }
  
    int minSwaps(vector<int>&A, int n){
        vector<int> in;
        int i = 0;
        inorder(A, in, i, n);
        
        vector<pair<int, int>> arr;
        
        for(int i = 0; i<n; i++) {
            arr.push_back({in[i], i});
        }
        
        stable_sort(arr.begin(), arr.end());
        int swaps = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i].second == i) {
                continue;
            }
            else {
                swaps++;
                swap(arr[i], arr[arr[i].second]);
                i--;
            }
        }
        
        return swaps;
    }
    
    
};

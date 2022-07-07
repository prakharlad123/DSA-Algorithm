class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int, stack<int>> edge;
        
        for(int i = 0; i < 2*e; i+=2) {
            edge[A[i]].push(A[i+1]);
        }
        
        for(int i = 0; i < 2*e; i+=2)  {
            if(edge[B[i]].top() != B[i+1]) {
                return 0;
            }
            edge[B[i]].pop();
        }
        
        return 1;
    }
};

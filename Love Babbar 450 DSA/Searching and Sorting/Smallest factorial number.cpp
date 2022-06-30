class Solution
{
    public:
        bool isValid(int mid, int n) {
            int count = 0, d = 5;
            
            while(d <= mid) {
                count += (mid/d);
                d = d * 5;
            }
            
            return count >= n;
        }
        
        int findNum(int n) {
            if(n == 1) {
                return 5;
            }
            
            int low = 0, high = 5*n;
            
            while(low < high) {
                int mid = low + (high - low)/2;
                if(isValid(mid, n)) {
                    high = mid;
                }
                else {
                    low = mid+1;
                }
            }
            
            return low;
        }
};

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(Item &a, Item &b) {
        return 1.0*a.value/a.weight > 1.0*b.value/b.weight;
    }
    
    
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr+n, cmp);
        double ans = 0;
        
        for(int i = 0; i < n; i++) {
            ans += 1.0 * min(arr[i].weight, W)/arr[i].weight * arr[i].value;
            W -= min(arr[i].weight, W);
        }
        
        return ans;
    }
        
};

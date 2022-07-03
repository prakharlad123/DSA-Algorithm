class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K) {
        int can = 0, num = 0;
        
        while(num < N) {
            can++;
            num += (1 + K);
        }
        
        sort(candies, candies + N);
        int min_cost = 0, max_cost = 0, i = 0, j = N-1;
        
        while(can) {
            can--;
            min_cost += candies[i];
            i++;
            max_cost += candies[j];
            j--;
        }
        
        return {min_cost, max_cost};
    }
};

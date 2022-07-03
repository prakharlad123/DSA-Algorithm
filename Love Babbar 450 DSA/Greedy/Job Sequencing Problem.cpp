class Solution 
{
    public:
    static bool cmp(Job a, Job b) {
        return a.profit > b.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
       sort(arr, arr+n, cmp);
       
       int maxDead = arr[0].dead;
       for(int i = 1; i < n; i++) {
           maxDead = max(maxDead, arr[i].dead);
       }
       
       vector<int> days(maxDead+1, -1);
       
       int jobs = 0, jobProfit = 0;
       
       for(int i = 0; i < n; i++) {
           if(days[arr[i].dead] == -1) {
               jobProfit += arr[i].profit;
               jobs++;
               days[arr[i].dead] = 1;
           }
           else{
               for(int j = arr[i].dead-1; j >= 1; j--) {
                   if(days[j] == -1) {
                       jobProfit += arr[i].profit;
                       jobs++;
                       days[j] = 1;
                       break;
                   }
               }
           }
       }
       
       return {jobs, jobProfit};
    } 
};

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> ans;
        vector<pair<int, int>> jobs;
        int maxDead = 0;
        
        for(int i = 0; i < n; i++) {
            maxDead = max(maxDead, arr[i].dead);
            jobs.push_back({arr[i].profit, arr[i].dead});
        }
        
        sort(jobs.begin(), jobs.end());
        reverse(jobs.begin(), jobs.end());
        vector<bool> comp(maxDead, false);
        int profit = 0, comp_jobs = 0;
        
        for(int i = 0; i < n; i++) {
            int d = jobs[i].second;
            if(comp[d-1] == false) {
                comp[d-1] = true;
                comp_jobs++;
                profit += jobs[i].first;
            }
            else {
                for(int j = d-2; j >= 0; j--) {
                    if(comp[j] == false) {
                        comp[j] = true;
                        comp_jobs++;
                        profit += jobs[i].first;
                        break;
                    }
                }
            }
        }
        
        ans.push_back(comp_jobs);
        ans.push_back(profit);
        
        return ans;
    } 
};

class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n) {
        vector<pair<int, int>> act;
        
        for(int i = 0; i < n; i++) {
            act.push_back({start[i], end[i]});
        }
        
        sort(act.begin(), act.end(), cmp);
        int take = 1, endAct = act[0].second;
        
        for(int i = 1; i < n; i++) {
            if(act[i].first > endAct) {
                take++;
                endAct = act[i].second;
            }
        }
        
        return take;
    }
};

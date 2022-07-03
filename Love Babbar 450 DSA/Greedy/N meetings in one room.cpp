class Solution
{
    public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int>> meeting;
        
        for(int i = 0; i < n; i++) {
            meeting.push_back({start[i], end[i]});
        }
        
        sort(meeting.begin(), meeting.end(), cmp);
        int count = 0;
        int endMeeting = -1;
        for(int i = 0; i < n; i++) {
            if(endMeeting < meeting[i].first) {
                count++;
                endMeeting  = meeting[i].second;
            }
        }
        
        return count;
        
    }
};

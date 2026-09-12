class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> temp;
        for(int i=0;i<intervals.size();i++){
            temp.push_back({intervals[i][1],intervals[i][0]});

        }
        sort(temp.begin(),temp.end());
        int j=0;
        int ans=0;
        for(int i=1;i<temp.size();i++){
            if(temp[i].second<temp[j].first){
                ans++;
            }
            else {
                j=i;
            }
        }
        return ans;
    }
};
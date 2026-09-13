class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>> temp;
        for(int i=0;i<intervals.size();i++){
            temp.push_back({intervals[i][0],intervals[i][1]});
        }
        sort(temp.begin(),temp.end());
        vector<vector<int>> ans;
        for(int i=0;i<temp.size();i++){
            vector<int> gec;
            gec.push_back(temp[i].first);
            int ct=temp[i].second;
            while(i<temp.size()-1&&ct>=temp[i+1].first){
                i++;
                if(ct<temp[i].second)ct=temp[i].second;
            }
            gec.push_back(ct);
            ans.push_back(gec);
        }
    return ans;
    }
};
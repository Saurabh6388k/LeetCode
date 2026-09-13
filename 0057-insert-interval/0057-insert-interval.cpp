class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newinterval) {
        int j=0;
        if(intervals.size()==0)return {newinterval};
        vector<vector<int>> ans;
        
        if(newinterval[1]<intervals[0][0]){
            ans.push_back(newinterval);
            for(int i=0;i<intervals.size();i++){
                ans.push_back(intervals[i]);
            }
            return ans;

        }
        for(int i=0;i<intervals.size();i++){

            if(newinterval[0]>intervals[i][1]){
                ans.push_back({intervals[i][0],intervals[i][1]});
                if(i==intervals.size()-1)ans.push_back(newinterval);
                else if(newinterval[1]<intervals[i+1][0]){
                    ans.push_back(newinterval);
                    newinterval[0]=intervals[i+1][0];
                    newinterval[1]=intervals[i+1][1];

                }
            }
            else {
                vector<int> temp;
                if(intervals[i][0]<newinterval[0])temp.push_back(intervals[i][0]);else temp.push_back(newinterval[0]);
                if(i==intervals.size()-1){
                    if(newinterval[1]>intervals[i][1])
                    temp.push_back(newinterval[1]);
                    else temp.push_back(intervals[i][1]);
                    ans.push_back(temp);
                    break;
                }
                while(newinterval[1]>intervals[i][1]){
                    if(i<intervals.size()-1&&intervals[i+1][0]<=newinterval[1])
                    i++;
                    else {
                        temp.push_back(newinterval[1]);
                        if(i!=intervals.size()-1){
                        newinterval[0]=intervals[i+1][0];
                        newinterval[1]=intervals[i+1][1];
                        }
                        break;
                    }
                }
                if(temp.size()<2){
                if(i==intervals.size())temp.push_back(newinterval[1]);
                else if(i==intervals.size()-1)temp.push_back(intervals[i][1]);
                else if(intervals[i][1]>=intervals[i+1][0]){
                    while(i<intervals.size()-1&&intervals[i][1]>=intervals[i+1][0])i++;
                    if(i==intervals.size()-1){
                        if(intervals[i-1][1]>intervals[i][1])temp.push_back(intervals[i-1][1]);
                        else temp.push_back(intervals[i][1]);

                    }
                    else {
                        temp.push_back(intervals[i][1]);
                        newinterval[0]=intervals[i+1][0];
                        newinterval[1]=intervals[i+1][1];
                    }


                }
                else {
                    temp.push_back(intervals[i][1]);
                    newinterval[0]=intervals[i+1][0];
                    newinterval[1]=intervals[i+1][1];
                }
                }


                ans.push_back(temp);
            }
        }
        return ans;
        
    }
};
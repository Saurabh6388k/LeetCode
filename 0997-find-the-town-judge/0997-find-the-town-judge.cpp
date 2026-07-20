class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> arr[n+1];
        vector<int> dff[n+1];
        for(int i=0;i<trust.size();i++){
            arr[trust[i][1]].push_back(trust[i][0]);
            dff[trust[i][0]].push_back(trust[i][1]);
        }
        for(int i=1;i<=n;i++){
            if(arr[i].size()==n-1&&dff[i].size()==0)return i;
        }
        return -1;
    }
};
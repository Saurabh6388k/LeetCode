class Solution {
public:
    int cst(vector<int> &cuts,int i,int j,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<=j;k++){
            mini=min(mini,cuts[j+1]-cuts[i-1]+cst(cuts,i,k-1,dp)+cst(cuts,k+1,j,dp));

        }

return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>>dp(cuts.size()+3,vector<int>(cuts.size()+3,-1));
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        return cst(cuts,1,cuts.size()-2,dp);
    }
};
class Solution {
public:
        int check(int idx,int tar,vector<vector<int>>&dp,vector<int> &coin){

            if(tar<0)return 1e9;
            if(tar==0)return 0;
            if(dp[idx][tar]!=-1)return dp[idx][tar];
            if(idx==0){
                if(tar%coin[idx]==0)return tar/coin[idx];
                else return 1e9;
            }
            int take=1e9,nottake=1e9;
            int ans;
                nottake=check(idx-1,tar,dp,coin);
               if(tar>=coin[idx]) take=1+check(idx,tar-coin[idx],dp,coin);
                ans=min(take,nottake);
              return  dp[idx][tar]=ans;

        
            
        }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans= check(coins.size()-1,amount,dp,coins);
        if(ans==1e9)return -1;
        return ans;
    }
};
class Solution {
public:
        int check(int idx,int tar,vector<vector<int>>&dp,vector<int> &coin){

            if(dp[idx][tar]!=-1)return dp[idx][tar];
            if(idx==0){
                  
                   if(tar%coin[idx]==0)return 1;
                  else return 0;
            }
            if(tar==0){
             
               return 1;

            }
            int take=0,nottake=0;
            int ans;
                nottake=check(idx-1,tar,dp,coin);
               if(tar>=coin[idx]) take=check(idx,tar-coin[idx],dp,coin);
                ans=take+nottake;
              return  dp[idx][tar]=ans;

        
            
        }
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return check(coins.size()-1,amount,dp,coins);
    }
};
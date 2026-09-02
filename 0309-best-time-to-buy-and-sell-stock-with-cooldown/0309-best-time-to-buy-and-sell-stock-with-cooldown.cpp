class Solution {
public:
    int check(vector<int>&prices,int idx,bool ch,vector<vector<int>>&dp){
            if(idx>=prices.size())return 0;
            if(dp[idx][ch]!=-1)return dp[idx][ch];

        if(ch){
            return dp[idx][ch]= max(-prices[idx]+check(prices,idx+1,0,dp),check(prices,idx+1,1,dp));
        }
        else {
            return dp[idx][ch]= max(prices[idx]+check(prices,idx+2,1,dp),check(prices,idx+1,0,dp));
        }


    }
    int maxProfit(vector<int>& prices) {
         vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return check(prices,0,1,dp);
        
    }
};
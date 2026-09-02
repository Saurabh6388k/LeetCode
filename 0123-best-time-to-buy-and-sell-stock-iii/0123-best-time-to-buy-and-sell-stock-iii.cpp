class Solution {
public:
         int check(vector<int>&prices,int idx,bool ch,vector<vector<vector<int>>>&dp,int count){
            if(count==2)return 0;
            if(idx==prices.size())return 0;
            if(dp[idx][ch][count]!=-1)return dp[idx][ch][count];

        if(ch){
            return dp[idx][ch][count]= max(-prices[idx]+check(prices,idx+1,0,dp,count),check(prices,idx+1,1,dp,count));
        }
        else {
            return dp[idx][ch][count]= max(prices[idx]+check(prices,idx+1,1,dp,count+1),check(prices,idx+1,0,dp,count));
        }


    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        return check(prices,0,1,dp,0);
    }
};
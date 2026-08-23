class Solution {
public:
        int check(int idx,int tar,vector<vector<int>>&dp,vector<int> &coin){

            if(dp[idx][tar]!=-1)return dp[idx][tar];
            if(idx==0){
                  if(tar==0){
                    if(coin[idx]==0)return 2;
                    else return 1;
                  }
                  else if(tar==coin[idx])return 1;
                  else return 0;
            }
            if(tar==0){
              if(coin[idx]==0)return 2*check(idx-1,tar,dp,coin);
              else return check(idx-1,tar,dp,coin);

            }
            int take=0,nottake=0;
            int ans;
                nottake=check(idx-1,tar,dp,coin);
               if(tar>=coin[idx]) take=check(idx-1,tar-coin[idx],dp,coin);
                ans=take+nottake;
              return  dp[idx][tar]=ans;

        
            
        }
    int findTargetSumWays(vector<int>& nums, int target) {
  
        int sum=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        long long s=sum+target;
        if(s<0)return 0;
        if(s%2!=0)return 0;
              vector<vector<int>> dp(nums.size(),vector<int>(s/2+1,-1));
        return check(nums.size()-1,s/2,dp,nums);

    }
};
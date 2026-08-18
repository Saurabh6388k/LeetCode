class Solution {
public:
        bool target(vector<int> &nums,vector<vector<int>>&dp,int tar,int i){
            
            if(tar==0)return true;

            if(i==0){
                    return nums[i]==tar;
            }
            if(dp[i][tar]!=-1)return dp[i][tar];
            bool c1,c2=false;
            c1= target(nums,dp,tar,i-1);
           if(tar>=nums[i]) c2=target(nums,dp,tar-nums[i],i-1);
            return dp[i][tar]=c1||c2;
        }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];

    }      
    if((sum)%2!=0)return false;
    vector<vector<int>> dp(nums.size(),vector<int>(sum/2+1,-1));
    return target(nums,dp,sum/2,nums.size()-1);
    }
};
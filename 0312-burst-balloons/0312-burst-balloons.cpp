class Solution {
public:
        int cst(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
            if(i>j)return 0;
            if(dp[i][j]!=-1)return dp[i][j];
           int maxi=0;
            for(int k=i;k<=j;k++){
                maxi=max(maxi,nums[i-1]*nums[k]*nums[j+1]+cst(nums,i,k-1,dp)+cst(nums,k+1,j,dp));
            }
            return dp[i][j]=maxi;
        }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return cst(nums,1,nums.size()-2,dp);
    }
};
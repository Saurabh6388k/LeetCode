class Solution {
public:
    int cst(vector<int> &arr,int i,int j,int k,vector<int>&dp){
        if(i==arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int maxi=0;
        int ct=0;
        for(int m=i;m<=min(j,i+k-1);m++){
            ct=max(ct,arr[m]);
            maxi=max(maxi,ct*(m-i+1)+cst(arr,m+1,j,k,dp));
            
        }
        return dp[i]=maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return cst(arr,0,arr.size()-1,k,dp);
    }
};
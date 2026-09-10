class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),1));
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                if(matrix[i][j]==0)dp[i][j]=0;
            }
        }
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(dp[i][j]==1){
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        int ans=0;
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};
class Solution {
public:
        
        int dfs(vector<int> arr[],int node,vector<bool> &vis,vector<bool> &pvis,int l,vector<int> &dp){
            if(dp[node]!=-1)return dp[node];
            vis[node]=true;
            pvis[node]=true;
            int temp=1;
            for(auto it : arr[node]){
                if(!pvis[it]){
                    temp=max(temp,1+dfs(arr,it,vis,pvis,l+1,dp));
                }
            }
           
            pvis[node]=0;
            return dp[node]=temp;
        }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<bool>vis(m*n,0);

        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        vector<int> arr[m*n];

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                for(int k=0;k<4;k++){
                    int cx=i+dx[k];
                    int cy=j+dy[k];
                    if(cx>=0&&cy>=0&&cx<m&&cy<n){
                        if(matrix[i][j]<matrix[cx][cy]){
                            arr[i*n+j].push_back(cx*n+cy);                       
                        }
                    }
                    
                }
            }
        }
        vector<int> dp(m*n,-1);
        int ans=1;
        for(int i=0;i<m*n;i++){
            if(!vis[i]){
                vector<bool> pvis(m*n,0);
            ans=max(ans,dfs(arr,i,vis,pvis,1,dp));
            }
        }
        return ans;
    }
};
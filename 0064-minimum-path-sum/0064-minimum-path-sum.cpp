class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

         vector<int> st(n,0);
        vector<int> curr(n,0);
        curr[0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)continue;
               int ct1=INT_MAX;
               int ct2=INT_MAX;
               if(i>0){
                ct1=st[j]+grid[i][j];
               }
               if(j>0)ct2=curr[j-1]+grid[i][j];
               
               curr[j]=min(ct1,ct2);
                
            }
            st=curr;
            
        }
        return st[n-1];
    }
};
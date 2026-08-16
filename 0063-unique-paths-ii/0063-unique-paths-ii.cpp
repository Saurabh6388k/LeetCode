class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        vector<int> st(Grid[0].size(),0);
        vector<int> curr(Grid[0].size(),0);
        int n=Grid[0].size();
        int m=Grid.size();
        if(Grid[0][0]==0)
        curr[0]=1;
        if(Grid[m-1][n-1]==1)return 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)continue;
               int ct1=0;
               int ct2=0;
               if(Grid[i][j]==1){
                curr[j]=0;
                continue;
               }
               if(i>0){
                ct1=st[j];
               }
               if(j>0)ct2=curr[j-1];
               
               curr[j]=ct1+ct2;
                
            }
            st=curr;
            
        }
        return st[n-1];
    }
};
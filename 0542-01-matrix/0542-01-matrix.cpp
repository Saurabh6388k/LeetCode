class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int col=mat[0].size();
        int row=mat.size();
        vector<bool> vis(col*row,0);
        vector<vector<int>> ans(row,vector<int>(col,0));
        queue<int> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    vis[i*col+j]=1;
                    q.push(col*i+j);
                }
            }

        }
        int dx[4]={0,0,1,-1};
        int  dy[4]={1,-1,0,0};
        while(!q.empty()){
            int ch=q.front();
            int x=ch/col;
            int y=ch%col;
            q.pop();
              
              for(int i=0;i<4;i++){
                int cx=dx[i]+x;
                int cy=dy[i]+y;
                if(cx>=0&&cy>=0&&cx<row&&cy<col&&mat[cx][cy]==1){
                    if(!vis[cx*col+cy]){
                        ans[cx][cy]=ans[x][y]+1;
                        vis[cx*col+cy]=1;
                        q.push(cx*col+cy);

                    }
                }
              }
              
            
        }
        
    return ans;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int col=grid[0].size();
        int row=grid.size();

        vector<bool> vis(row*col,0);
        queue<int> q;
        bool check=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    vis[i*col+j]=1;
                    q.push(i*col+j);

                }
                if(grid[i][j]==1){
                    check=1;
                }
            }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        if(!check)return 0;
        int k=-1;
        while(!q.empty()){
            int siz=q.size();
            while(siz--){
                 int ch=q.front();
                 q.pop();
                 int x=ch/col;
                 int y=ch%col;
                 for(int i=0;i<4;i++){
                    int cx=x+dx[i];
                    int cy=y+dy[i];
                    if(cx>=0&&cy>=0&&cx<row&&cy<col&&grid[cx][cy]==1){
                        if(!vis[cx*col+cy]){
                            vis[cx*col+cy]=1;
                            q.push(cx*col+cy);
                        }
                        
                    }
                 }

            }
            k++;
           
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    if(!vis[i*col+j])return -1;
                }
            }
        }
        return k;
    }
};
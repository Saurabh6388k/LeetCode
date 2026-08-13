class Solution {
public:
         void bfs(int node,vector<bool> &vis,vector<vector<char>>&grid,int col){
        vis[node]=true;
        int dx[4]={0,1,-1,0};
        int dy[4]={-1,0,0,1};
        int x=node/col;
        int y=node%col;


        for(int i=0;i<4;i++){
            int cx=dx[i]+x;
            int cy=dy[i]+y;
            if(cx>=0&&cy>=0&&cx<grid.size()&&cy<col&&grid[cx][cy]=='O'){
                if(!vis[cx*col+cy]){
                    bfs(cx*col+cy,vis,grid,col);
                }
            }
            
        }
    }
    void solve(vector<vector<char>>& grid) {
        vector<bool> vis(grid[0].size()*grid.size(),0);
        int c=grid[0].size();
       
            for(int i=0;i<grid[0].size();i++){
                if(grid[0][i]=='O'){

                        if(!vis[i])
                    bfs(i,vis,grid,grid[0].size());
                }
            }
                            for(int i=0;i<grid[0].size();i++){
                if(grid[grid.size()-1][i]=='O'){

                        if(!vis[c*(grid.size()-1)+i])
                    bfs((grid.size()-1)*grid[0].size()+i,vis,grid,grid[0].size());
                }
                            }
                                 for(int i=0;i<grid.size();i++){
                if(grid[i][0]=='O'){

                        if(!vis[c*i])
                    bfs(grid[0].size()*i,vis,grid,grid[0].size());
                }
                            }
                                 for(int i=0;i<grid.size();i++){
                if(grid[i][grid[0].size()-1]=='O'){

                        if(!vis[i*c+c-1])
                    bfs(i*grid[0].size()+grid[0].size()-1,vis,grid,grid[0].size());
                }
                            }
                   for(int i=0;i<grid.size();i++){
                    for(int j=0;j<grid[0].size();j++){
                        if(grid[i][j]=='X')continue;
                        if(!vis[i*grid[0].size()+j])grid[i][j]='X';
                    }
                   }         

    }
};
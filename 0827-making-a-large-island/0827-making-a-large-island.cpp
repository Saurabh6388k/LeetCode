class Solution {
public:
         class Disjoint_set{
        public:
        vector<int> parent;
        vector<int> size;
        vector<int> rank;
        Disjoint_set(int n){
            size.resize(n);
            rank.resize(n);
            parent.resize(n);

            for(int i=0;i<n;i++){
                size[i]=1;
                rank[i]=0;
                parent[i]=i;
            }
        }
            int findUpar(int node){
                if(node==parent[node])return node;
               return parent[node]= findUpar(parent[node]);
            }
            void unionbyrank(int u,int v){
                int fu=findUpar(u);
                int fv=findUpar(v);
                if(fu==fv)return;
                if(rank[fu]==rank[fv]){
                    rank[fu]++;
                    parent[fv]=fu;
                }
                else if(rank[fu]>rank[fv]){
                    parent[fv]=fu;
                }
                else if(rank[fv]>rank[fu]) {
                    parent[fu]=fv;
                }
            }
            void unionbysize(int u,int v){
                int fu=findUpar(u);
                int fv=findUpar(v);
                if(fu==fv)return;
                if(size[fu]>size[fv]){
                    parent[fv]=fu;
                    size[fu]+=size[fv];
                }
                else {
                    parent[fu]=fv;
                    size[fv]+=size[fu];
                }
            }


        };
    int largestIsland(vector<vector<int>>& grid) {
        int col=grid[0].size();
        int row=grid.size();
        queue<int> q;
        Disjoint_set ds(col*row);
        vector<bool> vis(col*row,0);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    q.push(i*col+j);
                }
            }
        }
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            int ch=q.front();
            int x=ch/col;
            int y=ch%col;
            vis[ch]=1;
            q.pop();
            for(int i=0;i<4;i++){
                int cx=x+dx[i];
                int cy=y+dy[i];
                if(cx>=0&&cy>=0&&cx<row&&cy<col){
                    if(grid[cx][cy]==1&&!vis[cx*col+cy]){
                            ds.unionbysize(ch,cx*col+cy);
                            q.push(cx*col+cy);
                    }
                }
            }
            
        }
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0){
                    unordered_map<int,bool> mp;
                    int temp=1;
                    for(int k=0;k<4;k++){
                        int x=dx[k]+i;
                        int y=dy[k]+j;
                        if(x>=0&&y>=0&&x<row&&y<col){
                            if(grid[x][y]==1){
                                if(!mp[ds.findUpar(x*col+y)]){
                                temp+=ds.size[ds.findUpar(x*col+y)];
                                mp[ds.findUpar(x*col+y)]=1;


                                }
                            }

                        }
                    }
                    ans=max(ans,temp);
                }
                else {
                    ans=max(ans,ds.size[ds.findUpar(i*col+j)]);
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int row=grid.size();
    int col=grid[0].size();
     pq.push({grid[0][0],0});
     vector<bool> vis(row*col,0);
     int dx[4]={0,0,1,-1};
     int dy[4]={1,-1,0,0};
     while(!pq.empty()){
        int ct=pq.top().first;
        int ch=pq.top().second;
        pq.pop();
        int x=ch/col;
        int y=ch%col;
        if(vis[ch])continue;
        vis[ch]=1;
        if(x==row-1&&y==col-1)return ct;
        for(int i=0;i<4;i++){
        int cx=dx[i]+x;
        int cy=dy[i]+y;
        if(cx>=0&&cy>=0&&cx<row&&cy<col){
            if(!vis[cx*col+cy]){
                if(ct>=grid[cx][cy]){
                    pq.push({ct,cx*col+cy});

                }
                else {
                    pq.push({grid[cx][cy],cx*col+cy});
                }



            }
        }
        }
     }
return -1;
    }
};
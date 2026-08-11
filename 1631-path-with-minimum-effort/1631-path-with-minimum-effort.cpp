class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
     
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int col=grid[0].size();
        pq.push({0,0});
        vector<bool> vis(col*grid.size(),0);
        int dx[4]={0,0,1,-1};
        int dy[4]={-1,1,0,0};
        int ans=0;
        
        while(!pq.empty()){
            
            int ch=pq.top().second;
            int ct=pq.top().first;

            vis[ch]=1;
            ans=max(ans,ct);
            pq.pop();
            int x=ch/col;
            int y=ch%col;
            if(x==grid.size()-1&&y==col-1)return ans;
            for(int i=0;i<4;i++){
                int cx=x+dx[i];
                int cy=y+dy[i];
                if(cx>=0&&cy>=0&&cx<grid.size()&&cy<grid[0].size()){
                    if(!vis[cx*col+cy])
                        pq.push({abs(grid[cx][cy]-grid[x][y]),cx*col+cy});

                    
                
                
                }
            }
        }
        return ans;
    }
};
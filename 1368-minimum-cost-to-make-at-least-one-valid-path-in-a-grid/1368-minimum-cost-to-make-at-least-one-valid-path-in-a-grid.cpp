class Solution {
    private : 
        int min(int a,int b){
            if(a<b)return a;
            return b;
        }
public:
    int minCost(vector<vector<int>>& grid) {
    if(grid.size()==1&&grid[0].size()==1)return 0;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};   
    vector<bool> vis(grid.size()*grid[0].size(),0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    int ans=INT_MAX;
    while(!pq.empty()){
        int ch=pq.top().second;
        int ct=pq.top().first;
        int i=ch/grid[0].size();
        int j=ch%grid[0].size();
        pq.pop();
        if(ch/grid[0].size()==(grid.size()-1)&&ch%grid[0].size()==grid[0].size()-1)return ans;
            if(vis[ch])continue;
        vis[ch]=true;
        
       
            for(int k=0;k<4;k++){
                int cx=ch/grid[0].size()+dx[k];
                int cy=ch%grid[0].size()+dy[k];
                int chk=cx*grid[0].size()+cy;
                if(cx>=0&&cy>=0&&cx<grid.size()&&cy<grid[0].size()){
                      if(!vis[cx*grid[0].size()+cy]){
                        
            
                    if(k+1==grid[i][j]){
                        pq.push({ct,chk});
                        if(chk/grid[0].size()==(grid.size()-1)&&chk%grid[0].size()==grid[0].size()-1){
                    ans=min(ans,ct);
                 
                }
                    }
                    else {
                         pq.push({ct+1,chk});
                        if(chk/grid[0].size()==(grid.size()-1)&&chk%grid[0].size()==grid[0].size()-1){
                    ans=min(ans,ct+1);

                    }

                }

                }
            
        

    }
            }
           
    }
    return ans;
    }
};
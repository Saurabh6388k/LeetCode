class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<pair<int,pair<int,int>>>pq;
        int hlt=health;
        if(grid[0][0]==1)hlt-=1;
        if(hlt<1)return false;
        pq.push({hlt,{0,0}});
        int dh[4]={-1,0,1,0};
        int fh[4]={0,-1,0,1};
        vector<vector<int>>mhlt(grid.size(),vector<int>(grid[0].size(),-1));
        while(!pq.empty()){
            int hlt=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
           
            if(i==grid.size()-1&&j==grid[0].size()-1)return true;
            for(int k=0;k<4;k++){
                int qi=dh[k]+i;
                int qj=fh[k]+j;
                if(qi>=0&&qj>=0&&qi<grid.size()&&qj<grid[0].size()){
                    if(mhlt[qi][qj]<(hlt-grid[qi][qj])){
                                   
                    if(hlt-grid[qi][qj]>0){
                        mhlt[qi][qj]=hlt-grid[qi][qj];
                    pq.push({hlt-grid[qi][qj],{qi,qj}});
                    }
                    }

                }
            }

        }
        return false;
    }
};
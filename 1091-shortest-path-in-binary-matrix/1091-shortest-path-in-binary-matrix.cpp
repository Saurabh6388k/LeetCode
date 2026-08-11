class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int arr[grid.size()][grid[0].size()];
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
            arr[i][j]=INT_MAX;
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int col=grid[0].size();
        if(grid[0][0]==1)return -1;
        pq.push({0,0});
        arr[0][0]=1;
        int dx[8]={0,0,1,1,-1,-1,-1,1};
        int dy[8]={-1,1,0,-1,0,-1,1,1};
        while(!pq.empty()){
            int ch=pq.top().second;
            int ct=pq.top().first;
            pq.pop();
            int x=ch/col;
            int y=ch%col;
            if(x==grid.size()-1&&y==col-1)return arr[x][y];
            for(int i=0;i<8;i++){
                int cx=x+dx[i];
                int cy=y+dy[i];
                if(cx>=0&&cy>=0&&cx<grid.size()&&cy<grid[0].size()){
                if(grid[cx][cy]==0){
                        
                    if(arr[x][y]+1<arr[cx][cy]){
                        arr[cx][cy]=arr[x][y]+1;
                        pq.push({arr[cx][cy],cx*col+cy});

                    }
                }
                }
            }
        }
        return -1;
    }
};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<bool> vis(image.size()*image[0].size(),0);
     queue<int> pq;
     int col=image[0].size();
     int row=image.size();
     long long temp=image[sr][sc];
     pq.push(sr*col+sc);
     image[sr][sc]=color;
     int dx[4]={0,1,-1,0};
     int dy[4]={1,0,0,-1};

     
     while(!pq.empty()){
        int ch=pq.front();
        pq.pop();
        int x=ch/col;
        int y=ch%col;
        vis[ch]=1;
        for(int i=0;i<4;i++){
            int cx=dx[i]+x;
            int cy=dy[i]+y;
            if(cx>=0&&cy>=0&&cx<row&&cy<col){
                if(image[cx][cy]==temp){
                if(!vis[cx*col+cy]){
                    image[cx][cy]=color;
                    pq.push(cx*col+cy);

                }
                }
            }
    
        }

     }


              return image;
     
    }
};
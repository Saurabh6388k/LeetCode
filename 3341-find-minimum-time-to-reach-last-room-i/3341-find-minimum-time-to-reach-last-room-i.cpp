class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
      int ch[moveTime.size()][moveTime[0].size()];
      for(int i=0;i<moveTime.size();i++){
        for(int j=0;j<moveTime[0].size();j++){
            ch[i][j]=INT_MAX;
        }
      }
        ch[0][0]=0;
        pq.push({0,{0,0}});
        int dh[4]={-1,0,1,0};
        int fh[4]={0,-1,0,1};
        while(!pq.empty()){
            int time=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==moveTime.size()-1&&j==moveTime[0].size()-1)return ch[i][j];
            for(int k=0;k<4;k++){
                int qi=dh[k]+i;
                int qj=fh[k]+j;
                if(qi>=0&&qj>=0&&qi<moveTime.size()&&qj<moveTime[0].size()){
                    if(moveTime[qi][qj]>ch[i][j]){
                    if(moveTime[qi][qj]+1<ch[qi][qj]){
                        ch[qi][qj]=moveTime[qi][qj]+1;
                        pq.push({ch[qi][qj],{qi,qj}});
                    }
                    }
                    else {
                        if(ch[i][j]+1<ch[qi][qj]){
                            ch[qi][qj]=ch[i][j]+1;
                            pq.push({ch[qi][qj],{qi,qj}});
                        }
                    }
                }
            }

        }
        return ch[moveTime.size()-1][moveTime[0].size()-1];

    }
};
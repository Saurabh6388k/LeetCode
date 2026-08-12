class Solution {

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<bool> col(n,0);
        vector<int> temp(n,-1);
        for(int i=0;i<n;i++){
           
            if(temp[i]==-1){
                 queue<int> q;
                 q.push(i);
                 temp[i]=0;
                 while(!q.empty()){
                    int ch=q.front();
                    q.pop();
                    for(int j=0;j<graph[ch].size();j++){
                        int qch=graph[ch][j];
                        if(temp[qch]==-1){
                            temp[qch]=1-temp[ch];
                            q.push(qch);

                        }
                        else if(temp[qch]==temp[ch])return false;
                        
                    }
                 }




            }
        }
       

        return true;
    }
};
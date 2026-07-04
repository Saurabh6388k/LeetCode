class Solution {
public:
            void bfs(vector<int> adj[],int val,unordered_map<int,bool> &temp){
                queue<int>has;
                has.push(val);
                while(!has.empty()){
                    int idx=has.size();
                    for(int i=0;i<idx;i++){
                        int gh=has.front();
                        has.pop();
                        temp[gh]=true;
                        for(int j=0;j<adj[gh].size();j++){
                            if(!temp[adj[gh][j]]){
                            has.push(adj[gh][j]);
                            temp[adj[gh][j]]=true;
                            }
                        }

                    }
                }
            }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        vector<int> adj[isConnected.size()+1];
        unordered_map<int,bool>temp;
        for(int i=0;i<isConnected.size();i++){
                for(int j=0;j<isConnected[i].size();j++){
                    if(isConnected[i][j]==1)adj[i+1].push_back(j+1);
                    
                }
        }
        for(int i=1;i<=isConnected.size();i++){
                if(!temp[i]){
                    bfs(adj,i,temp);
                        count++;
                }
        }
        return count;

    }
};
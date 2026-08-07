class Solution {
    private : 
            int timer=-1;
           int  dfs(vector<int> arr[],int node,vector<bool> &vis,vector<int> &mini,vector<vector<int>> &ans,int par,vector<int>&tin){
                vis[node]=true;
                tin[node]=mini[node]=++timer;

                for(int i=0;i<arr[node].size();i++){
                    if(arr[node][i]==par)continue;
                    if(vis[arr[node][i]]){
                        if(tin[arr[node][i]]<mini[node]){
                            mini[node]=tin[arr[node][i]];
                            continue;
                        }
                    }
                    else {
                        int child=dfs(arr,arr[node][i],vis,mini,ans,node,tin);
                        if(mini[child]<mini[node])mini[node]=mini[child];
                    }
                }
                if(node!=0&&tin[par]<mini[node]){
                    ans.push_back({par,node});
                }
                return node;

            }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<bool>vis(n,0);
        vector<int>mini(n,0);
        
        vector<int> arr[n];
        for(int i=0;i<connections.size();i++){
            arr[connections[i][0]].push_back(connections[i][1]);
            arr[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int>> ans;
        vector<int> tin(n,0);

          int gh=  dfs(arr,0,vis,mini,ans,0,tin);
            return ans;
    }
};
class Solution {
    private: 
            void dfs(  vector<int> arr[], vector<int> &vis,int k){

                    vis[k]=1;
                    for(int i=0;i<arr[k].size();i++){
                        if(!vis[arr[k][i]])dfs(arr,vis,arr[k][i]);
                    }
            }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
      
         vector<int> vis(n,0);
         vector<int> arr[n];
     
        for(int i=0;i<connections.size();i++){
            arr[connections[i][0]].push_back(connections[i][1]);
            arr[connections[i][1]].push_back(connections[i][0]);   
        }
        int ch=0;       
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            ch++;          
            dfs(arr,vis,i);          
        }
       
    
        return ch-1;
        
    }
};
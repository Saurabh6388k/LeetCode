class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
          vector<int> arr[n];

        for(int i=0;i<n-1;i++){
            arr[i].push_back(i+1);
        }
        vector<int> dist(n,0);
        for(int i=0;i<n;i++){
            dist[i]=i+1;
        }
        int dis=n-1;
        vector<int> ans(queries.size(),n-1);
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
                int curr=dist[u];
            if(dist[u]!=0&&dist[u]<v){
                int temp=dist[u];
                while(curr<v){
                    dist[u]=dist[curr];
                    dist[curr]=0;
                    curr=dist[u];
                    dis--;
                }
            }
        
        ans[i]=dis;
        }
        

        
        return ans; 
    }
};
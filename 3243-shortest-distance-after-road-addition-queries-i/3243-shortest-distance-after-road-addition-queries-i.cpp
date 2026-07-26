class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
      
        vector<int> arr[n];
       
        for(int i=0;i<n-1;i++){
            arr[i].push_back(i+1);
        }
        vector<int> ans(queries.size(),n-1);
        for(int i=0;i<queries.size();i++){
               queue<pair<int,int>>pq;
                vector<bool> vis(n,false);
        pq.push({0,0});
        arr[queries[i][0]].push_back(queries[i][1]);
        while(!pq.empty()){
            int stp=pq.front().first;
            int chk=pq.front().second;
            pq.pop();
            vis[chk]=true;
            if(chk==n-1){
                ans[i]=stp;
                break;
            }
            for(int k=0;k<arr[chk].size();k++){
                if(!vis[arr[chk][k]])
                pq.push({stp+1,arr[chk][k]});
            }

        }
        

        }
        return ans;
    }
};
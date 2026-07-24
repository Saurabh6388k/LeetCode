class Solution {
    private: void dfs(int par,vector<int> arr[],vector<int> &vis,int k,vector<vector<int>> &ans){
        vis[k]=1;
        for(int i=0;i<arr[k].size();i++){
            if(!vis[arr[k][i]]){
            ans[arr[k][i]].push_back(par);
            dfs(par,arr,vis,arr[k][i],ans);
            }

        }

    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> arr[n];
        for(int i=0;i<edges.size();i++){
            arr[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> vis(n,0);
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
              vector<int> vis(n,0);
            dfs(i,arr,vis,i,ans);
        }

       
        return ans;

    }
};
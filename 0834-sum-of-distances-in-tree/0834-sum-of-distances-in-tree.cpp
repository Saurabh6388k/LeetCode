class Solution {
public:
        vector<int> ans;
        vector<int> subtree;
        void dfs1(vector<int> arr[],int node,int depth,vector<bool>&vis){
            ans[0]+=depth;
            vis[node]=true;
            subtree[node]=1;
            for(auto it : arr[node]){
                if(!vis[it]){
                dfs1(arr,it,depth+1,vis);
                subtree[node]+=subtree[it];
                }
            }
        }
        void dfs2(vector<int> arr[],int n,int node,int par,vector<bool>&vis){
            vis[node]=1;
            if(node!=0){
                ans[node]=ans[par]+n-2*subtree[node];
            }
            for(auto it : arr[node]){
                if(!vis[it])
                    dfs2(arr,n,it,node,vis);
            }
        }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> arr[n];
        vector<bool> vis(n,0);
        for(int i=0;i<edges.size();i++){
            arr[edges[i][0]].push_back(edges[i][1]);
            arr[edges[i][1]].push_back(edges[i][0]);
        }
        ans.resize(n);
        subtree.resize(n);
        for(int i=0;i<n;i++){
            ans[i]=0;
            subtree[i]=0;
        }
        dfs1(arr,0,0,vis);
        for(int i=0;i<n;i++)vis[i]=false;

        dfs2(arr,n,0,0,vis);

        return ans;
        
    }
};
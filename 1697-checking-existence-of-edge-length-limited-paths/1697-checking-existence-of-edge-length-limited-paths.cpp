class Solution {
    private : 
    class Disjoint_set{
        public:
        vector<int> parent;
        vector<int> size;
        vector<int> rank;
        Disjoint_set(int n){
            size.resize(n);
            rank.resize(n);
            parent.resize(n);

            for(int i=0;i<n;i++){
                size[i]=1;
                rank[i]=0;
                parent[i]=i;
            }
        }
            int findUpar(int node){
                if(node==parent[node])return node;
               return parent[node]= findUpar(parent[node]);
            }
            void unionbyrank(int u,int v){
                int fu=findUpar(u);
                int fv=findUpar(v);
                if(fu==fv)return;
                if(rank[fu]==rank[fv]){
                    rank[fu]++;
                    parent[fv]=fu;
                }
                else if(rank[fu]>rank[fv]){
                    parent[fv]=fu;
                }
                else if(rank[fv]>rank[fu]) {
                    parent[fu]=fv;
                }
            }
            void unionbysize(int u,int v){
                int fu=findUpar(u);
                int fv=findUpar(v);
                if(fu==fv)return;
                if(size[fu]>size[fv]){
                    parent[fv]=fu;
                    size[fu]+=size[fv];
                }
                else {
                    parent[fu]=fv;
                    size[fv]+=size[fu];
                }
            }


        };
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        Disjoint_set ds(n);
        vector<vector<int>> oq;
        for(int i=0;i<queries.size();i++){
            oq.push_back({queries[i][2],queries[i][0],queries[i][1],i});
        }
        sort(oq.begin(),oq.end());
        sort(edges.begin(),edges.end(),[](auto &a,auto &b){
            return a[2]<b[2];
        });
        int j=0;
        vector<bool> ans(queries.size(),0);
        for(int i=0;i<oq.size();i++){
            int lim=oq[i][0];
            int u=oq[i][1];
            int v=oq[i][2];
            int oridx=oq[i][3];
            while(j<edges.size()&&edges[j][2]<lim){
                ds.unionbysize(edges[j][0],edges[j][1]);
                j++;
            }
            if(ds.findUpar(u)==ds.findUpar(v)){
                ans[oridx]=true;
            }
            else ans[oridx]=false;

        }
        return ans;
    }
};
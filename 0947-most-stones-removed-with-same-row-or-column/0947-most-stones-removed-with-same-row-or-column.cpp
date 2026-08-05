class Solution {
private:
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
    int removeStones(vector<vector<int>>& stones) {
       Disjoint_set ds(stones.size());
       for(int i=0;i<stones.size()-1;i++){
        for(int j=i;j<stones.size();j++){
            if(stones[i][0]==stones[j][0]){
                ds.unionbyrank(i,j);

            }
            else if(stones[i][1]==stones[j][1]){
                ds.unionbyrank(i,j);
            }

        }
       }
       int n=0;
       for(int i=0;i<stones.size();i++){
        if(ds.parent[i]==i)n++;
       }
       return stones.size()-n;


    }
};
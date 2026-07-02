class Solution {
public:
        bool ans=false;
        unordered_map<int,bool> vis;
        unordered_map<int,vector<int>>temp;
        void check(int sor,int des){
            if(vis[sor]){
                    return;
            }
            vis[sor]=true;
            if(sor==des)ans=true;
                int idx=temp[sor].size();

                for(int i=0;i<idx;i++){
                    check(temp[sor][i],des);
                }
        }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        for(int i=0;i<edges.size();i++){
            temp[edges[i][0]].push_back(edges[i][1]);
            temp[edges[i][1]].push_back(edges[i][0]);
        }
        check(source,destination);
        return ans;

    }
};
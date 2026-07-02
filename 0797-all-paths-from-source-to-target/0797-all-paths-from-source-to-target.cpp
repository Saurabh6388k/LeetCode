class Solution {
public:
            vector<int> ans;
            vector<vector<int>>has;
            void check(vector<vector<int>>& gp,int q){
                ans.push_back(q);
                for(int i=0;i<gp[q].size();i++){
                    check(gp,gp[q][i]);
                }
                if(q==gp.size()-1){
                    has.push_back(ans);
                }
                ans.pop_back();
            }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
      check(graph,0);
      return has;
    }
};
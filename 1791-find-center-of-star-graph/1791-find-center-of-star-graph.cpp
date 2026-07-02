class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int ans;
        int a,b;
        a=edges[0][0];
        b=edges[0][1];
        for(int i=1;i<edges.size();i++){
                if(edges[i][0]==a)return a;
                else if(edges[i][0]==b)return b;
                else if(edges[i][1]==a)return a;
                else return b;
        }
        return a;
    }
};
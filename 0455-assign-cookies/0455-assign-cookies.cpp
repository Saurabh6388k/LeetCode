class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0,j=0;
        int count=0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        for(;i<g.size();i++){
            if(j>=s.size())break;
            if(s[j]>=g[i]){
                count++;
                j++;
                
            }
            else {
                j++;
                i--;
            }
        }
        return count;
    }
};
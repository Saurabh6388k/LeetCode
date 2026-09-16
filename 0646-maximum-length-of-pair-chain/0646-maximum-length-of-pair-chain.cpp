class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](vector<int> a,vector<int> b){
            return b[1]>a[1];
        });
        int j=0;
        int count=1;
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]<=pairs[j][1]){
                continue;

            }
            else {
                j=i;
                count++;
            }
        }
        return count;
    }
};
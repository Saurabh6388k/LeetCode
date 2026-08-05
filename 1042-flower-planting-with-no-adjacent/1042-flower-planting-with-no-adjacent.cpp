class Solution {
public:
            
       
    vector<int> gardenNoAdj(int n, vector<vector<int>>& edges) {
        vector<int>ans(n,0);   
        vector<int> arr[n+1];
        
        for(int i=0;i<edges.size();i++){
            arr[edges[i][0]].push_back(edges[i][1]);
             arr[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=1;i<=n;i++){
            vector<bool> used(5,0);
            for(auto it:arr[i]){
            if(ans[it-1]!=0)used[ans[it-1]]=true;

            }
            for(int j=1;j<5;j++){
                if(!used[j]){
                    ans[i-1]=j;
                }
            }
        }
        return ans;
     
    }
};
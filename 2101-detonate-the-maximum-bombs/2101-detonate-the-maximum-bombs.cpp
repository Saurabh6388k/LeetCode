class Solution {
public:
        int ans=1;
      void dfs(vector<int> arr[],int node,vector<bool> &vis,vector<bool>&pvis,int &num){
        vis[node]=true;
        pvis[node]=true;
        for(auto it: arr[node]){
            if(!pvis[it]){
                num++;
                pvis[it]=true;
            }
        }
        for(auto it : arr[node]){
            {
                if(!vis[it])
                dfs(arr,it,vis,pvis,num);    
        }
        if(ans<num)ans=num;
      }
      }
    int maximumDetonation(vector<vector<int>>& bombs) {
       vector<int> arr[bombs.size()];
      
       for(int i=0;i<bombs.size()-1;i++){
        for(int j=i;j<bombs.size();j++){
            long long dist= 1LL*(bombs[i][0]-bombs[j][0])*(bombs[i][0]-bombs[j][0]) + 1LL*(bombs[i][1]-bombs[j][1])*(bombs[i][1]-bombs[j][1]);
            
            if((dist<=1LL*bombs[i][2]*bombs[i][2])){
        
        arr[i].push_back(j);
            }
            if(dist<=1LL*bombs[j][2]*bombs[j][2]){
                arr[j].push_back(i);
            }
        }
       } 
       for(int i=0;i<bombs.size();i++){
        vector<bool> pvis(bombs.size(),0);
         vector<bool> vis(bombs.size(),0);

            int num=1;
            dfs(arr,i,vis,pvis,num);
       
       }
       return ans;
    }
};
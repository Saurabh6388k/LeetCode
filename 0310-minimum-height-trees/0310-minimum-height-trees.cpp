class Solution {
  public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        if(n==2)return {0,1}; 
     
       
        vector<bool> vis(n,false);
        vector<int> temp(n,0);
     
        vector<int> arr[n];
        for(int i=0;i<edges.size();i++){
            arr[edges[i][0]].push_back(edges[i][1]);
            arr[edges[i][1]].push_back(edges[i][0]);
            temp[edges[i][0]]++;
            temp[edges[i][1]]++;
        
        }
       
        queue<int> fech;
        for(int i=0;i<n;i++){
           
        if(temp[i]==1){
        fech.push(i);
        temp[i]--;
        }
        }
     
        int remain=n;
       while(remain>2){
            int sx=fech.size();
            remain-=sx;
            while(sx){
            int chk=fech.front();
            fech.pop();
            sx--;
            vis[chk]=true;
           
            for(int i=0;i<arr[chk].size();i++){
                temp[arr[chk][i]]--;
               
                if(temp[arr[chk][i]]==1){
                    if(!vis[arr[chk][i]]){
                    
                    fech.push(arr[chk][i]);
                    }
                }
            }
            }
          
       }
       vector<int> ans;
       while(!fech.empty()){
        ans.push_back(fech.front());
        fech.pop();
       }
    return ans;

    }
};
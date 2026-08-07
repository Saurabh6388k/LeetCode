class Solution {
public:
   
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pair<int,int>> arr[n];
        for(int i=0;i<edges.size();i++){
            arr[edges[i][0]].push_back({edges[i][1],edges[i][2]});
             arr[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            
        }
        int ans=-1;
        int check=INT_MAX;
        for(int i=0;i<n;i++){
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
       vector<int> dist(n,INT_MAX);
      dist[i]=0;
       pq.push({0,i});
       while(!pq.empty()){
        int ch=pq.top().second;
        int ct=pq.top().first;
        pq.pop();
        if(dist[ch]<ct)continue;
        for(auto it: arr[ch]){
           int vct=it.second;
           int vch=it.first;
            
            if(dist[vch]>dist[ch]+vct){
                dist[vch]=dist[ch]+vct;
                pq.push({dist[vch],vch});
            }



        }
       }
       int count=0;
       for(int k=0;k<n;k++){
        if(k==i)continue;
        if(distanceThreshold>=dist[k])count++;
       }
    if(count<check){
        ans=i;
        check=count;
    }
    else if(count==check){
        if(ans<i)ans=i;
    }



        }
        return ans;

    }
};
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        

       vector<pair<pair<int,int>,int>> arr[n];
       for(int i=0;i<edges.size();i++){
        arr[edges[i][0]].push_back({{edges[i][2],edges[i][3]},edges[i][1]});

       } 
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
       pq.push({0,0});
       vector<int> dist(n,INT_MAX);
       dist[0]=0;
       while(!pq.empty()){
        int tm=pq.top().first;
        int chk=pq.top().second;
        pq.pop();
        if(chk==n-1)return dist[n-1];
        for(int i=0;i<arr[chk].size();i++){
            if(dist[chk]>arr[chk][i].first.second)continue;
            else if(dist[chk]<arr[chk][i].first.first){
                if(dist[arr[chk][i].second]>arr[chk][i].first.first+1){
                dist[arr[chk][i].second]=arr[chk][i].first.first+1;
                pq.push({dist[arr[chk][i].second],arr[chk][i].second});
                }
            }
            else {

                if(dist[arr[chk][i].second]>tm+1){
                      dist[arr[chk][i].second]=tm+1;
                      pq.push({dist[arr[chk][i].second],arr[chk][i].second});
                }
            }
        }
       }
       return -1;
    }
};
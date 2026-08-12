class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> arr[n+1];
        for(int i=0;i<times.size();i++){
            arr[times[i][0]].push_back({times[i][2],times[i][1]});

        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<bool> vis(n,0);
        int ans=0;
        while(!pq.empty()){
            int ct=pq.top().first;
            int ch=pq.top().second;
                 pq.pop();
                 if(vis[ch])continue;
            vis[ch]=1;
            ans=max(ans,ct);
            for(auto it: arr[ch]){
                int qct=it.first;
                int qch=it.second;
                if(!vis[qch]){
                    pq.push({qct+ct,qch});
                }
            }
        }
              for(int i=1;i<=n;i++){
                if(!vis[i])return -1;
            }
return ans;
    }
};
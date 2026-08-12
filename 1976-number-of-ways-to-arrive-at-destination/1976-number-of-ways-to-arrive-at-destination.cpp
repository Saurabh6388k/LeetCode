class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,int>> arr[n];
        for(int i=0;i<roads.size();i++){
            arr[roads[i][0]].push_back({roads[i][2],roads[i][1]});
            arr[roads[i][1]].push_back({roads[i][2],roads[i][0]});
        }
        vector<long long> count(n,0);
        count[0]=1;
        vector<long long> dist(n,LLONG_MAX);
        dist[0]=0;
             const int MOD=1e9+7;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        q.push({0,0});
        while(!q.empty()){
            int ch=q.top().second;
            long long ct=q.top().first;
            q.pop();
            if(ct>dist[ch])continue;
            
            for(int i=0;i<arr[ch].size();i++){
                if(arr[ch][i].second==ch)continue;
                long long qct=arr[ch][i].first;
                int qch=arr[ch][i].second;
                if(ct+qct<dist[qch]){
                    count[qch]=count[ch];
                    dist[qch]=ct+qct;
                    q.push({ct+qct,qch});
                }
                else if(ct+qct==dist[qch]){
                    count[qch]=(count[qch]+count[ch])%MOD;
                }     
            }
        }
   
        return count[n-1]%MOD;
    }
};
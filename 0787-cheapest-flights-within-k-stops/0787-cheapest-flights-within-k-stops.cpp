class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int,int>> arr[100];
        for(int i=0;i<flights.size();i++){
            arr[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,src}});
        int ans=INT_MAX;
        int c=0;
        bool check=0;
        while(!q.empty()&&c<=k+1){
            int siz=q.size();
            while(siz--){
            int ct=q.front().first;
            int count=q.front().second.first;
            int ch=q.front().second.second;
            q.pop();
            if(ch==dst){
                check=true;
                ans=min(ans,ct);
                continue;
            }
            if(count>k)continue;
            for(int i=0;i<arr[ch].size();i++){
                int qch=arr[ch][i].first;
                int qct=arr[ch][i].second;
                if(ct+qct<dist[qch]){
                    dist[qch]=ct+qct;
                        q.push({ct+qct,{count+1,qch}});
                }
            }
            
            }
        
            c++;
        }
        
    if(!check)return -1;
        return ans;
    }
};
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> arr[n];
        map<pair<int,int>,bool> mp;
        vector<int> temp(n,0);
        
        for(int i=0;i<roads.size();i++){
            temp[roads[i][0]]++;
            temp[roads[i][1]]++;
            mp[{roads[i][0],roads[i][1]}]=true;
            mp[{roads[i][1],roads[i][0]}]=true;

        }
        int a=0,b=0;
        vector<int> fg;
        for(int i=0;i<n;i++){
            if(temp[a]<temp[i]){
                a=i;
            }        
        }
        fg.push_back(a);
        for(int i=0;i<n;i++){
            if(temp[a]==temp[i]){
                fg.push_back(i);
            }
        }
        for(int i=0;i<fg.size();i++){
            a=fg[i];
        for(int i=0;i<n;i++){
            
            
            if(a==b&&b!=i){
                b=i;
            }
            if(i==a)continue;
            if(temp[b]<temp[i]){
                b=i;
            }
            else if(temp[b]==temp[i]){
                if(!mp[{i,a}])b=i;
            }
        }
        if(!mp[{a,b}])break;
        }
        if(mp[{a,b}]){
            return temp[a]+temp[b]-1;
        }
        return temp[a]+temp[b];

    }
};
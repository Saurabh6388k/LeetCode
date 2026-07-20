class Solution {
    private :
            void check( vector<int> arr[], vector<bool> &vis,int k){
                for(int i=0;i<arr[k].size();i++){
                    if(!vis[arr[k][i]]){
                        vis[arr[k][i]]=true;
                        check(arr,vis,arr[k][i]);
                    }
                }

            }
public:
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> ans(rooms.size(),0);
        ans[0]=true;
        vector<int> arr[rooms.size()];
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                arr[i].push_back(rooms[i][j]);
            }
        }
        check(arr,ans,0);
        for(int i=0;i<rooms.size();i++){
            if(ans[i]==false)return false;
        }
return true;
    }
};
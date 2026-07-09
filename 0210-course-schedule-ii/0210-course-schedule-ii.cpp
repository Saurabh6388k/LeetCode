class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int> temp[numCourses];
       for(auto it: prerequisites){
        temp[it[1]].push_back(it[0]);
       }
        unordered_map<int,int>indeed;
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<temp[i].size();j++){
            indeed[temp[i][j]]++;
            }
        }
        vector<int> ans;
        queue<int>fh;
        for(int i=0;i<numCourses;i++){

        if(!indeed[i]){
        fh.push(i);
        }
        }
        while(!fh.empty()){
            int curr=fh.front();
            fh.pop();
            ans.push_back(curr);
            for(int i=0;i<temp[curr].size();i++){
                indeed[temp[curr][i]]--;
                if(!indeed[temp[curr][i]])fh.push(temp[curr][i]);
            }
        }
        
        if(ans.size()==numCourses)return ans;
        return {};
    }
};
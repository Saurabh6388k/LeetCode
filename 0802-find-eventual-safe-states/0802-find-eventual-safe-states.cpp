class Solution {
public:
   
        unordered_map<int,bool>temp;
        vector<int> ans;
        unordered_map<int,bool>gh;


        bool check(int a,vector<int> sg[]){
            vector<bool> ch(sg[a].size(),false);
    
            temp[a]=true;
            int count=0;
            for(int i=0;i<sg[a].size();i++){
                if(!temp[sg[a][i]]){
                ch[i]=check(sg[a][i],sg);
                
                }
                else if(gh[sg[a][i]])ch[i]=true;
                else ch[i]=false;
                count++;
                
            }
            bool fg=false;
            for(int i=0;i<ch.size();i++){
                if(ch[i]!=true)fg=true;
            }
            if(fg){
            
                return false;
            }
            else {
                if(!gh[a]){
                ans.push_back(a);
                gh[a]=true;
                }
                
            }
           if(count==0){
            return true;
           }

        return true;
        }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       
        vector<int> sg[graph.size()];
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){

            
            sg[i].push_back(graph[i][j]);


        }
        }
        for(int i=0;i<graph.size();i++){
            if(!temp[i])
           bool ds= check(i,sg);

        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
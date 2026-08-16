class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> ans;
        ans.push_back(triangle[0][0]);
        for(int i=1;i<triangle.size();i++){
            vector<int> temp(triangle[i].size(),0);
            for(int j=0;j<triangle[i].size();j++){
                int a=INT_MAX;
                int b=INT_MAX;
                if(j!=triangle[i].size()-1)a=min(a,ans[j]);
                if(j!=0)b=min(b,ans[j-1]);
                temp[j]=min(a,b)+triangle[i][j];
                
            }
            ans=temp;
        }
        int ans1=INT_MAX;
        for(int i=0;i<ans.size();i++){
            ans1=min(ans1,ans[i]);
        }

        return ans1;
    }
};
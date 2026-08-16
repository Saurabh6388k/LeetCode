class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp1={1};
        ans.push_back(temp1);
        for(int i=1;i<numRows;i++){
            vector<int> temp(i+1,1);
            for(int j=0;j<temp.size()-1;j++){
                if(j==0)continue;
                temp[j]=temp1[j]+temp1[j-1];
            }
            ans.push_back(temp);
            temp1=temp;

        }
        return ans;
        
        
    }
};
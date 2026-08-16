class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> temp1={1};
        if(rowIndex==0)return temp1;
        for(int i=1;i<=rowIndex;i++){
            vector<int> temp(i+1,1);
            for(int j=0;j<temp.size()-1;j++){
                if(j==0)continue;
                temp[j]=temp1[j]+temp1[j-1];
            }
            temp1=temp;
        }
        return temp1;
    }
};
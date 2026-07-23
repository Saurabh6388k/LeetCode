class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
      int arr[matrix.size()];
      for(int i=0;i<matrix.size();i++){
        arr[i]=0;
      }  
      for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix.size();j++){
            if(matrix[i][j]==1)
            arr[i]++;
        }
      }
      vector<int> ans;
      for(int i=0;i<matrix.size();i++){
        ans.push_back(arr[i]);
      }
      return ans;
    }
};
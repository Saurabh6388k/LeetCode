class Solution {
public:
    int are(vector<int> &arr){
        if(arr.size()==1)return arr[0];
        vector<int> lmin(arr.size(),0);
        vector<int>rmin(arr.size(),arr.size()-1);
        stack<int> st;
        for(int i=0;i<arr.size();i++){
           while(!st.empty()&&arr[i]<=arr[st.top()]){
            st.pop();
           }
           if(st.empty())lmin[i]=0;
           else lmin[i]=st.top()+1;

           st.push(i);

        }
        while(!st.empty())st.pop();
        for(int i=arr.size()-1;i>=0;i--){
        while(!st.empty()&&arr[i]<=arr[st.top()]){
            st.pop();
        }
        if(st.empty())rmin[i]=arr.size()-1;
        else rmin[i]=st.top()-1;

        st.push(i);

           
        }
        int ans=0;
        for(int i=0;i<arr.size();i++){
            ans=max(ans,arr[i]*(rmin[i]-lmin[i]+1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> dp(matrix[0].size(),0);
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<dp.size();j++){
                if(matrix[i][j]=='1')dp[j]++;
                else{
                    dp[j]=0;
                }
            }
            ans=max(ans,are(dp));
        }
        return ans;
    }
};
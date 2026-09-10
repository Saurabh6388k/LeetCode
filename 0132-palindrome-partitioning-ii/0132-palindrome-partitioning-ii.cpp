class Solution {
public:
        bool check(string &s,int i,int k){
            while(i<k){
                if(s[i]!=s[k])return false;
                i++;
                k--;
            }
            return true;
        }
        int cst(string &s,int i,int j,vector<int>&dp){
            if(i==s.size())return 0;
            if(dp[i]!=-1)return dp[i];
            int mini=INT_MAX;
            for(int k=i;k<=j;k++ ){
                if(check(s,i,k)){
                    mini=min(mini,1+cst(s,k+1,j,dp));
                }
            }
            return dp[i]=mini;
        }
    int minCut(string s) {
        vector<int> dp(s.size(),-1);
        return cst(s,0,s.size()-1,dp)-1;


    }
};
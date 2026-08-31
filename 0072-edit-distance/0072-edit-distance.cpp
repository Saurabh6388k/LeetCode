class Solution {
public:
        int check(string &w1,string &w2,int idx1,int idx2,vector<vector<int>> &dp){
            if(idx2<0)return idx1+1;
            if(idx1<0)return idx2+1;
              int ch1=0,ch2=0,ch3=0;
              if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
            if(w1[idx1]==w2[idx2])return dp[idx1][idx2]=check(w1,w2,idx1-1,idx2-1,dp);
            else {

            ch1=1+check(w1,w2,idx1,idx2-1,dp);
            ch2=1+check(w1,w2,idx1-1,idx2,dp);
            ch3=1+check(w1,w2,idx1-1,idx2-1,dp);
           
            }
             return dp[idx1][idx2]=min(ch1,min(ch2,ch3));
        }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return check(word1,word2,word1.size()-1,word2.size()-1,dp);
    }
};
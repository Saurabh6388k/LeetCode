class Solution {
public:
        int check(string &s,string &c,vector<vector<int>> &dp,int idx1,int idx2){
           
            if(idx1<0||idx2<0)return 0;
             
            if(idx1==0||idx2==0){
                if(s[idx1]==c[idx2])return 1;
                else return max(check(s,c,dp,idx1-1,idx2),check(s,c,dp,idx1,idx2-1));
            }
            if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
            
            int take =INT_MIN;
            int not_take1=INT_MIN;
            int not_take2=INT_MIN;
            if(s[idx1]==c[idx2]) take=1+check(s,c,dp,idx1-1,idx2-1);
            not_take1=check(s,c,dp,idx1-1,idx2);
            not_take2=check(s,c,dp,idx1,idx2-1);
           return dp[idx1][idx2]=max(take,max(not_take1,not_take2));


        }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        int cm=check(word1,word2,dp,word1.size()-1,word2.size()-1);
        return word1.size()+word2.size()-2*cm;
        
    }
};
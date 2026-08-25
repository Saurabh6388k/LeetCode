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
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        string c=s;
        for(int ch=0;ch<s.size();ch++){

            c[s.size()-1-ch]=s[ch];
            
        }
        return check(s,c,dp,s.size()-1,s.size()-1);
    }
};
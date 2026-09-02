class Solution {
public:
        bool check(string &s,string &p,int idx1,int idx2,vector<vector<int>>&dp){

            if(idx1<0&&idx2<0)return true;
           
            if(idx1<0){
                while(idx2>=0){
                    if(p[idx2--]=='*')continue;
                    else return false;
                }
                return true;
            }
            if(idx2<0)return false;
             if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];


            if(p[idx2]==s[idx1]||p[idx2]=='?')return dp[idx1][idx2]=check(s,p,idx1-1,idx2-1,dp);
            else if(p[idx2]=='*'){
                return dp[idx1][idx2]=check(s,p,idx1-1,idx2,dp)||check(s,p,idx1,idx2-1,dp);
            }
            else {
                return dp[idx1][idx2]= false;
            }
        }
    bool isMatch(string s, string p) {
        
        vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
        return check(s,p,s.size()-1,p.size()-1,dp);
    }
};
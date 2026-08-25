class Solution {
public:
    int check(string &s,string &c,vector<vector<int>> &dp,int idx1,int idx2){
           
            if(idx1<0||idx2<0)return 0;
             
            if(idx1==0||idx2==0){
                if(s[idx1]==c[idx2])return dp[idx1+1][idx2+1]=1;
                else return dp[idx1+1][idx2+1]= max(check(s,c,dp,idx1-1,idx2),check(s,c,dp,idx1,idx2-1));
            }
            if(dp[idx1+1][idx2+1]!=-1)return dp[idx1+1][idx2+1];
            
            int take =INT_MIN;
            int not_take1=INT_MIN;
            int not_take2=INT_MIN;
            if(s[idx1]==c[idx2]) take=1+check(s,c,dp,idx1-1,idx2-1);
            not_take1=check(s,c,dp,idx1-1,idx2);
            not_take2=check(s,c,dp,idx1,idx2-1);
           return dp[idx1+1][idx2+1]=max(take,max(not_take1,not_take2));


        }
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size()+1,vector<int>(str2.size()+1,-1));
        int cm=check(str1,str2,dp,str1.size()-1,str2.size()-1);
        int i=str1.size();
        int j=str2.size();
        string s="";

        while(i>0&&j>0){
        if(str1[i-1]==str2[j-1]){
            s.push_back(str1[i-1]);
            i--,j--;

        }
        else if(dp[i-1][j]>dp[i][j-1]){
            s.push_back(str1[i-1]);
            i--;
        }
        else {
            s.push_back(str2[j-1]);
            j--;
        }
        
    }
    while(i>0){
        s.push_back(str1[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(str2[j-1]);
        j--;
    }
    string ans="";
    for(int k=s.size()-1;k>=0;k--){
        ans.push_back(s[k]);
    }
    return ans;
    }

};
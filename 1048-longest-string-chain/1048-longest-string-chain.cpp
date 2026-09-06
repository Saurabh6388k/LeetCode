class Solution {
public:
        bool check(string w1,string w2){
            if(w2.size()!=w1.size()+1)return 0;
            int j=0,i=0;
            for(;i<w2.size();i++){
                if(w2[i]==w1[j]){
                    j++;
                }
            }
            if(w1.size()==j)return true;
            return false;
            
        }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size()<b.size();
        });
        vector<int> dp(words.size(),1);
        int maxi=1;
        for(int i=1;i<words.size();i++){
            for(int j=0;j<i;j++){
            if(check(words[j],words[i])&&dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
            }
            }
            maxi=max(dp[i],maxi);
        }
        return maxi;
    }
};
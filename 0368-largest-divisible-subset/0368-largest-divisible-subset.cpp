class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),1);
        vector<int> has(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            has[i]=i;
        }
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    has[i]=j;
                }
            }

        }
        vector<int> ans;
        int c=0,ch=1;
        for(int i=0;i<nums.size();i++){
            if(ch<dp[i]){
                c=i;
                ch=dp[i];
            }
        }
        while(has[c]!=c){
            ans.push_back(nums[c]);
            c=has[c];
        }
        ans.push_back(nums[c]);
        return ans;
    }
};
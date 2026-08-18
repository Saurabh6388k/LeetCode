class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1=0,prev2=0;
        int curr=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {curr=nums[i];
            int ans1,ans2;
            ans1=prev2+curr;
            ans2=prev1;
            int ch=max(ans1,ans2);
            ans=max(ans,max(ans1,ans2));
            prev2=prev1;
            prev1=ch;


            
        }
    return ans;
    }
};
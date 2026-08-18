class Solution {
public:
         int robbie(vector<int>& nums) {
            if(nums.empty())return 0;
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
    int rob(vector<int>& nums) {
        vector<int> ans1;
        vector<int> ans2;
if(nums.size()==1)return nums[0];
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                ans1.push_back(nums[i]);

            }
            if(i!=(nums.size()-1))ans2.push_back(nums[i]);
        }
        return max(robbie(ans1),robbie(ans2));
    }
};
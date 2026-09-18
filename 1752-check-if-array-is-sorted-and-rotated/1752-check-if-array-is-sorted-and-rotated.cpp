class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        bool ch=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<=nums[i]){
                continue;
            }
            else {
                while(i<n-1&&nums[i+1]>=nums[i])i++;
                if(i!=n-1)return false;
                ch=1;

            }
        }
        if(ch&&nums[n-1]>nums[0])return false;

        return true;
    }
};
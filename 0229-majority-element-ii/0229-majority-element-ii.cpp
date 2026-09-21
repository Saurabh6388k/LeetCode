class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count=0;
        vector<int> ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            for(int j=i;j<nums.size();j++){

                if(nums[j]==nums[i])count++;
            }
            if(count>(nums.size())/3) ans.push_back(nums[i]);
            count=0;



        }

    return ans;
    }
};

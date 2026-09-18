class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=1;
        for(int i=0;i<nums.size()-1;i++){
            if(j>=nums.size())break;
            if(i>=j)j=i+1;
        while(j<nums.size()-1&&nums[j]==0)j++;
        if(nums[i]==0){
            swap(nums[i],nums[j]);
            j++;
        }
        }
        
    }
};
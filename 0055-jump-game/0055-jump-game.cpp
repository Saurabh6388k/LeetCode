class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(maxi>=i){
                if(i+nums[i]>maxi)maxi=i+nums[i];
            }
            else return false;
        }
        return true;
    }
};
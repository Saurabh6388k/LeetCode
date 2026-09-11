class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0,jump=0;
        while(r<nums.size()-1){
            if(l>=nums.size()-1)return jump;
            int far=0;
            for(int i=r;i<=l;i++){
                if(i+nums[i]>far)far=i+nums[i];
            }
            r=l+1;
            l=far;
            jump++;
            
        }
        return jump;
        
    }
};
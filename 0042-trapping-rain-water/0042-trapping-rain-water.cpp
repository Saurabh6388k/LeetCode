class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>leftmax=height;
        vector<int> rightmax=height;
        leftmax[0]=0,rightmax[height.size()-1]=0;
        for(int i=1;i<height.size();i++){
            leftmax[i]=max(height[i-1],leftmax[i-1]);

        }
        for(int i=height.size()-2;i>=0;i--){
            rightmax[i]=max(height[i+1],rightmax[i+1]);

        }
        int water=0;
        for(int i=0;i<height.size();i++){
            int minheight=min(leftmax[i],rightmax[i]);
            if(minheight>=height[i]){
                water+=minheight-height[i];
            }
        }
        return water;
    }
};
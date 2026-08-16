class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        if(n==2)return 2;

        int prev=1;
        int prev1=2;
        int curr;
        for(int i=2;i<n;i++){
            curr=prev+prev1;
            prev=prev1;
            prev1=curr;

        }
        return curr;
    }
};
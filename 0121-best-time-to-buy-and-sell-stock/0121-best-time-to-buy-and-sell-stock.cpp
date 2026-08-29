class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=prices[prices.size()-1],ans=0;
        for(int i=prices.size()-2;i>=0;i--){
            if(prices[i]<=maxi){
                ans=max(ans,maxi-prices[i]);
            }
            if(maxi<prices[i])maxi=prices[i];
        }
        return ans;
        
    }
};
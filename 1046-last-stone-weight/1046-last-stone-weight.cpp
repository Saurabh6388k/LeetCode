class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>p;
        int ans=0;
        for(int i=0;i<stones.size();i++){
            p.push(stones[i]);
        }
        while(!p.empty()){
            if(p.size()==1)return p.top();
            int ft=p.top();
            p.pop();
            int sd=p.top();
            p.pop();
            if(ft==sd)continue;
            else {
                p.push(ft-sd);
            }

        }
        return ans;
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int gasi=0;
            int start=0;
            int tgas=0;
            int tcost=0;
            for(int i=0;i<gas.size();i++){
                tgas+=gas[i];
                tcost+=cost[i];
                gasi+=gas[i]-cost[i];

                if(gasi<0){
                    start=i+1;
                    gasi=0;
                }

            }

          return  (tgas<tcost) ?  -1: start;





    }
};
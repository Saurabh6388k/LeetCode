class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int> a,vector<int> b){
            return b[1]>a[1];
        });
        int count=1;
        int cst=points[0][1];
        int j=0;
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=points[j][1]){
                
                continue;
            }
            else {
                cst=points[i][1];
                j=i;
                count++;

            }
        }
        return count;
    }
};
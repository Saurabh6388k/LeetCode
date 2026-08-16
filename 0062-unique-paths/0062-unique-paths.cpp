class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> st(n,-1);
        vector<int> curr(n,-1);
        st[0]=1;
        curr[0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)continue;
               int ct1=0;
               int ct2=0;
               if(i>0){
                ct1=st[j];
               }
               if(j>0)ct2=curr[j-1];
               
               curr[j]=ct1+ct2;
                
            }
            st=curr;
            
        }
        return st[n-1];
        
    }

};
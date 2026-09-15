class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> rct(ratings.size(),1);
        vector<int> lct(ratings.size(),1);
        for(int i=1;i<ratings.size();i++){
            if(ratings[i-1]<ratings[i])lct[i]=lct[i-1]+1;

        }
    for(int i=ratings.size()-2;i>=0;i--){
        if(ratings[i+1]<ratings[i])rct[i]=rct[i+1]+1;
    }
    int ans=0;
    for(int i=0;i<ratings.size();i++){
        ans+=max(lct[i],rct[i]);
    }
return ans;

    }
};
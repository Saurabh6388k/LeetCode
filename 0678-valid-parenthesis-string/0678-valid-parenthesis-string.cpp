class Solution {
public:
    bool checkValidString(string s) {
       int mini=0;
       int maxi=0;
       for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            mini+=1;
            maxi++;
        }
        else if(s[i]==')'){
            if(mini>0)mini--;
            maxi--;
        }
        else {

            if(mini>0)mini-=1;
            maxi++;
        }


        if(maxi<0)return false;
       }


if(mini==0)return true;
return false;


    }
};
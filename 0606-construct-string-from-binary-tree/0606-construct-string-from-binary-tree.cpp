/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
        string s="";
        int arr[4]={-1,-1,-1,-1};
        void tstr(TreeNode* root,bool g){
            if(!root)return;
            if(g){
                s+="(";
            }
            if(root->val<0){
                s+="-";
                root->val=-root->val;
            }
            int num=root->val;
            int i=0;
            if(num==0){
                s+='0';
            }
            else {

            
            while(num){
                arr[i++]=num%10;
                num/=10;
            }
            for(int i=3;i>=0;i--){
                if(arr[i]>=0){
                    s+='0'+arr[i];
                }
            }
           for(int i=0;i<4;i++){
            if(arr[i]>=0)
            arr[i]=-1;

           }
            }
            
            bool id=true;
            if(!root->left&&root->right)s+="()";
            tstr(root->left,true);
            tstr(root->right,true);
            if(g){
                s+=")";
            }


        }
    string tree2str(TreeNode* root) {
        tstr(root,false);
        return s;
    }
};
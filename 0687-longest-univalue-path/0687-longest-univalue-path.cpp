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
        int maxcount=0;
        
       
        int check(TreeNode* root){
            if(!root)return 0;
            int sum=1;
            long long lsum=check(root->left);
            long long rsum=check(root->right);
         
            bool th1=0,th2=0;
            if(root->left){
           if(root->left->val==root->val){
            th1=1;
             sum=lsum+sum;

           }
            }
           if(root->right){
           if(root->right->val==root->val){
            th2=1;
            sum=sum+rsum;
           }
           }

        if(sum>maxcount)maxcount=sum;
        if(!th1)lsum=0;
        if(!th2)rsum=0;
           int ch=max(lsum,rsum);

            return ch+1;

        }
    int longestUnivaluePath(TreeNode* root) {
        if(!root)return 0;
        if(!root->left&&!root->right)return 0;

        int gt=check(root);
        return maxcount-1;
    }
};
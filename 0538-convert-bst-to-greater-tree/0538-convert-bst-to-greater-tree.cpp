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
        long long prev=INT_MAX;
        long long sum=0;

        void su(TreeNode* root){
            if(!root)return;
            su(root->right);
           if(prev==INT_MAX)sum=root->val;

           else sum=prev+root->val;
           root->val=sum;
            prev=sum;
            su(root->left);           
        }
    TreeNode* convertBST(TreeNode* root) {
        su(root);
        return root;
    }
};
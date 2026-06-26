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
        int abso=INT_MAX;
        int prev=-1;
        void diff(TreeNode* root){
            if(!root)return;
            diff(root->left);
            if(prev>=0)abso=min(abso,root->val-prev);     
            prev=root->val;
            diff(root->right);
        
        }

    int getMinimumDifference(TreeNode* root) {
        diff(root);
        return abso;
    }
};
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
        int ans,k=0;
        void check(TreeNode* root,int tar){
            if(root==NULL)return;
            check(root->left,tar);
            k++;
            if(k==tar)ans=root->val;
            check(root->right,tar);
            return;

        }
    int kthSmallest(TreeNode* root, int k) {
        check(root,k);
        return ans;
    }
};
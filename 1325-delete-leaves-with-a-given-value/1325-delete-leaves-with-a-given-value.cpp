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
        TreeNode* check(TreeNode* root,int tar){
            if(!root)return NULL;
            root->left=check(root->left,tar);
            root->right=check(root->right,tar);
            if(!root->left&&!root->right){
                if(root->val==tar)return NULL;
            }

        return root;
        }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return check(root,target);

    }
};
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
        unordered_map<TreeNode*,int>temp;
        TreeNode* fg(TreeNode* root){
            if(!root)return NULL;
            root->left=fg(root->left);
            root->right=fg(root->right);
            if(temp[root])return NULL;

            return root;

        }
        int fech(TreeNode* root){
            if(!root)return 0;
            int l=fech(root->left);
            int r=fech(root->right);
            int sum= root->val+l+r;
            if(sum==0)temp[root]++;
        return sum;
        }
    TreeNode* pruneTree(TreeNode* root) {
        int has=fech(root);
        return fg(root);
    }
};
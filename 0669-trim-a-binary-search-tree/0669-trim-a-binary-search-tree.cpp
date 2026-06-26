/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     reeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
        
    TreeNode* bt(TreeNode* root,int low,int high){
        if(!root)return NULL;
        if(root->val<low)return bt(root->right,low,high);
        if(root->val>high)return bt(root->left,low,high);

        root->left=bt(root->left,low,high);
        root->right=bt(root->right,low,high);
       
        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
       TreeNode* cur=bt(root,low,high);
       return cur;
        
    }
};
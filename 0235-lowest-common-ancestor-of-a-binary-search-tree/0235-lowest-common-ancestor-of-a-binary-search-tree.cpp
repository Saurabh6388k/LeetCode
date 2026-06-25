/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr =root;
        while(curr){
            if(curr->val>p->val&&curr->val>q->val){
                curr=curr->left;
            }
            else if(curr->val<p->val&&curr->val<q->val)curr=curr->right;
            else if(curr->val>p->val&&curr->val<q->val||curr->val>q->val&&curr->val>q->val){
                return curr;
            }
            else if(curr->val==q->val||curr->val==p->val)return curr;



        }
        return NULL;
    }
};
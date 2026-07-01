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
        TreeNode* a=NULL;
        TreeNode* b=NULL;
        TreeNode* c=NULL;
        bool dg=true;
        void check(TreeNode* root){
            if(!root)return ;

            check(root->left);

            if(c&&c->val>root->val){
                if(dg){
                        dg=false;
                a=c;
                b=root;
                }
                else {
                    b=root;
                }
            }
                 c=root;
            check(root->right);
            

        }
    void recoverTree(TreeNode* root) {
        check(root);
        swap(a->val,b->val);
    }
};
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        TreeNode* curr=root;
        TreeNode* prev=NULL;
        TreeNode* fech=NULL;
        bool fe=true;
        while(curr){
            if(curr->val<key){
                fech=curr;
                fe=true;
                curr=curr->right;
            }
            else if(curr->val>key){
                fech=curr;
                fe=false;
                curr=curr->left;
            }
            else {

                if(curr->left){
                    prev=curr->left;
                    while(prev->right)prev=prev->right;
                  
                    curr->val=prev->val;
                  
                    curr->left=deleteNode(curr->left,prev->val);
                    break;

                }
                else if(curr->right){
                    prev=curr->right;
                    while(prev->left)prev=prev->left;
                    curr->val=prev->val;
                    curr->right=deleteNode(curr->right,prev->val);
                    break;

                }
                if(!curr->left&&!curr->right){
                    delete curr;
                  
                    if(root==curr)return NULL;
                      if(fe)
                    fech->right=NULL;
                    if(!fe)fech->left=NULL;
                   
                }
                 break;

            }
        }


        return root;
    }
};
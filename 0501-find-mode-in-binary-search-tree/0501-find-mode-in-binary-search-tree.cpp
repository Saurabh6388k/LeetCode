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
            int count=0,prev=pow(10,6);
            int maxcount=0;
            vector<int> ans;
            void check(TreeNode* root){
                if(!root)return;
                check(root->left);
                if(root->val==prev)count++;
                else count=1;
                
                if(count==maxcount){
                    ans.push_back(root->val);
                }
                else if(count>maxcount){
                    ans.clear();
                    ans.push_back(root->val);
                    maxcount=count;

                }
                   prev=root->val;
                check(root->right);
           
            }
    vector<int> findMode(TreeNode* root) {
        check(root);
        return ans;
    }
};
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
            int ans=0;

        pair<int,int> check(TreeNode* root){
            if(!root)return {0,0};
            auto p=check(root->left);
            auto q=check(root->right);
            int p1=p.first;
            int p2=p.second;
            int q1=q.first;
            int q2=q.second;
            if(((p1+q1+root->val)/(p2+q2+1))==root->val)ans++;

            return {p1+q1+root->val,p2+q2+1};
            
        }
    int averageOfSubtree(TreeNode* root) {
        auto fg=check(root);
        return ans;
    }
};
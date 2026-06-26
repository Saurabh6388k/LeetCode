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
         vector<int> q1;
       vector<int> q2;
     void check1(TreeNode* root){
        if(!root)return;
        check1(root->left);
        check1(root->right);
        if(!root->left&&!root->right)q1.push_back(root->val);

     }
         void check2(TreeNode* root){
        if(!root)return;
        check2(root->left);
        check2(root->right);
        if(!root->left&&!root->right)q2.push_back(root->val);

     }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      check1(root1);
      check2(root2);
      if(q1.size()!=q2.size())return false;

     
      for(int j=0;j<q1.size();j++){
        if(q1[j]!=q2[j])return false;

      }

      return true;
    }
};
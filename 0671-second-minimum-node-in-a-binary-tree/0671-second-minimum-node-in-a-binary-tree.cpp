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
        vector<int>ans;
        void check(TreeNode* root){
            if(!root)return ;
            check(root->left);
            check(root->right);
            ans.push_back(root->val);
        }
    int findSecondMinimumValue(TreeNode* root) {
        check(root);
        sort(ans.begin(),ans.end());
        int count =0;
        if(ans.size()<2)return -1;
        for(int i=0;i<ans.size()-1;i++){
                if(ans[i]!=ans[i+1])count++;
                if(count==1)return ans[i+1];
        }
        return -1;
    }
};
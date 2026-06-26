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
            TreeNode* maxbt(vector<int>&nums,int st,int end){
                if(st>end)return NULL;
                int mxd=st;
                int mx=nums[st];

                for(int i=st;i<=end;i++){
                    if(mx<nums[i]){
                        mx=nums[i];
                        mxd=i;
                    }
                }
                TreeNode* root=new TreeNode(nums[mxd]);
                root->left=maxbt(nums,st,mxd-1);
                root->right=maxbt(nums,mxd+1,end);
                return root;
            }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
                return maxbt(nums,0,nums.size()-1);
    }
};
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
        TreeNode* check(vector<int>nums,int l,int r){
            if(l>r)return NULL;
            int idx=l+(r-l)/2;
            TreeNode* curr=new TreeNode(nums[idx]);
            curr->left=check(nums,l,idx-1);
            curr->right=check(nums,idx+1,r);
            return curr;

        }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return check(nums,0,nums.size()-1);
        
    }
};
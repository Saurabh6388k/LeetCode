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
        int count=0,prev=INT_MAX;
        int maxcount=0;
            long long sum=0;
            vector<int> ans;
            unordered_map<long long ,int>temp;

        int check(TreeNode* root){
            if(!root)return 0 ;
            long long lsum=check(root->left);
           long long rsum= check(root->right);
           
           
            sum=lsum+rsum+root->val;
            temp[sum]++;
            if(temp[sum]==maxcount){
                ans.push_back(sum);
            }
            else if(temp[sum]>maxcount){
                ans.clear();
                ans.push_back(sum);
                 maxcount=max(maxcount,temp[sum]);
            }
            
          
            return sum;
        }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        long long fh=check(root);
        return ans;
    }
};
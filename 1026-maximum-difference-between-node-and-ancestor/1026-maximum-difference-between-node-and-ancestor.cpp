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
                    vector<int>has;
            TreeNode* check(TreeNode* root){
                if(!root)return NULL;
                has.push_back(root->val);
          
            
                if(root->left==NULL&&root->right==NULL){
                  for(int i=0;i<has.size()-1;i++){
                    for(int j=i+1;j<has.size();j++){
                        ans=max(ans,abs(has[j]-has[i]));
                    }
                  }
                  has.pop_back(); 
                  return NULL;            
            }
            root->left=check(root->left);
            root->right=check(root->right);
            if(root->left==NULL&&root->right==NULL){
                
                has.pop_back();
                return NULL;
            }
            return NULL;
            }
    int maxAncestorDiff(TreeNode* root) {
        TreeNode* ge=check(root);
        return ans;
    }
};
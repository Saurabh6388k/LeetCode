/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* curr=original;
        TreeNode* prev=cloned;
        stack<pair<TreeNode*,TreeNode*>> temp;
        temp.push({original,cloned});
        while(!temp.empty()){
            curr=temp.top().first;
            prev=temp.top().second;
            temp.pop();
            
            if(curr->right)temp.push({curr->right,prev->right});
            if(curr->left)temp.push({curr->left,prev->left});

            if(curr==target){
                return prev;

            }
            
        }
        return NULL;
    }
};
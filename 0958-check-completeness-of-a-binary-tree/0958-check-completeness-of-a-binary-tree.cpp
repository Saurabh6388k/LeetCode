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
    bool isCompleteTree(TreeNode* root) {
        queue<pair<TreeNode*,bool>> temp;
        temp.push({root,true});
        vector<bool>has;
  bool eg=false;
        while(!temp.empty()){

            TreeNode* fech=temp.front().first;
            bool ag=temp.front().second;
            int kg=0;
            int idx=temp.size();
        for(int i=0;i<idx;i++){
            fech=temp.front().first;
            ag=temp.front().second;
            if(fech==NULL){
                
                    eg=true;
                    temp.pop();
            
                    continue;

            }
            if(eg&&ag)return false;

            if(fech->left){
                temp.push({fech->left,true});

            }
            else {kg++;
                temp.push({NULL,false});
            }
            if(fech->right){
                temp.push({fech->right,true});

            }
            else {
                kg++;
                temp.push({NULL,false});

            }
            
            
            temp.pop();
        }
        if(2*idx==kg)break;
        }
        return true;
    }
};
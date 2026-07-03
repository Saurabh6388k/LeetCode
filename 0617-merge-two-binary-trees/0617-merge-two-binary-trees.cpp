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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        queue<pair<TreeNode*,TreeNode*>>temp;
        temp.push({root1,root2});
        TreeNode* head=root1;
        if(!root1&&root2)head=root2;
        if(!root1&&!root2)return NULL;
        

        

        while(!temp.empty()){
                        int idx=temp.size();
                   
                    for(int i=0;i<idx;i++){
                     TreeNode* curr1=temp.front().first;
                    TreeNode* curr2=temp.front().second;
                    temp.pop();
                    bool c1=false,c2=false;
                    if(curr1)c1=true;
                    if(curr2)c2=true;
                    if(curr1&&curr2){
                        curr1->val=curr1->val+curr2->val;
                    }
                    
                        if(c1&&c2){
                            if(!curr1->left&&curr2->left){
                                curr1->left=curr2->left;
                                curr2->left=NULL;
                            }
                            if(!curr1->right&&curr2->right){
                                curr1->right=curr2->right;
                                curr2->right=NULL;
                            }
                            if(curr1->left||curr2->left)
                            temp.push({curr1->left,curr2->left});
                            if(!curr1->right&&curr2->right)curr1->right=curr2->right;
                            if(curr1->right||curr2->right)temp.push({curr1->right,curr2->right});

                            

                        }
                        else if(!c1&&c2){
                            if(curr2->left)temp.push({NULL,curr2->left});
                            if(curr2->right)temp.push({NULL,curr2->right});
                        }
                        else{
                            if(curr1->left)temp.push({curr1->left,NULL});
                            if(curr1->right)temp.push({curr1->right,NULL});
                        }
                    }                   
        }
        return head;
    }
};
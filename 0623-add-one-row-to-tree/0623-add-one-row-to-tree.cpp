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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> temp;
        temp.push(root);
        int idx=1;
        if(depth==1){
            TreeNode* f=new TreeNode(val);
            f->left=root;
            return f;
        }
        while(!temp.empty()){
            int id=temp.size();
            TreeNode* curr=temp.front();
            

            for(int i=0;i<id;i++){
                     curr=temp.front();
                     if(idx+1==depth){
                      
                        
                              TreeNode* gech=new TreeNode(val);
                            gech->left=curr->left;
                                curr->left=gech;
                            temp.push(gech);                      
                              TreeNode* tech=new TreeNode(val);
                            tech->right=curr->right;
                                curr->right=tech;
                                temp.push(tech);
                        

                     }
                     else {
                        if(curr->left)temp.push(curr->left);
                        if(curr->right)temp.push(curr->right);

                     }
                     temp.pop();

            }
            if(idx+1==depth)return root;
            idx++;
        }
        return root;
    }
};
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
    int maxLevelSum(TreeNode* root) {
         
        queue<TreeNode*> gec;
        gec.push(root);
        int qmax=1;
        double amax=root->val;
        int lvl=1;
        while(!gec.empty()){
            int idx=gec.size();
    double fech=0;
  
    TreeNode* eg=gec.front();
    for(int i=0;i<idx;i++){
        fech+=eg->val;
   
        if(eg->left)gec.push(eg->left);
        if(eg->right)gec.push(eg->right);
        gec.pop();
        eg=gec.front();

    }
    if(amax<fech){
            qmax=lvl;
            amax=fech;
    }
        lvl++;
        }
        return qmax;
    }
};
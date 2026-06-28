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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>temp;
        queue<TreeNode*> gec;
        gec.push(root);

        while(!gec.empty()){
            int idx=gec.size();
    double fech=0;
    int count=0;
    TreeNode* eg=gec.front();
    for(int i=0;i<idx;i++){
        fech+=eg->val;
        count++;
        if(eg->left)gec.push(eg->left);
        if(eg->right)gec.push(eg->right);
        gec.pop();
        eg=gec.front();

    }
    temp.push_back(fech/count);
        }
        return temp;

    }
};
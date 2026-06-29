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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> temp;
        queue<pair<TreeNode*,pair<int,int>>>nodes;
        nodes.push({root,{0,0}});
        while(!nodes.empty()){
            auto p=nodes.front();
            nodes.pop();
            TreeNode* fg=p.first;
            int x=p.second.first;
            int y=p.second.second;
            temp[x][y].insert(fg->val);
            if(fg->left){
                nodes.push({fg->left,{x-1,y+1}});
            }
            if(fg->right){
                nodes.push({fg->right,{x+1,y+1}});

            }



        }
        vector<vector<int>> ans;
        for(auto q : temp){
                vector<int>gech;
                for(auto g :q.second){
                    gech.insert(gech.end(),g.second.begin(),g.second.end());
                }
                ans.push_back(gech);

        }
        return ans;

    }
};
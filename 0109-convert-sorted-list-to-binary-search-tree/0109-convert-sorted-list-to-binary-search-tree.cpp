/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
          TreeNode* check(ListNode* head,int l,int r){
            if(l>r)return NULL;
            ListNode* gh=head;
            for(int i=l;i<l+(r-l)/2;i++){
                    gh=gh->next;
            }

            int idx=l+(r-l)/2;
            TreeNode* curr=new TreeNode(gh->val);
            curr->left=check(head,l,idx-1);
            curr->right=check(gh->next,idx+1,r);
            return curr;

        }
    TreeNode* sortedListToBST(ListNode* head) {
        int idx=0;
        ListNode* sd=head;
        
        while(sd){
            idx++;
            sd=sd->next;

        }
        return check(head,0,idx-1);

    }
};
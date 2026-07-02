/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        queue<Node*> temp;
        Node* head=NULL;
        temp.push(node);
        unordered_map<Node*,bool>gh;
        unordered_map<int,Node*>ff;
        while(!temp.empty()){
 
            int idx=temp.size();
            for(int i=0;i<idx;i++){
                           Node* curr=temp.front();
                           temp.pop();
                           if(gh[curr])continue;
                           Node* prev=NULL;
                           if(!ff[curr->val]){
                           prev=new Node(curr->val);
                                ff[prev->val]=prev;
                           }
                           else prev=ff[curr->val];
                           gh[curr]=true;
                           if(curr==node)head=prev;
                           for(int j=0;j<curr->neighbors.size();j++){
                            if(!gh[curr->neighbors[j]]){
                            temp.push(curr->neighbors[j]);
                            }
                              Node* fg=NULL;
                            if(!ff[curr->neighbors[j]->val])
                            {
                                
                             fg=new Node(curr->neighbors[j]->val);
                             ff[fg->val]=fg;
                            }
                                    else fg=ff[curr->neighbors[j]->val];
                                prev->neighbors.push_back(fg);
                                                

                            
                           }


            }
        }
        return head;
    }
};
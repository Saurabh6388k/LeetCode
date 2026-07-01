/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
        int ans=0;
        void check(vector<Employee*> root,int id){
            Employee* curr=root[0];
            for(int i=0;i<root.size();i++){
                if(root[i]->id==id){
                    curr=root[i];
                    break;
                }
            }
               ans+=curr->importance;
            for(int i=0;i<curr->subordinates.size();i++){
                check(root,curr->subordinates[i]);
            }
        }
    int getImportance(vector<Employee*> employees, int id) {
           
            check(employees,id);

            return ans;
    }
};
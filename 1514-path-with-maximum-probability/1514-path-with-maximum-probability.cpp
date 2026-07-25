class Solution {
    
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        double ans=0;

        vector<pair<int,double>> arr[n];
        for(int i=0;i<edges.size();i++){
            arr[edges[i][0]].push_back({edges[i][1],succProb[i]});
            arr[edges[i][1]].push_back({edges[i][0],succProb[i]});

        }

       
        vector<bool> vis(n,false);
        priority_queue<pair<double,int>> temp;
        vector<double> prob(n,0.0);
        prob[start_node]=1.0;

        temp.push({prob[start_node],start_node});
        while(!temp.empty()){
            double proba=temp.top().first;
            int chk=temp.top().second;
            temp.pop();

            for(int i=0;i<arr[chk].size();i++){

                    if(prob[arr[chk][i].first]<prob[chk]*arr[chk][i].second){
                        prob[arr[chk][i].first]=prob[chk]*arr[chk][i].second;
                        temp.push({prob[arr[chk][i].first],arr[chk][i].first});
                    }
            }

        }

       return prob[end_node];

        }

    
};
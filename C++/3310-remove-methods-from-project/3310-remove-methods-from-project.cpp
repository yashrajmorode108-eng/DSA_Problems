class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj,vector<int> &suspecious){
        suspecious[node] = 1;

        for(auto nbr : adj[node]){
            if(!suspecious[nbr]){
                dfs(nbr,adj,suspecious);
            }
        }
        return;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for(auto &e : invocations){
            adj[e[0]].push_back(e[1]);
        }

        vector<int> suspecious(n,0);
        dfs(k,adj,suspecious);
        vector<int> ans;
        for(auto e : invocations){
            int a = e[0];
            int b = e[1];

            if(!suspecious[a] && suspecious[b]){
                for(int i =0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }

        for(int i =0;i<n;i++){
            if(!suspecious[i]) ans.push_back(i);
        }

        return ans;
    }
};
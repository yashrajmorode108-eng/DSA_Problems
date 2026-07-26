class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<int>&vis, vector<int>& low, vector<int>& tin, vector<int> adj[], vector<vector<int>> &bridges){
        vis[node] = 1;
        low[node] = tin[node] = timer;
        timer++;

        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it,node,vis,low,tin,adj,bridges);

                low[node] = min(low[node],low[it]);
                if(low[it] > tin[node]){
                   bridges.push_back({it,node});
                }
            }else{
                low[node] = min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto &e : connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n,0);
        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>> bridges;
        for(int i =0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,vis,low,tin,adj,bridges);
            }
        }

        return bridges;
    }
};
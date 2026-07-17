class Solution {
public:
    bool is(int start, vector<int>& color, vector<vector<int>>& graph){
          queue<int> q;
          q.push(start);
          color[start] = 0;
          while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto nbr : graph[node]){
               if(color[nbr] == -1){
                color[nbr] = !color[node];
                q.push(nbr);
               }else if(color[nbr] == color[node]){
                return false;
               }
            }
          }
          return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i = 0; i<n;i++){
            if(color[i] == -1){
                if(is(i,color,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
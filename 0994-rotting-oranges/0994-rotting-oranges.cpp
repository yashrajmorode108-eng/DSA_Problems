class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        int tm = 0;
        int cnt = 0;  //fresh_orange

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }else if(grid[i][j] == 1){
                    cnt++;
                   // vis[i][j] = 0;
                }else{
                   // vis[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm,t);

            vector<int> drow = {-1,0,1,0};
            vector<int> dcol = {0,1,0,-1};

            for(int i = 0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >=0 && nrow < n && ncol >= 0 && ncol <m && grid[nrow][ncol]==1 && vis[nrow][ncol] != 2 ){
                    vis[nrow][ncol] = 2;
                    q.push({{nrow,ncol},t+1});
                    cnt--;
                }
            }
        }

        if(cnt > 0) return -1;
        return tm;

    }
};
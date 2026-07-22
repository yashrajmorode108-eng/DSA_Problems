class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> dist(n, vector<int>(n,1e9));
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>> , greater<pair<int, pair<int, int>>>> pq;

        dist[0][0] = 1;
        pq.push({1,{0,0}});
        int ans = 0;
        while(!pq.empty()){
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int d = pq.top().first;
            if(r==n-1 && c == n-1) return d;
            pq.pop();
            
            int dr[] = {1,1,0,-1,-1,0,1,-1};
            int dc[] = {0,1,-1,-1,1,1,-1,0};

            for(int i = 0;i<8;i++){
                int nr = r + dr[i];
                int nc = c +  dc[i];

                if(nr >=0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0){
                    if(d+1 < dist[nr][nc]){
                        dist[nr][nc] = d+ 1;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }

        }
        return -1;
    }
};
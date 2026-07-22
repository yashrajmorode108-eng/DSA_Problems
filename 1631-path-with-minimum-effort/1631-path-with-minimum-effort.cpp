class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m  = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> efforts(m, vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        efforts[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int e = pq.top().first;
            if(r==m-1 && c == n-1) return e;

            pq.pop();
            int dr[] = {1,-1,0,0};
            int dc[] = {0,0,1,-1};

            for(int i = 0; i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >=0 && nr <m && nc >= 0 && nc < n){
                    int extra = abs(heights[r][c] - heights[nr][nc]);
                    int neweffort = max(efforts[r][c],extra);
                    if(neweffort< efforts[nr][nc]){
                        pq.push({neweffort,{nr,nc}});
                        efforts[nr][nc] = neweffort;
                    }
                }
            }
        }
        return efforts[m-1][n-1];
    }
};
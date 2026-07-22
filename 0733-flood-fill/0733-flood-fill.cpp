class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        queue<pair<int,int>> q;

        vector<vector<int>> iscolor(m,vector<int>(n,-1));

        q.push({sr,sc});
        int c = image[sr][sc];
        image[sr][sc] = color;
        iscolor[sr][sc] = 1;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            int dr[] = {-1,1,0,0};
            int dc[] = {0,0,-1,1};

            for(int i = 0;i<4;i++){
                int nr = cur.first + dr[i];
                int nc = cur.second + dc[i];

                if(nr >=0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == c && iscolor[nr][nc] == -1){
                    image[nr][nc] = color;
                    iscolor[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};
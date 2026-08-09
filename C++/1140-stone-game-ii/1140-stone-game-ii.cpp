class Solution {
public:
    vector<vector<int>> dp;
    vector<int> suffix;
    int n;

    int solve(int idx, int M) {
        if (idx >= n) return 0;

        if (dp[idx][M] != -1)
            return dp[idx][M];

        int best = 0;

        // Alice's maximum stones = remaining stones - Bob's maximum stones
        int total = suffix[idx];

        for (int x = 1; x <= 2 * M && idx + x <= n; x++) {
            int taken = total - solve(idx + x, max(M, x));
            best = max(best, taken);
        }

        return dp[idx][M] = best;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suffix.assign(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};

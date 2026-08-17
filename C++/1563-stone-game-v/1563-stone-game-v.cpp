class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        auto getSum = [&](int l, int r) {
            return prefix[r + 1] - prefix[l];
        };

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // leftMax[i][j] =
        // max(dp[i][k] + sum(i, k)) for i <= k <= j
        vector<vector<int>> leftMax(n, vector<int>(n, 0));

        // rightMax[i][j] =
        // max(dp[k][j] + sum(k, j)) for i <= k <= j
        vector<vector<int>> rightMax(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            leftMax[i][i] = stoneValue[i];
            rightMax[i][i] = stoneValue[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            int mid = i - 1;

            for (int j = i + 1; j < n; j++) {

                // Find largest mid such that:
                // sum(i...mid) <= sum(mid+1...j)
                while (mid + 1 < j &&
                       getSum(i, mid + 1) <= getSum(mid + 2, j)) {
                    mid++;
                }

                int best = 0;

                // Keep left part
                if (mid >= i) {
                    best = max(best, leftMax[i][mid]);
                }

                // Keep right part
                int rightStart;

                if (mid >= i &&
                    getSum(i, mid) == getSum(mid + 1, j)) {
                    // Equal sums: either side can be kept
                    rightStart = mid + 1;
                } else {
                    rightStart = mid + 2;
                }

                if (rightStart <= j) {
                    best = max(best, rightMax[rightStart][j]);
                }

                dp[i][j] = best;

                int total = getSum(i, j);

                leftMax[i][j] =
                    max(leftMax[i][j - 1], dp[i][j] + total);

                rightMax[i][j] =
                    max(rightMax[i + 1][j], dp[i][j] + total);
            }
        }

        return dp[0][n - 1];
    }
};
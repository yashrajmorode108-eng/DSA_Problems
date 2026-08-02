class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n);

        // Base case: only one number left
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
        }

        // Length of subarray
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                int takeLeft = nums[l] - dp[l + 1];
                int takeRight = nums[r] - dp[l];

                dp[l] = max(takeLeft, takeRight);
            }
        }

        return dp[0] >= 0;
    }
};
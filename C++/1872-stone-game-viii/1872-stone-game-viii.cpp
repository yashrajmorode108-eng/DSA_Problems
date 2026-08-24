class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Convert stones into prefix sums.
        // After merging first i+1 stones, their value is prefix[i].
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // If Alice takes all stones initially,
        // score difference = total sum.
        int best = stones[n - 1];

        // dp idea:
        // best = maximum score difference current player can achieve
        // from the current merged state.
        for (int i = n - 2; i >= 1; i--) {
            best = max(best, stones[i] - best);
        }

        return best;
    }
};
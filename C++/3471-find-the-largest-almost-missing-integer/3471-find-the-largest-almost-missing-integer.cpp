class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < n; i++)
            pos[nums[i]].push_back(i);

        int ans = -1;
        int maxStart = n - k;

        for (auto &entry : pos) {
            auto &v = entry.second;

            int covered = 0;
            bool has = false;
            int curL = 0, curR = -1;

            for (int idx : v) {
                int L = max(0, idx - k + 1);
                int R = min(idx, maxStart);

                if (L > R) continue; // occurrence is in no k-window

                if (!has) {
                    curL = L;
                    curR = R;
                    has = true;
                } else if (L <= curR + 1) {
                    curR = max(curR, R);
                } else {
                    covered += curR - curL + 1;
                    curL = L;
                    curR = R;
                }
            }

            if (has)
                covered += curR - curL + 1;

            if (covered == 1)
                ans = max(ans, entry.first);
        }

        return ans;
    }
};
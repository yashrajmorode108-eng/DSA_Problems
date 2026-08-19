class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 9) {
                rowMask[row] |= (1 << col);
            }
        }

        long long ans = 2LL * n;

        for (auto &[row, mask] : rowMask) {
            ans -= 2;

            bool left = true;
            for (int s = 2; s <= 5; s++) {
                if (mask & (1 << s)) {
                    left = false;
                    break;
                }
            }

            bool middle = true;
            for (int s = 4; s <= 7; s++) {
                if (mask & (1 << s)) {
                    middle = false;
                    break;
                }
            }

            bool right = true;
            for (int s = 6; s <= 9; s++) {
                if (mask & (1 << s)) {
                    right = false;
                    break;
                }
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};
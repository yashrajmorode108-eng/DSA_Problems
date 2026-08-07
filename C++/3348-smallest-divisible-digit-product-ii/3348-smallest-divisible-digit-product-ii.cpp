class Solution {
public:
    using ll = long long;

    vector<array<int, 4>> fac = {
        {0,0,0,0}, // 0
        {0,0,0,0}, // 1
        {1,0,0,0}, // 2
        {0,1,0,0}, // 3
        {2,0,0,0}, // 4
        {0,0,1,0}, // 5
        {1,1,0,0}, // 6
        {0,0,0,1}, // 7
        {3,0,0,0}, // 8
        {0,2,0,0}  // 9
    };

    array<int, 4> need;
    int A, B, C, D;
    vector<int> dp;

    int id(int a, int b, int c, int d) {
        return (((a * (B + 1) + b) * (C + 1) + c) * (D + 1) + d);
    }

    int minDigits(int a, int b, int c, int d) {
        return dp[id(a, b, c, d)];
    }

    array<int,4> subtractNeed(array<int,4> cur, int digit) {
        for (int k = 0; k < 4; k++) {
            cur[k] = max(0, cur[k] - fac[digit][k]);
        }
        return cur;
    }

    string buildSuffix(int len, array<int,4> rem) {
        string s;

        for (int pos = 0; pos < len; pos++) {
            int left = len - pos - 1;

            for (int d = 1; d <= 9; d++) {
                auto nxt = subtractNeed(rem, d);

                if (minDigits(nxt[0], nxt[1], nxt[2], nxt[3]) <= left) {
                    s.push_back(char('0' + d));
                    rem = nxt;
                    break;
                }
            }
        }

        return s;
    }

    string smallestNumber(string num, long long t) {
        need = {0,0,0,0};

        while (t % 2 == 0) {
            need[0]++;
            t /= 2;
        }
        while (t % 3 == 0) {
            need[1]++;
            t /= 3;
        }
        while (t % 5 == 0) {
            need[2]++;
            t /= 5;
        }
        while (t % 7 == 0) {
            need[3]++;
            t /= 7;
        }

        if (t != 1) return "-1";

        A = need[0];
        B = need[1];
        C = need[2];
        D = need[3];

        int totalStates = (A + 1) * (B + 1) * (C + 1) * (D + 1);
        const int INF = 1e9;

        dp.assign(totalStates, INF);
        dp[id(0,0,0,0)] = 0;

        for (int a = 0; a <= A; a++) {
            for (int b = 0; b <= B; b++) {
                for (int c = 0; c <= C; c++) {
                    for (int d = 0; d <= D; d++) {
                        if (a == 0 && b == 0 && c == 0 && d == 0)
                            continue;

                        int best = INF;

                        for (int digit = 2; digit <= 9; digit++) {
                            int na = max(0, a - fac[digit][0]);
                            int nb = max(0, b - fac[digit][1]);
                            int nc = max(0, c - fac[digit][2]);
                            int nd = max(0, d - fac[digit][3]);

                            if (na == a && nb == b && nc == c && nd == d)
                                continue;

                            best = min(best, 1 + minDigits(na, nb, nc, nd));
                        }

                        dp[id(a,b,c,d)] = best;
                    }
                }
            }
        }

        int n = num.size();

        vector<array<int,4>> prefix(n + 1);
        vector<bool> valid(n + 1, true);

        prefix[0] = {0,0,0,0};

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];
            valid[i + 1] = valid[i];

            int digit = num[i] - '0';

            if (digit == 0) {
                valid[i + 1] = false;
            } else if (valid[i]) {
                for (int k = 0; k < 4; k++) {
                    prefix[i + 1][k] += fac[digit][k];
                }
            }
        }

        if (valid[n]) {
            bool ok = true;

            for (int k = 0; k < 4; k++) {
                if (prefix[n][k] < need[k]) {
                    ok = false;
                    break;
                }
            }

            if (ok) return num;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (!valid[i]) continue;

            int curDigit = num[i] - '0';

            for (int d = max(1, curDigit + 1); d <= 9; d++) {
                array<int,4> rem = need;

                for (int k = 0; k < 4; k++) {
                    rem[k] = max(
                        0,
                        rem[k] - prefix[i][k] - fac[d][k]
                    );
                }

                int suffixLen = n - i - 1;

                if (minDigits(rem[0], rem[1], rem[2], rem[3]) <= suffixLen) {
                    string ans = num.substr(0, i);
                    ans.push_back(char('0' + d));
                    ans += buildSuffix(suffixLen, rem);
                    return ans;
                }
            }
        }

        int required = minDigits(need[0], need[1], need[2], need[3]);
        int len = max(n + 1, required);

        return buildSuffix(len, need);
    }
};
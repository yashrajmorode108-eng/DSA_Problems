class Solution {
public:
    int minimumPushes(string word) {
         vector<int> freq(26, 0);

        for (char c : word)
            freq[c - 'a']++;

        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < 26 && freq[i] > 0; i++) {
            int cost = i / 8 + 1;   // 0-7 ->1, 8-15 ->2, 16-23 ->3, 24-25 ->4
            ans += freq[i] * cost;
        }

        return ans;
    }
};
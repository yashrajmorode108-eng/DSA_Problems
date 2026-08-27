class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        string prefix = "";

        // Try matching target for as long as possible
        for (int i = 0; i < n; i++) {
            int cur = target[i] - 'a';

            if (cnt[cur] > 0) {
                prefix.push_back(target[i]);
                cnt[cur]--;
                continue;
            }

            // Can't match target[i], try smallest character greater than it
            for (int c = cur + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    prefix.push_back('a' + c);
                    cnt[c]--;

                    // Add remaining characters in sorted order
                    for (int j = 0; j < 26; j++) {
                        prefix += string(cnt[j], 'a' + j);
                    }

                    return prefix;
                }
            }

            // Can't become greater here, so backtrack
            break;
        }

        // Backtrack from right to left
        while (!prefix.empty()) {
            int pos = prefix.size() - 1;

            // Restore the character used at this position
            char removed = prefix.back();
            prefix.pop_back();
            cnt[removed - 'a']++;

            int cur = target[pos] - 'a';

            // Find smallest available character greater than target[pos]
            for (int c = cur + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    prefix.push_back('a' + c);
                    cnt[c]--;

                 
                    for (int j = 0; j < 26; j++) {
                        prefix += string(cnt[j], 'a' + j);
                    }

                    return prefix;
                }
            }
        }

        return "";
    }
};
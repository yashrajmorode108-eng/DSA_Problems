class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, ones = 0;
        string ans = "";

        for (int right = 0; right < n; right++) {
            if (s[right] == '1') ones++;

            while (ones > k) {
                if (s[left] == '1') ones--;
                left++;
            }

            while (ones == k && left <= right) {
                string curr = s.substr(left, right - left + 1);

                if (ans.empty() || curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }

                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }
        }

        return ans;
    }
};
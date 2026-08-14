class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans = {1};

        while (ans.size() < n) {
            vector<int> next;

            // Generate odd numbers
            for (int x : ans) {
                int val = 2 * x - 1;
                if (val <= n)
                    next.push_back(val);
            }

            // Generate even numbers
            for (int x : ans) {
                int val = 2 * x;
                if (val <= n)
                    next.push_back(val);
            }

            ans = next;
        }

        return ans;
    }
};
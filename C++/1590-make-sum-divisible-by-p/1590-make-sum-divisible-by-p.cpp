class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;

        for (int x : nums)
            total += x;

        int rem = total % p;

        if (rem == 0)
            return 0;

        unordered_map<int, int> last;
        last[0] = -1;

        int prefix = 0;
        int n = nums.size();
        int ans = n;

        for (int i = 0; i < n; i++) {
            prefix = (prefix + nums[i]) % p;

            int need = (prefix - rem + p) % p;

            if (last.find(need) != last.end()) {
                ans = min(ans, i - last[need]);
            }

            last[prefix] = i;
        }

        return ans == n ? -1 : ans;
    }
};
    

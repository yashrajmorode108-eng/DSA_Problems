class Solution {
public:
 void fwht(vector<long long>& a, bool inverse) {
        int n = a.size();

        for (int len = 1; 2 * len <= n; len <<= 1) {
            for (int i = 0; i < n; i += 2 * len) {
                for (int j = 0; j < len; ++j) {
                    long long u = a[i + j];
                    long long v = a[i + j + len];

                    a[i + j] = u + v;
                    a[i + j + len] = u - v;
                }
            }
        }

        if (inverse) {
            for (long long& x : a) x /= n;
        }
    }
    int uniqueXorTriplets(vector<int>& nums) {
       int mx = *max_element(nums.begin(), nums.end());

        int M = 1;
        while (M <= mx) M <<= 1;

        vector<long long> f(M, 0);

        for (int x : nums)
            f[x] = 1;   // distinct values only

        fwht(f, false);

        for (long long& x : f)
            x = x * x * x;

        fwht(f, true);

        int ans = 0;
        for (long long x : f)
            if (x != 0) ++ans;

        return ans;
    }
};
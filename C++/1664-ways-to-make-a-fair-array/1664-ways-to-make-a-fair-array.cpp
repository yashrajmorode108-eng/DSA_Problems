class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();

        long long totalEven = 0;
        long long totalOdd = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                totalEven += nums[i];
            else
                totalOdd += nums[i];
        }

        long long leftEven = 0;
        long long leftOdd = 0;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long rightEven = totalEven - leftEven;
            long long rightOdd = totalOdd - leftOdd;

            if (i % 2 == 0)
                rightEven -= nums[i];
            else
                rightOdd -= nums[i];

            long long newEven = leftEven + rightOdd;
            long long newOdd = leftOdd + rightEven;

            if (newEven == newOdd)
                ans++;

            if (i % 2 == 0)
                leftEven += nums[i];
            else
                leftOdd += nums[i];
        }

        return ans;
    }
};
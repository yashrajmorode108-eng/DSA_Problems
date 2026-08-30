class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        // Case 1: remove both from front
        int front = right + 1;

        // Case 2: remove both from back
        int back = n - left;

        // Case 3: one from front, one from back
        int bothSides = (left + 1) + (n - right);

        return min({front, back, bothSides});
    }
};
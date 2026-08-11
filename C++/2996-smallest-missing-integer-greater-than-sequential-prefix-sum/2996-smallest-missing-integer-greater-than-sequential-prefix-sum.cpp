class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0] ;
        unordered_set<int> freq(nums.begin(),nums.end());
        int i = 1;
        while(i < n && nums[i] == nums[i-1] + 1){
            sum += nums[i];
            i++;
        }

        while(freq.count(sum))sum++;
        return sum;
    }
};
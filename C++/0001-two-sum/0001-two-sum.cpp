class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> prefix;
        int n = nums.size();
        int sum =0;
        for(int i = 0;i<n;i++){
            int rem = target - nums[i];
            if(prefix.find(rem)!= prefix.end()){
                return {i,prefix[rem]};
            
            }
            prefix[nums[i]] = i;

        }
        return {};

        return {};
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        int n = nums.size();
        for(int i = 2;i<n;i++){
            if(arr1.back() > arr2.back()){
                arr1.push_back(nums[i]);
            }else{
                arr2.push_back(nums[i]);
            }
        }

        vector<int> result;
        for(auto num : arr1){
            result.push_back(num);
        }

        for(auto num : arr2){
            result.push_back(num);
        }

        return result;
    }
};
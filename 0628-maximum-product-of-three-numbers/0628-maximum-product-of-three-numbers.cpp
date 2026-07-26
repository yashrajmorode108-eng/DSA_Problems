class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==3) return nums[0]*nums[1]*nums[2];

        int maxi = INT_MIN;
        int maxi2 = -1;
        int maxi3 = -1;

        int mini = INT_MAX;
        int mini2 = -1;

        for(int i =0;i<n;i++){
            if(nums[i] >= maxi){
                maxi3 = maxi2;
                maxi2 = maxi;
                maxi = nums[i];
            }else if(nums[i] >= maxi2 && maxi != nums[i]){
                maxi3 = maxi2;
                maxi2 = nums[i];
            }else if(nums[i] >= maxi3 && nums[i] != maxi2){
                maxi3= nums[i];
            }

            if(nums[i] <= mini){
                mini2 = mini;
                mini = nums[i];
            }else if(nums[i]<=mini2 && mini!= nums[i]){
                mini2 = nums[i];
            }
        }
        return max(mini2*mini*maxi, maxi*maxi2*maxi3);
    }
};
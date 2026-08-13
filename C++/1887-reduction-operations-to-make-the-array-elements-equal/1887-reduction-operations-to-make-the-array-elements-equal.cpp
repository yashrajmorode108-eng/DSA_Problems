class Solution {
public:
    int reductionOperations(vector<int>& nums) {
       int n = nums.size();
       sort(nums.begin(),nums.end());

       int ans =0;
       int operations = 0;
       for(int i = 0;i<n-1;i++){
          if(nums[i] != nums[i+1]){
            
          operations++;
       }
       ans += operations;
      
       }
        return ans;
}
};
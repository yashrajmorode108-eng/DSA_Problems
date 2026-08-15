class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
         int x = 0;
         bool a = false;
         for(int i  : nums){
            x ^= i;
            if(i!=0) a= true;
         }

         if(x != 0){
            return nums.size();
         }else if(a== true){
            return nums.size() -1 ;
         }

         return 0;
    }
};
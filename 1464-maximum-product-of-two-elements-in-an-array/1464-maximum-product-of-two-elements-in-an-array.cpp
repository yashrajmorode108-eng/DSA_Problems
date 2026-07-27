class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = 0;
        int sec_max = -1;

        for(auto it : nums){
            if(maxi <= it){
                sec_max = maxi;
                maxi = it;
            }else if(it >= sec_max && it != maxi){
                sec_max = it;
            }
        }

        return (maxi-1)*(sec_max-1);
    }
};
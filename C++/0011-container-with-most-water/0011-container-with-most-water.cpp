class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = INT_MIN;
        int n = height.size();
        int l = 0, r = n-1;

        while(l < r){
            int curr = 0;
            if(height[l] <= height[r]){
                curr = height[l]*(r-l);
                l++;
            }else{
                curr = height[r]*(r-l);
                r--;
            }

            maxi = max(maxi, curr);

        }
        return maxi;
    }
};
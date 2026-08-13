class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = -101;
        int sum =0;

        for(int g : gain){
            sum += g;
            ans = max(ans,sum);
        }
        return ans<0 ? 0 : ans;
    }
};
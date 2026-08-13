class Solution {
public:
    bool isperfect_square(int n){
        int low =0, high = n;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long square = (long long) mid*mid;
            if(square == n){
                return true;
            }else if(square < n){
                low = mid +1;
            }else{
                high = mid -1;
            }
        }
        return false;
    }
    bool judgeSquareSum(int c) {
        int i = 0;
        while(i*i <= (c/2)){
            if(isperfect_square(c-(i*i))){
                return true;
            }
            i++;
        }
        return false;
    }
};
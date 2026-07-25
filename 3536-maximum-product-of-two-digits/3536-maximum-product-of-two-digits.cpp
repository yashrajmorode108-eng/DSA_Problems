class Solution {
public:
    int maxProduct(int n) {
        int maxi = 0;
        int sec = -1;

        int num = n;
        while(num){
            if(num%10 >= maxi){
                sec = maxi;
                maxi = num%10;
            }else if(num%10 >= sec && num%10 != maxi){
                sec = num%10;
            }
            num /= 10;
        }
        return maxi*sec;
    }
};
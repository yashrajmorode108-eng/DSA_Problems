class Solution {
public:
    bool isfeasible(int mid, int t){
        int product = 1;
        while(mid){
           product *= (mid %10);
           mid /= 10;
        }
        if(product % t == 0) return true;
        return false;
    }
    int smallestNumber(int n, int t) {
        int low = n;
        int high = 100;
        int ans;
        
        for(int i = n;i<=100;i++){
            if(isfeasible(i,t)){
                return i;
            }
        }
        return 0;
    }
};
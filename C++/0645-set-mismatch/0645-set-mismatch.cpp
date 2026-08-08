class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        long long n_sum = (n*(n+1))/2;
        long long sq_sum = n*(n+1);
        sq_sum *= (2*n+1);
        sq_sum /= 6;
        long long sum = 0, q_sum = 0;
        for(auto num : nums){
             sum += num;
             q_sum += (num*num);
        }

        int x = (int)(sum - n_sum);
        int y = (int)(q_sum - sq_sum)/x;

        int repeat = (x +y)/2;
        int missing = repeat - x;

        return {repeat,missing};
    }
};
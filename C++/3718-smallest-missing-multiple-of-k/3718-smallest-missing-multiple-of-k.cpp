class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
       set<int> st(nums.begin(),nums.end());
       int K  = k;
       while(true){
        if(st.find(K) == st.end()){
            return K;
        }
        K += k;
       }

       return -1;

    }
};
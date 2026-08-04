class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int num : nums){
            maxi = max(maxi,num);
            mini= min(mini,num);

            freq[num]++;
        }

        for(int i = mini;i<=maxi;i++){
            if(freq[i] == 0){
                ans.push_back(i);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};
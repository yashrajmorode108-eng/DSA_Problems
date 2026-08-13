class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mad = numeric_limits<int>::max();

        for(int i = 1; i < arr.size(); ++i){
            mad = min(mad, arr[i] - arr[i-1]);
        }

        vector<vector<int>> res;
        
        for(int i = 1; i < arr.size(); ++i){
            if(arr[i] - arr[i-1]==mad){
                res.push_back({arr[i-1], arr[i]});
            }
        }

        return res;
    }
};
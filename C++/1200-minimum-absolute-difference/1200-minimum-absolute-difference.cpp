class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mini = INT_MAX;
        int  n = arr.size();
        vector<vector<int>> ans;
        set<int> s;
        s.insert(arr[0]);
        for(int i = 1; i<n;i++){
           mini = min(mini,abs(arr[i]-arr[i-1]));
           s.insert(arr[i]);
        }

        for(int i =0;i<n;i++){
            if(s.find(arr[i]-mini)!= s.end() ){
                ans.push_back({arr[i] - mini,arr[i]});
            }
            // if(s.find(mini + arr[i])!= s.end() && (ans.back() != {arr[i],mini + arr[i]})){
            //     ans.push_back({arr[i],mini + arr[i]});
            // }
        }

        return ans;


    }
};
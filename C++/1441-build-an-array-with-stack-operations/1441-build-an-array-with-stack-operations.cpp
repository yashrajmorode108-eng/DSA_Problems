class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int m = target.size();
        int j = 0;
        int i =1;
        while(i<=n){
           ans.push_back("Push");
           if(i == target[j]){
            i++;
            j++;
           }else{
            ans.push_back("Pop");
            i++;
           }

           if(j==m)break;
        }
        return ans;
    }
};
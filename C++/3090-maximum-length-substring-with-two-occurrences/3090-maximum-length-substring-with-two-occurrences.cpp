class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans =0;
        int left = 0;
        vector<int> freq(26,0);
        int n = s.size();
        for(int r = 0;r<n;r++){
           freq[s[r] - 'a']++;
           while(freq[s[r]-'a'] >2){
            freq[s[left]-'a']--;
            left++;
           }

           ans = max(ans,r-left + 1);
        }
        return ans;
    }
};
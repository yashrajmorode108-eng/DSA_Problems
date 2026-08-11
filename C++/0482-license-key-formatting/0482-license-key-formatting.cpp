class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        int m = k;
        int n = s.size();

        for(int i = n-1;i>=0;i--){
            if(s[i] != '-'){
                 if(m==0){
                ans.push_back('-');
                m=k;
                }
                if((s[i]-'0')<=9 &&(s[i]-'0')>=0){
                    ans.push_back(s[i]);
                }else{
                    ans.push_back(toupper(s[i]));
                }
                m--;
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
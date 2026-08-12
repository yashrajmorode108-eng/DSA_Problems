class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string dou = s + s;
        return dou.substr(1,dou.size() -2).find(s) != string::npos;
    }
};
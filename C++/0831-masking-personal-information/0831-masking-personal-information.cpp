class Solution {
public:
    string maskPII(string s) {
        if(s.find('@')!= string::npos){
            int at = s.find('@');
            string ans = "";
            for(char &c : s){
                c = tolower(c);
            }

            ans += s[0];
            ans += "*****";
            ans += s[at - 1];

            ans += s.substr(at);

            return ans;
        }
        string digit;
        for(char c : s){
            if(isdigit(c)){
                digit += c;
            }
        }

        int country = digit.size() - 10;
        string ans = "";

        if(country > 0){
            ans += '+';
            ans.append(country,'*');
            ans += "-***-***-";

            ans += digit.substr(digit.size() - 4);
        }else{

        ans += "***-***-";
        ans += digit.substr(digit.size()-4);
        }
        return ans;
    }
};
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = 1;
        if(b=="")return 0;
        string cur = a;
        while(cur.length() < b.length()){
            cur += a;
            count++;
        }

        if(cur.find(b) != string::npos) return count;

        cur += a;
        count++;

        if(cur.find(b) != string::npos)return count;

        return -1;



    }
};
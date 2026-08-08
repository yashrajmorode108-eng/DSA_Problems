class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> ans(n, 0);
    stack<int> st;

    int prevTime = 0;

    for (string s : logs) {
        int first = s.find(':');
        int second = s.find(':', first + 1);

        int id = stoi(s.substr(0, first));
        string type = s.substr(first + 1, second - first - 1);
        int time = stoi(s.substr(second + 1));

        if (type == "start") {
            if (!st.empty()) {
                ans[st.top()] += time - prevTime;
            }

            st.push(id);
            prevTime = time;
        } else {
            ans[st.top()] += time - prevTime + 1;
            st.pop();

            prevTime = time + 1;
        }
    }

    return ans;
}
};

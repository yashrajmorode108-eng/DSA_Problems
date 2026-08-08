class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto s : tokens){
            if((s!="*")&&(s!="+")&&(s!="-")&&(s!="/")){
                st.push(stoi(s));
            }else
            if(s == "*" ){
                int left = st.top();
                st.pop();
                int right = st.top();
                st.pop();

                st.push(right*left);
            }else if(s == "+" ){
                int left = st.top();
                st.pop();
                int right = st.top();
                st.pop();

                st.push(right+left);
            }else if(s == "-" ){
                int left = st.top();
                st.pop();
                int right = st.top();
                st.pop();

                st.push(right-left);
            }else if(s == "/" ){
                int left = st.top();
                st.pop();
                int right = st.top();
                st.pop();

                st.push(right/left);
            }
        }
        return st.top();
    }
};
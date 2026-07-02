class Solution {
public:
     vector<int> nse(vector<int>& arr){
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }

            result[i] = st.empty()? n : st.top();
            st.push(i);
        }
        return result;
    }
    vector<int> psee(vector<int>& arr){
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        for(int i = 0;i<n;i++){
            while(!st.empty() && arr[i] < arr[st.top()]){
                st.pop();
            }

            result[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        return result;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;
        vector<int> ns = nse(arr);
        vector<int> ps = psee(arr);
        //int mod = (int) 1e9 + 7;
        for(int i = 0;i<n;i++){
            long long right = ns[i] - i;
            long long left = i - ps[i];

            total = (total + ((right*left)*1LL*arr[i]));
        }
        return total;
    }
     vector<int> nge(vector<int>& arr){
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[i] >= arr[st.top()]){
                st.pop();
            }

            result[i] = st.empty()? n : st.top();
            st.push(i);
        }
        return result;
    }
    vector<int> pgee(vector<int>& arr){
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        for(int i = 0;i<n;i++){
            while(!st.empty() && arr[i] > arr[st.top()]){
                st.pop();
            }

            result[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        return result;
    }
    long long sumSubarrayMaxes(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;
        vector<int> ns = nge(arr);
        vector<int> ps = pgee(arr);
        //int mod = (int) 1e9 + 7;
        for(int i = 0;i<n;i++){
            long long right = ns[i] - i;
            long long left = i - ps[i];

            total = (total + ((right*left)*1LL*arr[i]));
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxes(nums) - sumSubarrayMins(nums);
    }
};
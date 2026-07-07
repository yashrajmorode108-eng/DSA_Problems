class KthLargest {
    int k;
    priority_queue<int,vector<int>, greater<int>> pq;
public:
    KthLargest(int k1, vector<int>& nums) {
        k = k1;
        for(int score: nums){
            if(static_cast<int>(pq.size()) < k || score > pq.top()){
                pq.push(score);
                if(static_cast<int>(pq.size())>k){
                    pq.pop();
                }
            }
        }
    }
    
    int add(int val) {
        if(static_cast<int>(pq.size())<k || val > pq.top()){
            pq.push(val);
            if(static_cast<int>(pq.size()) > k){
                pq.pop();
            }
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
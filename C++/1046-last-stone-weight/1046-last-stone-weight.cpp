class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone : stones){
            pq.push(stone);
        }

        while(!pq.empty()){
            if(pq.size() == 1)return pq.top();
            int y = pq.top();
            pq.pop();
            int x = pq.top();pq.pop();

            if(y!=x){
                pq.push(y-x);
            }
        }

        if(pq.empty())return 0;
        return 0;
    }
};
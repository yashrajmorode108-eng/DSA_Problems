/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;   //min_heap;

        if(n==0) return nullptr;
        if(n==1) return lists[0];

        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;

        for(int i = 0;i<n;i++){
           if(lists[i]) pq.push({lists[i]->val, lists[i]});
        }

        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            cur->next = x.second;
            cur = cur->next;

            if(x.second->next){
                pq.push({x.second->next->val, x.second->next});
            }
        }
        return dummy->next;
    }
};
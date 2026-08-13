/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       unordered_map<Node*, Node*> mpp;
       Node* temp = head;

       while(temp!= NULL){
        mpp[temp] = new Node(temp->val);
        temp= temp->next;
       }
       
       temp = head;

       while(temp!= NULL){
        mpp[temp]->next = temp->next ? mpp[temp->next]:nullptr;
        mpp[temp]->random = temp->random ? mpp[temp->random]: nullptr;
        temp = temp->next;
       }

       return mpp[head];
    }
};
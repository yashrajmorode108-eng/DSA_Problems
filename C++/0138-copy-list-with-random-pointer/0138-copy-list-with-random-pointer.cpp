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
        if (head == nullptr)
            return nullptr;

        Node* cur = head;

        // Step 1: Insert copied nodes after original nodes
        while (cur != nullptr) {
            Node* copy = new Node(cur->val);

            copy->next = cur->next;
            cur->next = copy;

            cur = copy->next;
        }

        // Step 2: Assign random pointers
        cur = head;

        while (cur != nullptr) {
            Node* copy = cur->next;

            if (cur->random != nullptr)
                copy->random = cur->random->next;

            cur = copy->next;
        }

        // Step 3: Separate original and copied lists
        cur = head;
        Node* copiedHead = head->next;

        while (cur != nullptr) {
            Node* copy = cur->next;

            cur->next = copy->next;

            if (copy->next != nullptr)
                copy->next = copy->next->next;

            cur = cur->next;
        }

        return copiedHead;
    }
};
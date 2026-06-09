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
        unordered_map<Node*, Node*> oldToCopy;
        oldToCopy[nullptr] = nullptr;

        Node* cur = head;
        while (cur != nullptr) {
            if (oldToCopy.find(cur) == oldToCopy.end()) {
                oldToCopy[cur] = new Node(0);
            }
            oldToCopy[cur]->val = cur->val;
            if (oldToCopy.find(cur->next) == oldToCopy.end()) {
                oldToCopy[cur->next] = new Node(0);
            }
            oldToCopy[cur]->next = oldToCopy[cur->next];
            if (oldToCopy.find(cur->random) == oldToCopy.end()) {
                oldToCopy[cur->random] = new Node(0);
            }
            oldToCopy[cur]->random = oldToCopy[cur->random];
            cur = cur->next;
        }
        return oldToCopy[head];
    }
};
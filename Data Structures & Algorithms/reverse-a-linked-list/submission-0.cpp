class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        //0 1 2 3
        //prev  curr-head curr->next= nextNode = prev so prev=curr and curr= nextNode

        while (curr) {
            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;

        ListNode *ptrA = headA;
        ListNode *ptrB = headB;

        while (ptrA != ptrB) {
            ptrA = (ptrA == NULL) ? headB : ptrA->next;
            ptrB = (ptrB == NULL) ? headA : ptrB->next;
        }

        return ptrA;
    }
};
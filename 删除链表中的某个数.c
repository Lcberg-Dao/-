#define _CRT_SECURE_NO_WARNINGS 1

//СІПл https://leetcode.cn/problems/remove-linked-list-elements/submissions/573657437/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy = { 0, head };
    struct ListNode* cur = &dummy;
    while (cur->next) {
        struct ListNode* nxt = cur->next;
        if (nxt->val == val) {
            cur->next = nxt->next;
            free(nxt);
        }
        else {
            cur = nxt;
        }
    }
    return dummy.next;
}
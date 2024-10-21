

/* https://leetcode.cn/problems/intersection-of-two-linked-lists/
* Definition for singly - linked list.
* struct ListNode {
    *int val;
    *struct ListNode* next;
    *
};
*/
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //计算两个链表的节点的个数
    struct ListNode* tail1 = headA;
    struct ListNode* tail2 = headB;
    int a = 0;
    int b = 0;
    while (tail1)
    {
        a++;
        tail1 = tail1->next;
    }
    while (tail2)
    {
        b++;
        tail2 = tail2->next;
    }
    struct ListNode* longlist = NULL;
    struct ListNode* shortlist = NULL;
    int w = 0;
    if (a > b)
    {

        longlist = headA;
        shortlist = headB;
        w = a - b;
    }
    else
    {
        longlist = headB;
        shortlist = headA;
        w = b - a;
    }
    while (w--)
    {
        longlist = longlist->next;
    }
    while (shortlist)
    {
        if (shortlist == longlist)
        {
            return longlist;
        }
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return NULL;
}
#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};


void SListPrint(struct ListNode* plist)
{
	if (plist == NULL)
	{
		return NULL;
	}
	struct ListNode* tail = plist;
	while (tail != NULL)
	{
		printf("%d->", tail->val);
		tail = tail->next;
	}
	printf("NULL\n");
}

struct ListNode* detectCycle(struct ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	struct ListNode* start = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			while (start != slow)
			{
				start = start->next;
				slow = slow->next;
			}
			return start;
		}
	}
	return NULL;
}

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	n1->val = 1;
	n2->val = 2;
	n3->val = 3;
	n4->val = 4;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n2;

	struct ListNode* newlist = detectCycle(n1);
	printf("%d\n", newlist->val);
	return 0;
}
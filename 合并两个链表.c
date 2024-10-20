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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* tail = newnode;

	while (list1 && list2)
	{
		if (list1->val < list2->val)
		{
			tail->next = list1;
			tail = list1;
			list1 = list1->next;
		}
		else
		{
			tail->next = list2;
			tail = list2;
			list2 = list2->next;
		}
	}
	if (list1 == NULL)
	{
		tail->next = list2;
	}
	else
	{
		tail->next = list1;
	}
	return newnode->next;
}

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	n1->val = -1;
	n2->val = 3;
	n3->val = 8;
	n4->val = 11;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n8 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n9 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	n5->val = 1;
	n6->val = 6;
	n7->val = 8;
	n8->val = 10;
	n9->val = 14;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = n9;
	n9->next = NULL;

	struct ListNode* newlist = mergeTwoLists(n1, n5);
	SListPrint(newlist);
	return 0;
}
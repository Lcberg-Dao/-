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

struct ListNode* partition(struct ListNode* pHead, int x)
{
	struct ListNode* lesslist = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* greatlist = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (pHead == NULL)
	{
		return NULL;
	}
	struct ListNode* tail = pHead;
	struct ListNode* tail1 = lesslist;
	struct ListNode* tail2 = greatlist;
	while (tail)
	{
		
		if (tail->val < x)
		{
			tail1->next = tail;
			tail1 = tail1->next;
		}
		else
		{
			tail2->next = tail;
			tail2 = tail2->next;
		}
		tail = tail->next;
	}
	tail1->next = greatlist->next;
	tail2->next = NULL;
	return lesslist->next;

}

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	n1->val = 1;
	n2->val = 7;
	n3->val = 3;
	n4->val = 5;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	struct ListNode* newlist = partition(n1, 4);
	SListPrint(newlist);
	return 0;
}
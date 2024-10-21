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

struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* scr = NULL;
	struct ListNode* tail = head;
	while (tail)
	{
		struct ListNode* next = tail->next;
		tail->next = scr;
		scr = tail;
		tail = next;
	}
	return scr;
}

int chkPalindrome(struct ListNode* A)
{
	if (A == NULL)
	{
		return 1;
	}
	struct ListNode* fast = A;
	struct ListNode* slow = A;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	struct ListNode* mid = slow;
	//ºó°ë¶ÎÄæÖÃ
	struct ListNode* backhead = reverseList(mid);
	struct ListNode* tail1 = A;
	struct ListNode* tail2 = backhead;
	while (tail2)
	{
		if (tail1->val == tail2->val)
		{
			tail1 = tail1->next;
			tail2 = tail2->next;
		}
		else
			return 0;
	}
	return 1;
}

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode*));
	n1->val = 1;
	n2->val = 2;
	n3->val = 3;
	n4->val = 2;
	n5->val = 1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	int pc = chkPalindrome(n1);
	printf("%d", pc);
	
	
	return 0;
}
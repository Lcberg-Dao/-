//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//struct ListNode 
//{
//    int val;
//    struct ListNode* next;
//};
// 
////���붯̬�ڵ�
//struct ListNode* BuySListNode(int x)
//{
//	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode*));
//	if (node == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//	node->val = x;
//	node->next = NULL;
//	return node;
//}
//
////������β��
//void SListPushBack(struct ListNode** pplist, int x)
//{
//	assert(pplist);
//	struct ListNode* newnode = BuySListNode(x);
//	if (*pplist == NULL)
//	{
//		*pplist = newnode;
//	}
//	//��β
//	else
//	{
//		struct ListNode* tail = *pplist;
//		while (tail->next != NULL)
//		{
//			tail = tail->next;
//		}
//		tail->next = newnode;
//	}
//}
//void SListPrint(struct ListNode* plist)
//{
//	if (plist == NULL)
//	{
//		return NULL;
//	}
//	struct ListNode* tail = plist;
//	while (tail != NULL)
//	{
//		printf("%d->", tail->val);
//		tail = tail->next;
//	}
//	printf("NULL\n");
//}
//
//int main()
//{
//	struct ListNode* plist = NULL;
//	SListPushBack(&plist, 1);
//
//	SListPrint(plist);
//
//	return 0;
//}
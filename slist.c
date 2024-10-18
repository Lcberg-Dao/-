#define _CRT_SECURE_NO_WARNINGS 1

#include "slist.h"

//在动态内存申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//单链表打印
void SListPrint(SListNode* plist)
{
	if (plist == NULL)
	{
		return 1;
	}
	SListNode* tail = plist;
	while (tail != NULL)
	{
		printf("->%d", tail->data);
		tail = tail->next;
	}
	printf("\n");
}

//单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* addnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = addnode;
	}
	//找尾
	else
	{
		SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = addnode;
	}
}

 //单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* addnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = addnode;
	}
	else
	{
		SListNode* tail = *pplist;
		*pplist = addnode;
		(*pplist)->next = tail;
	}
}


//单链表尾删
void SListPopBack(SListNode** pplist)
{
	assert(*pplist != NULL);

	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* tail = *pplist;
		SListNode* listnode = NULL;
		while (tail->next != NULL)
		{
			listnode = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		listnode->next = NULL;
	}
}


//头删
void SListPopFront(SListNode** pplist)
{
	assert((*pplist) != NULL);

	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* listnode = *pplist;
		*pplist = (*pplist)->next;
		free(listnode);
		listnode = NULL;
	}
}

//单链表的查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);

	SListNode* seardata = plist;
	//记录位置
	int count = 0;
	while (seardata != NULL)
	{
		count++;
		if (seardata->data == x)
		{
			printf("->%d在第%d个节点位置\n", x, count);
			return seardata;
		}
		else
		{
			seardata = seardata->next;
		}
	}
	printf("链表中没有这个数\n");
}

//// 单链表在pos位置之后插入x
//void SListInsertAfter(SListNode** pplist,SListNode* pos, SLTDateType x)
//{
//	SListNode* tail = *pplist;
//	SListNode* listnode = NULL;
//	SListNode* addnode = BuySListNode(x);
//	while (tail != pos)
//	{
//		tail = tail->next;
//		listnode = tail;
//	}
//	listnode->next = addnode;
//	addnode->next =tail;
//}

// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos)
{

}
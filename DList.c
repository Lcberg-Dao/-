#define _CRT_SECURE_NO_WARNINGS 1

#include "DList.h"

//创建新节点及申请空间
ListNode* Buynode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL)
	{
		perror("node:");
	}
	else
	{
		node->_data = x;
		node->_next = NULL;
		node->_prev = NULL;
	}
	return node;
}

//创建哨兵位及初始化
ListNode* ListCreate()
{
	ListNode* newnode = Buynode(0);
	newnode->_next = newnode;
	newnode->_prev = newnode;
	return newnode;
}

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newnode = Buynode(x);
	ListNode* tail = pHead->_prev;
	tail->_next = newnode;
	newnode->_prev = tail;
	newnode->_next = pHead;
	pHead->_prev = newnode;
}

// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);

	ListNode* tail = pHead->_next;
	printf("<= phead ");
	while (tail != pHead)
	{
		printf("<=> %d ", tail->_data);
		tail = tail->_next;
	}
	printf("=>\n");
}

// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	if (pHead->_next == pHead)
	{
		printf("链表为空，无法删除!!!\n");
		return;
	}
	ListNode* tail = pHead->_prev;
	ListNode* prevnode = tail->_prev;
	prevnode->_next = pHead;
	pHead->_prev = prevnode;
	free(tail);
	tail = NULL;
}

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* first = pHead->_next;
	ListNode* newnode = Buynode(x);

	newnode->_next = first;
	first->_prev = newnode;
	newnode->_prev = pHead;
	pHead->_next = newnode;
}

// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	if (pHead->_next == pHead)
	{
		printf("链表为空，无法删除!!!\n");
		return;
	}

	ListNode* first = pHead->_next;
	pHead->_next = first->_next;
	first->_next->_prev = pHead;
	free(first);
	first = NULL;

}

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* scr = pHead->_next;
	while (scr != pHead)
	{
		if (scr->_data == x)
		{
			return scr;
		}
		scr = scr->_next;
	}
	return NULL;
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = Buynode(x);

	newnode->_next = pos;
	pos->_prev = newnode;
	prev->_next = newnode;
	newnode->_prev = prev;
}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;

	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}
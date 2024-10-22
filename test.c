#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"

int main()
{
	//创建哨兵位及初始化
	ListNode* dlist = ListCreate();
	
	// 双向链表尾插
	ListPushBack(dlist, 1);
	ListPushBack(dlist, 2);
	ListPushBack(dlist, 3);
	ListPushBack(dlist, 4);
	ListPushBack(dlist, 5);
	ListPushBack(dlist, 6);
	//打印
	ListPrint(dlist);

	//尾删
	ListPopBack(dlist);
	ListPrint(dlist);
	ListPopBack(dlist);
	ListPrint(dlist);
	ListPopBack(dlist);
	ListPrint(dlist);
	
	//头插
	ListPushFront(dlist, 1);
	ListPrint(dlist);
	ListPushFront(dlist, 2);
	ListPrint(dlist);
	ListPushFront(dlist, 3);
	ListPrint(dlist);
	ListPushFront(dlist, 4);
	ListPrint(dlist);
	ListPushFront(dlist, 5);
	ListPrint(dlist);
	ListPushFront(dlist, 6);
	ListPrint(dlist);

	//头删
	ListPopFront(dlist);
	ListPopFront(dlist);
	ListPopFront(dlist);
	ListPrint(dlist);

	//查找
	ListNode* pos = ListFind(dlist, 1);
	//在pos前面插入x
	ListInsert(pos, 2);
	ListPrint(dlist);

	//查找
	pos = ListFind(dlist, 2);
	// 双向链表删除pos位置的节点
	ListErase(pos);
	ListPrint(dlist);

	return 0;
}
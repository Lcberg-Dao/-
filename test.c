#define _CRT_SECURE_NO_WARNINGS 1

#include "slist.h"

int main()
{
	SListNode* plist = NULL;

	//尾插
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	//打印链表
	SListPrint(plist);
	//头插
	SListPushFront(&plist, 0);
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);
	SListPrint(plist);
	//尾删
	SListPopBack(&plist);
	SListPrint(plist);
	//头删
	SListPopFront(&plist);
	SListPrint(plist);
	//查找
	SListNode* search = SListFind(plist, 2);
	SListPrint(search);
	//先查找位置在删除或者插入
	//在pos后插入x
	//SListInsertAfter(&plist, search, 10);
	//SListPrint(plist);
	//删除pos位置之后的值
	//SListEraseAfter(plist, 10);

	return 0;
}

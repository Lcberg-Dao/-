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

	//先查找位置在删除或者插入
	//在Pos位置之前插入
	SListInerTerlist(&plist, search, 20);
	SListPrint(plist);

	//删除pos之前的值
	search = SListFind(plist, 2);
	SListEraseTerlist(&plist, search);
	search = NULL;
	SListPrint(plist);

	//在pos之后插入
	search = SListFind(plist, 4);
	SListInsertAfter(search, 80);
	SListPrint(plist);

	//删除pos后面的数据
	search = SListFind(plist, 2);
	SListEraseAfter(search);
	SListPrint(plist);

	//链表销毁
	SLTDestroy(&plist);
	return 0;
}

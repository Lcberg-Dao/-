#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"

int main()
{
	SL s;
	//结构体初始化
	SListInit(&s);

	//尾插
	SListPushBack(&s, 10);
	SListPushBack(&s, 20);
	SListPushBack(&s, 30);
	SListPushBack(&s, 40);
	SListPushBack(&s, 50);
	SListPushBack(&s, 60);
	SListPushBack(&s, 70);

	//打印数据
	Print(&s);

	//尾删
	SListPopBack(&s);
	Print(&s);

	//头插
	SListPushFront(&s, 1);
	//打印数据
	Print(&s);

	//头删
	SListPopFront(&s);
	Print(&s);


	//数据销毁
	int n;
	scanf("%s", &n);
	if (n == 0)
	{
		SListDestroy(&s);
	}
	return 0;
}
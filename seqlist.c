#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"

//结构体初始化
void SListInit(SL* ps)
{
	assert(ps);

	ps->a = (SLDateType*)malloc(sizeof(SLDateType) * NUM);
	if (ps->a == NULL)
	{
		perror("malloc fail");
	}
	ps->size = 0;
	ps->capacity = NUM;

}

//动态内存数据销毁
void SListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}



//尾插
void SListPushBack(SL* ps, SLDateType x)
{
	assert(ps);

	if (ps->size > ps->capacity)
	{
		SLDateType* tmp = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->capacity *= 2;
	}
	ps->a [ps->size++] = x;
}

//尾删
void SListPopBack(SL* ps)
{
	assert(ps->a);

	ps->size--;
}

//打印数据
void Print(SL* ps)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");

}

//头插
void SListPushFront(SL* ps, SLDateType x)
{
	assert(ps);

	ps->size = ps->size + 1;

	if (ps->size > ps->capacity)
	{
		SLDateType* tmp = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->capacity *= 2;
	}

	SLDateType* pc = memmove(ps->a+1 , ps->a, sizeof(SLDateType) * ps->size);
	if (pc == NULL)
	{
		perror("memmove file");
		return;
	}
	ps->a[0] = x;
}

//头删
void SListPopFront(SL* ps)
{
	assert(ps);

	SLDateType* del = memmove(ps->a, ps->a+1, sizeof(SLDateType) * ps->size-1);
	if (del == NULL)
	{
		perror("memmove file");
		return;
	}
	ps->a = del;
	ps->size--;
}
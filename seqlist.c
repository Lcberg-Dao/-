#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"

//�ṹ���ʼ��
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

//��̬�ڴ���������
void SListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}



//β��
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

//βɾ
void SListPopBack(SL* ps)
{
	assert(ps->a);

	ps->size--;
}

//��ӡ����
void Print(SL* ps)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");

}

//ͷ��
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

//ͷɾ
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
#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

//ջ��ʼ��
void STInit(ST* para)
{
	assert(para);

	para->a = (STDatatype*)malloc(sizeof(STDatatype) * 4);
	para->capacity = 4;
	para->top = -1;
}

//����ջ
void STdestroy(ST* para)
{
	assert(para);
	free(para->a);
	para->capacity = 0;
	para->top = -1;
}

//��ջ
void STpush(ST* para, STDatatype x)
{
	assert(para);
	if (para->top == para->capacity)
	{
		para->capacity = para->capacity * 2;
		int* new = (STDatatype*)realloc(para->a ,sizeof(STDatatype) * (para->capacity));
		if (new == NULL)
		{
			perror("malloc:");
			return NULL;
		}
		para->a = new;
	}
	para->top++;
	para->a [para->top ] = x;
}

//��ջ
void STpop(ST* para)
{
	assert(para);
	assert(!STempty(para));

	printf("%d ", para->a[para->top]);
	para->top--;
}

//ջ�����ݵ�ʣ�����
void STsize(ST* para)
{
	assert(para);
	printf("\nջ�л���%d������ \n", para->top + 1);
}

//�ж�ջ�Ƿ�Ϊ��
bool STempty(ST* para)
{
	assert(para);

	return para->top == -1;
}

//ջ��Ԫ��
STDatatype STTop(ST* para)
{
	assert(para);
	assert(!STempty(para));

	return para->a[para->top];
}



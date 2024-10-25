#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

//栈初始化
void STInit(ST* para)
{
	assert(para);

	para->a = (STDatatype*)malloc(sizeof(STDatatype) * 4);
	para->capacity = 4;
	para->top = -1;
}

//销毁栈
void STdestroy(ST* para)
{
	assert(para);
	free(para->a);
	para->capacity = 0;
	para->top = -1;
}

//入栈
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

//出栈
void STpop(ST* para)
{
	assert(para);
	assert(!STempty(para));

	printf("%d ", para->a[para->top]);
	para->top--;
}

//栈中数据的剩余个数
void STsize(ST* para)
{
	assert(para);
	printf("\n栈中还有%d个数据 \n", para->top + 1);
}

//判断栈是否为空
bool STempty(ST* para)
{
	assert(para);

	return para->top == -1;
}

//栈顶元素
STDatatype STTop(ST* para)
{
	assert(para);
	assert(!STempty(para));

	return para->a[para->top];
}



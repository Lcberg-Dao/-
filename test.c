#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

int main()
{
	ST stack;

	//栈初始化
	STInit(&stack);


	//入栈
	STpush(&stack, 4);
	STpush(&stack, 3);
	STpush(&stack, 2);
	//出栈
	STpop(&stack);
	STpush(&stack, 1);
	STpop(&stack);
	STpop(&stack);

	//栈中数据的个数 
	STsize(&stack);

	//查询栈顶元素
	printf("栈顶的元素为->%d\n", STTop(&stack));

	return 0;
}
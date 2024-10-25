//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//
//typedef char STDatatype;
//typedef struct Stack
//{
//	STDatatype* a;
//	int top;//top =0 指向栈顶元素下一个元素位置，top=-1指向栈顶
//	int capacity;
//}ST;
//
//bool STempty(ST* para)
//{
//	assert(para);
//
//	return para->top == -1;
//}
//
////栈初始化
//void STInit(ST* para)
//{
//	assert(para);
//
//	para->a = (STDatatype*)malloc(sizeof(STDatatype) * 4);
//	para->capacity = 4;
//	para->top = -1;
//}
//
////销毁栈
//void STdestroy(ST* para)
//{
//	assert(para);
//	free(para->a);
//	para->capacity = 0;
//	para->top = -1;
//}
//
////入栈
//void STpush(ST* para, STDatatype x)
//{
//	assert(para);
//	if (para->top == para->capacity)
//	{
//		para->capacity = para->capacity * 2;
//		STDatatype* new = (STDatatype*)realloc(para->a, sizeof(STDatatype) * (para->capacity));
//		if (new == NULL)
//		{
//			perror("realloc:");
//		}
//		para->a = new;
//	}
//	else
//	{
//		para->top++;
//		para->a[para->top] = x;
//	}
//
//}
//
////出栈
//void STpop(ST* para)
//{
//	assert(para);
//	assert(!STempty(para));
//
//	para->top--;
//}
//
////栈顶元素
//STDatatype STTop(ST* para)
//{
//	assert(para);
//	assert(!STempty(para));
//
//	return para->a[para->top];
//}
//
////栈中数据的剩余个数
//void STsize(ST* para)
//{
//	assert(para);
//	printf("\n栈中还有%d个数据 \n", para->top + 1);
//}
//
//int main()
//{
//	ST stack;
//
//	//栈初始化
//	STInit(&stack);
//
//
//	//入栈
//	STpush(&stack, 4);
//	STpush(&stack, 3);
//	STpush(&stack, 2);
//	//出栈
//	STpop(&stack);
//	STpush(&stack, 1);
//	STpop(&stack);
//	STpop(&stack);
//
//	STpush(&stack, 2);
//	STpop(&stack);
//
//	//栈中数据的个数 
//	STsize(&stack);
//
//	//查询栈顶元素
//	printf("栈顶的元素为->%d\n", STTop(&stack));
//
//	return 0;
//}
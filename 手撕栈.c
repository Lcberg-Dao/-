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
//	int top;//top =0 ָ��ջ��Ԫ����һ��Ԫ��λ�ã�top=-1ָ��ջ��
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
////ջ��ʼ��
//void STInit(ST* para)
//{
//	assert(para);
//
//	para->a = (STDatatype*)malloc(sizeof(STDatatype) * 4);
//	para->capacity = 4;
//	para->top = -1;
//}
//
////����ջ
//void STdestroy(ST* para)
//{
//	assert(para);
//	free(para->a);
//	para->capacity = 0;
//	para->top = -1;
//}
//
////��ջ
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
////��ջ
//void STpop(ST* para)
//{
//	assert(para);
//	assert(!STempty(para));
//
//	para->top--;
//}
//
////ջ��Ԫ��
//STDatatype STTop(ST* para)
//{
//	assert(para);
//	assert(!STempty(para));
//
//	return para->a[para->top];
//}
//
////ջ�����ݵ�ʣ�����
//void STsize(ST* para)
//{
//	assert(para);
//	printf("\nջ�л���%d������ \n", para->top + 1);
//}
//
//int main()
//{
//	ST stack;
//
//	//ջ��ʼ��
//	STInit(&stack);
//
//
//	//��ջ
//	STpush(&stack, 4);
//	STpush(&stack, 3);
//	STpush(&stack, 2);
//	//��ջ
//	STpop(&stack);
//	STpush(&stack, 1);
//	STpop(&stack);
//	STpop(&stack);
//
//	STpush(&stack, 2);
//	STpop(&stack);
//
//	//ջ�����ݵĸ��� 
//	STsize(&stack);
//
//	//��ѯջ��Ԫ��
//	printf("ջ����Ԫ��Ϊ->%d\n", STTop(&stack));
//
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

int main()
{
	ST stack;

	//ջ��ʼ��
	STInit(&stack);


	//��ջ
	STpush(&stack, 4);
	STpush(&stack, 3);
	STpush(&stack, 2);
	//��ջ
	STpop(&stack);
	STpush(&stack, 1);
	STpop(&stack);
	STpop(&stack);

	//ջ�����ݵĸ��� 
	STsize(&stack);

	//��ѯջ��Ԫ��
	printf("ջ����Ԫ��Ϊ->%d\n", STTop(&stack));

	return 0;
}
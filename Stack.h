#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int STDatatype;
typedef struct Stack
{
	int* a;
	int top;//top =0 ָ��ջ��Ԫ����һ��Ԫ��λ�ã�top=-1ָ��ջ��
	int capacity;
}ST;

//ջ��ʼ��
void STInit(ST* para);
//����ջ
void STdestroy(ST* para);
//��ջ
void STpush(ST* para, STDatatype x);
//��ջ
void STpop(ST* para);
//ջ�����ݵĸ���
void STsize(ST* para);
//�ж�ջ�Ƿ�Ϊ��
bool STempty(ST* para);
//��ѯջ��Ԫ��
STDatatype STTop(ST* para);


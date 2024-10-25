#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int QDataType;
typedef struct Queuenode
{
	QDataType a;
	struct Queuenode* next;
}Qnode;

typedef struct Queue
{
	Qnode* tail;
	Qnode* read;
	int size;
}Queue;

//��ʼ������
void QueueInit(Queue* ps);
//���ٶ���
void QueueDestroy(Queue* ps);
//�����
void Queuepush(Queue* ps, QDataType x);
//������
void Queuepop(Queue* ps);
//�鿴�����е�Ԫ�ظ���
void Queuesize(Queue* ps);
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* ps);
//�鿴����
QDataType QueueFront(Queue* ps);
//�鿴��β
QDataType QueueBack(Queue* ps);

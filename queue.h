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

//初始化队列
void QueueInit(Queue* ps);
//销毁队列
void QueueDestroy(Queue* ps);
//入队列
void Queuepush(Queue* ps, QDataType x);
//出队列
void Queuepop(Queue* ps);
//查看队列中的元素个数
void Queuesize(Queue* ps);
//判断队列是否为空
bool QueueEmpty(Queue* ps);
//查看队首
QDataType QueueFront(Queue* ps);
//查看队尾
QDataType QueueBack(Queue* ps);

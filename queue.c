#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"

//创建新节点
Qnode* Creatnode(QDataType x)
{
	Qnode* node = (Qnode*)malloc(sizeof(Qnode));
	if (node == NULL)
	{
		perror("malloc:");
		return NULL;
	}
	node->a = x;
	node->next = NULL;
	return node;
}

//初始化
void QueueInit(Queue* ps)
{
	assert(ps);

	ps->read = NULL;
	ps->size = 0;
	ps->tail = NULL;
}

//销毁队列
void QueueDestroy(Queue* ps)
{
	assert(ps);
	free(ps->read);
	free(ps->tail);
	ps->read = NULL;
	ps->tail = NULL;
	ps->size = 0;
}

//入队列
void Queuepush(Queue* ps, QDataType x)
{
	assert(ps);
	Qnode* newnode = Creatnode(x);
	if (newnode == NULL)
	{
		perror("Creatnode");
		return;
	}
	if (ps->tail == NULL)
	{
		ps->read = ps->tail = newnode;
	}
	else
	{
		ps->tail->next = newnode;
		ps->tail = newnode;
	}
	ps->size++;
}

//出队列
void Queuepop(Queue* ps)
{
	assert(ps);
	assert(QueueEmpty(ps));
	//if (ps->size)
	//{
	//	printf("队列为空，无法出队列\n");
	//	return;
	//}
	if (ps->read == ps->tail)
	{
		free(ps->read);
		ps->read = ps->tail = NULL;
		ps->size--;
	}
	else
	{
		Qnode* after = ps->read;
		ps->read = ps->read->next;
		free(after);
		after = NULL;
		ps->size--;
	}
}
//查看队列中的元素个数
void Queuesize(Queue* ps)
{
	assert(ps);

	printf("队列中还剩%d个数据\n", ps->size);
}
//判断队列是否为空
bool QueueEmpty(Queue* ps)
{
	assert(ps);

	return ps->size;
}
//查看队首
QDataType QueueFront(Queue* ps)
{
	assert(ps);
	assert(QueueEmpty(ps));

	return ps->read->a;
}
//查看队尾
QDataType QueueBack(Queue* ps)
{
	assert(ps);
	assert(QueueEmpty(ps));

	return ps->tail->a;
}
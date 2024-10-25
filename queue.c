#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"

//�����½ڵ�
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

//��ʼ��
void QueueInit(Queue* ps)
{
	assert(ps);

	ps->read = NULL;
	ps->size = 0;
	ps->tail = NULL;
}

//���ٶ���
void QueueDestroy(Queue* ps)
{
	assert(ps);
	free(ps->read);
	free(ps->tail);
	ps->read = NULL;
	ps->tail = NULL;
	ps->size = 0;
}

//�����
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

//������
void Queuepop(Queue* ps)
{
	assert(ps);
	assert(QueueEmpty(ps));
	//if (ps->size)
	//{
	//	printf("����Ϊ�գ��޷�������\n");
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
//�鿴�����е�Ԫ�ظ���
void Queuesize(Queue* ps)
{
	assert(ps);

	printf("�����л�ʣ%d������\n", ps->size);
}
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* ps)
{
	assert(ps);

	return ps->size;
}
//�鿴����
QDataType QueueFront(Queue* ps)
{
	assert(ps);
	assert(QueueEmpty(ps));

	return ps->read->a;
}
//�鿴��β
QDataType QueueBack(Queue* ps)
{
	assert(ps);
	assert(QueueEmpty(ps));

	return ps->tail->a;
}
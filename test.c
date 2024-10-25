#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"

void Print(Queue* ps)
{
	printf("��ͷ����Ϊ->%d\n", QueueFront(ps));
	printf("��β����Ϊ->%d\n", QueueBack(ps));
}
int main()
{
	//��������
	Queue queue;

	//��ʼ��
	QueueInit(&queue);

	//�����
	Queuepush(&queue, 1);
	Queuepush(&queue, 2);
	Queuepush(&queue, 3);
	Queuepush(&queue, 4);
	Queuesize(&queue);
	Print(&queue);

	//������
	Queuepop(&queue);
	//�鿴�����е�Ԫ�ظ���
	Queuesize(&queue);
	Print(&queue);

	Queuepush(&queue, 5);
	Queuesize(&queue);
	Print(&queue);

	//���ٶ���
	QueueDestroy(&queue);
	return 0;
}
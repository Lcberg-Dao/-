#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"

void Print(Queue* ps)
{
	printf("队头数据为->%d\n", QueueFront(ps));
	printf("队尾数据为->%d\n", QueueBack(ps));
}
int main()
{
	//创建队列
	Queue queue;

	//初始化
	QueueInit(&queue);

	//入队列
	Queuepush(&queue, 1);
	Queuepush(&queue, 2);
	Queuepush(&queue, 3);
	Queuepush(&queue, 4);
	Queuesize(&queue);
	Print(&queue);

	//出队列
	Queuepop(&queue);
	//查看队列中的元素个数
	Queuesize(&queue);
	Print(&queue);

	Queuepush(&queue, 5);
	Queuesize(&queue);
	Print(&queue);

	//销毁队列
	QueueDestroy(&queue);
	return 0;
}
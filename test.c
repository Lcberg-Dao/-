#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"

int main()
{
	SL s;
	//�ṹ���ʼ��
	SListInit(&s);

	//β��
	SListPushBack(&s, 10);
	SListPushBack(&s, 20);
	SListPushBack(&s, 30);
	SListPushBack(&s, 40);
	SListPushBack(&s, 50);
	SListPushBack(&s, 60);
	SListPushBack(&s, 70);

	//��ӡ����
	Print(&s);

	//βɾ
	SListPopBack(&s);
	Print(&s);

	//ͷ��
	SListPushFront(&s, 1);
	//��ӡ����
	Print(&s);

	//ͷɾ
	SListPopFront(&s);
	Print(&s);


	//��������
	int n;
	scanf("%s", &n);
	if (n == 0)
	{
		SListDestroy(&s);
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1

#include "slist.h"

int main()
{
	SListNode* plist = NULL;

	//β��
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	//��ӡ����
	SListPrint(plist);
	//ͷ��
	SListPushFront(&plist, 0);
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);
	SListPrint(plist);
	//βɾ
	SListPopBack(&plist);
	SListPrint(plist);
	//ͷɾ
	SListPopFront(&plist);
	SListPrint(plist);
	//����
	SListNode* search = SListFind(plist, 2);
	SListPrint(search);
	//�Ȳ���λ����ɾ�����߲���
	//��pos�����x
	//SListInsertAfter(&plist, search, 10);
	//SListPrint(plist);
	//ɾ��posλ��֮���ֵ
	//SListEraseAfter(plist, 10);

	return 0;
}

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

	//�Ȳ���λ����ɾ�����߲���
	//��Posλ��֮ǰ����
	SListInerTerlist(&plist, search, 20);
	SListPrint(plist);

	//ɾ��pos֮ǰ��ֵ
	search = SListFind(plist, 2);
	SListEraseTerlist(&plist, search);
	search = NULL;
	SListPrint(plist);

	//��pos֮�����
	search = SListFind(plist, 4);
	SListInsertAfter(search, 80);
	SListPrint(plist);

	//ɾ��pos���������
	search = SListFind(plist, 2);
	SListEraseAfter(search);
	SListPrint(plist);

	//��������
	SLTDestroy(&plist);
	return 0;
}

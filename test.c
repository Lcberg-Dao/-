#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"

int main()
{
	//�����ڱ�λ����ʼ��
	ListNode* dlist = ListCreate();
	
	// ˫������β��
	ListPushBack(dlist, 1);
	ListPushBack(dlist, 2);
	ListPushBack(dlist, 3);
	ListPushBack(dlist, 4);
	ListPushBack(dlist, 5);
	ListPushBack(dlist, 6);
	//��ӡ
	ListPrint(dlist);

	//βɾ
	ListPopBack(dlist);
	ListPrint(dlist);
	ListPopBack(dlist);
	ListPrint(dlist);
	ListPopBack(dlist);
	ListPrint(dlist);
	
	//ͷ��
	ListPushFront(dlist, 1);
	ListPrint(dlist);
	ListPushFront(dlist, 2);
	ListPrint(dlist);
	ListPushFront(dlist, 3);
	ListPrint(dlist);
	ListPushFront(dlist, 4);
	ListPrint(dlist);
	ListPushFront(dlist, 5);
	ListPrint(dlist);
	ListPushFront(dlist, 6);
	ListPrint(dlist);

	//ͷɾ
	ListPopFront(dlist);
	ListPopFront(dlist);
	ListPopFront(dlist);
	ListPrint(dlist);

	//����
	ListNode* pos = ListFind(dlist, 1);
	//��posǰ�����x
	ListInsert(pos, 2);
	ListPrint(dlist);

	//����
	pos = ListFind(dlist, 2);
	// ˫������ɾ��posλ�õĽڵ�
	ListErase(pos);
	ListPrint(dlist);

	return 0;
}
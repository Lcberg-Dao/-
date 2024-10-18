#define _CRT_SECURE_NO_WARNINGS 1

#include "slist.h"

//�ڶ�̬�ڴ�����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//�������ӡ
void SListPrint(SListNode* plist)
{
	if (plist == NULL)
	{
		return 1;
	}
	SListNode* tail = plist;
	while (tail != NULL)
	{
		printf("->%d", tail->data);
		tail = tail->next;
	}
	printf("\n");
}

//������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* addnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = addnode;
	}
	//��β
	else
	{
		SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = addnode;
	}
}

 //�������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* addnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = addnode;
	}
	else
	{
		SListNode* tail = *pplist;
		*pplist = addnode;
		(*pplist)->next = tail;
	}
}


//������βɾ
void SListPopBack(SListNode** pplist)
{
	assert(*pplist != NULL);

	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* tail = *pplist;
		SListNode* listnode = NULL;
		while (tail->next != NULL)
		{
			listnode = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		listnode->next = NULL;
	}
}


//ͷɾ
void SListPopFront(SListNode** pplist)
{
	assert((*pplist) != NULL);

	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* listnode = *pplist;
		*pplist = (*pplist)->next;
		free(listnode);
		listnode = NULL;
	}
}

//������Ĳ���
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);

	SListNode* seardata = plist;
	//��¼λ��
	int count = 0;
	while (seardata != NULL)
	{
		count++;
		if (seardata->data == x)
		{
			printf("->%d�ڵ�%d���ڵ�λ��\n", x, count);
			return seardata;
		}
		else
		{
			seardata = seardata->next;
		}
	}
	printf("������û�������\n");
}

//// ��������posλ��֮�����x
//void SListInsertAfter(SListNode** pplist,SListNode* pos, SLTDateType x)
//{
//	SListNode* tail = *pplist;
//	SListNode* listnode = NULL;
//	SListNode* addnode = BuySListNode(x);
//	while (tail != pos)
//	{
//		tail = tail->next;
//		listnode = tail;
//	}
//	listnode->next = addnode;
//	addnode->next =tail;
//}

// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos)
{

}
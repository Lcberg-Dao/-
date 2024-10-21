#define _CRT_SECURE_NO_WARNINGS 1

#include "slist.h"

//�ڶ�̬�ڴ�����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return;
	}
	node->data = x;
	node->next = NULL;
	return node;
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
		printf("%d->", tail->data);
		tail = tail->next;
	}
	printf("NULL\n");
}

//������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
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
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* tail = *pplist;
		*pplist = newnode;
		(*pplist)->next = tail;
	}
}


//������βɾ
void SListPopBack(SListNode** pplist)
{
	assert(pplist);
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
	assert(pplist);
	assert(*pplist);

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
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//��pos֮ǰ����x
void SListInerTerlist(SListNode** pplist, SListNode* pos, SLTDateType x)
{
	assert(pos);
	assert(pplist);
	assert(*pplist);

	if (pos == *pplist)
	{
		SListPushFront(pplist, x);
	}
	else
	{
		SListNode* prev = *pplist;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SListNode* newnode = BuySListNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}

// �ڵ�����ɾ��pos֮ǰ��ֵ
void SListEraseTerlist(SListNode** pplist, SListNode* pos)
{
	assert(pplist);
	assert(*pplist);
	assert(pos);
	if (pos == *pplist)
	{
		printf("pos֮ǰû������\n");
		return NULL;
	}
	else
	{
		SListNode* prev = *pplist;
		SListNode* scr = NULL;
		if (prev->next == pos)
		{
			*pplist = (*pplist)->next;
			prev = NULL;
			return;
		}
		else
		{
			while (prev->next != pos)
			{
				scr = prev;
				prev = prev->next;
			}
			scr->next = pos;
			free(prev);
		}
	}
}

// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* prev = pos->next;
	SListNode* newnode = BuySListNode(x);
	if (pos->next == NULL)
	{
		pos->next = newnode;
	}
	else
	{
		newnode->next = prev;
		pos->next = newnode;
	}
}

// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		printf("pos����û������\n");
		return;
	}
	else
	{
		SListNode* prev = pos->next;
		if (prev->next == NULL)
		{
			pos->next = NULL;
			free(prev);
			prev = NULL;
		}
		else
		{
			pos->next = prev->next;
			free(prev);
			prev = NULL;
		}
	}
}

//��������
void SLTDestroy(SListNode** pplist)
{
	assert(pplist);
	SListNode* tail = *pplist;
	while (tail)
	{
		SListNode* next = tail->next;
		free(tail);
		tail = next;
	}
	*pplist = NULL;
	printf("����������\n");
}

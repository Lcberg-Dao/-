#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define NUM 4

typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* a;
	int size;
	int capacity;
}SL;

// �����ݵĹ���:��ɾ��� 
//�ṹ���ʼ��
void SListInit(SL* ps);
//��̬�ڴ���������
void SListDestroy(SL* ps);

//��ӡ
void Print(SL* ps);

//β��
void SListPushBack(SL* ps, SLDateType x);
//ͷ��
void SListPushFront(SL* ps, SLDateType x);
//ͷɾ
void SListPopFront(SL* ps);
//βɾ
void SListPopBack(SL* ps);

//// ˳������
//int SListFind(SL* ps, SLDateType x);
//// ˳�����posλ�ò���x
//void SListInsert(SL* ps, int pos, SLDateType x);
//// ˳���ɾ��posλ�õ�ֵ
//void SListErase(SL* ps, int pos);
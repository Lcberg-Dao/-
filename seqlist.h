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

// 对数据的管理:增删查改 
//结构体初始化
void SListInit(SL* ps);
//动态内存数据销毁
void SListDestroy(SL* ps);

//打印
void Print(SL* ps);

//尾插
void SListPushBack(SL* ps, SLDateType x);
//头插
void SListPushFront(SL* ps, SLDateType x);
//头删
void SListPopFront(SL* ps);
//尾删
void SListPopBack(SL* ps);

//// 顺序表查找
//int SListFind(SL* ps, SLDateType x);
//// 顺序表在pos位置插入x
//void SListInsert(SL* ps, int pos, SLDateType x);
//// 顺序表删除pos位置的值
//void SListErase(SL* ps, int pos);
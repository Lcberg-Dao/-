#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int STDatatype;
typedef struct Stack
{
	int* a;
	int top;//top =0 指向栈顶元素下一个元素位置，top=-1指向栈顶
	int capacity;
}ST;

//栈初始化
void STInit(ST* para);
//销毁栈
void STdestroy(ST* para);
//入栈
void STpush(ST* para, STDatatype x);
//出栈
void STpop(ST* para);
//栈中数据的个数
void STsize(ST* para);
//判断栈是否为空
bool STempty(ST* para);
//查询栈顶元素
STDatatype STTop(ST* para);


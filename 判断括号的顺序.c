//typedef char STDatatype;
//typedef struct Stack
//{
//	STDatatype* a;
//	int top;//top =0 指向栈顶元素下一个元素位置，top=-1指向栈顶
//	int capacity;
//}ST;
//
//bool STempty(ST* para)
//{
//	assert(para);
//
//	return para->top == -1;
//}
//
//栈初始化
//void STInit(ST* para)
//{
//	assert(para);
//
//	para->a = (STDatatype*)malloc(sizeof(STDatatype) * 4);
//	para->capacity = 4;
//	para->top = -1;
//}
//
//销毁栈
//void STdestroy(ST* para)
//{
//	assert(para);
//	free(para->a);
//	para->capacity = 0;
//	para->top = -1;
//}
//
//入栈
//void STpush(ST* para, STDatatype x)
//{
//	assert(para);
//	if (para->top == para->capacity)
//	{
//		para->capacity = para->capacity * 2;
//		STDatatype* new = (STDatatype*)realloc(para->a, sizeof(STDatatype) * (para->capacity));
//        if(new == NULL)
//        {
//            perror("realloc:");
//        }
//        para->a = new;
//	}
//    else
//    {
//	    para->top++;
//	    para->a [para->top ] = x;
//    }
//
//}
//
//出栈
//void STpop(ST* para)
//{
//	assert(para);
//	assert(!STempty(para));
//
//	para->top--;
//}
//
//栈顶元素
//STDatatype STTop(ST* para)
//{
//	assert(para);
//	assert(!STempty(para));
//
//	return para->a[para->top];
//}
//
//bool isValid(char* s) 
//{
//    ST stack;
//    STInit(&stack);
//
//    while(*s)
//    {
//        if(*s == '{'|| *s == '('|| *s == '[')
//        {
//            STpush(&stack, *s);
//        }
//        else
//        {
//            if(STempty(&stack))
//            {
//                return false;
//            }
//            char top = STTop(&stack);
//            if(top =='('&& *s == ')'||top =='{'&& *s == '}'||top =='['&& *s == ']')
//            {
//                STpop(&stack);
//            }
//            else
//            {
//                return false;
//            }
//        }
//        s++;
//    }
//    if(!STempty(&stack))
//    {
//        return false;
//    }
//    return true;
//    STdestroy(&stack); 
//}
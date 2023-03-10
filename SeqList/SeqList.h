#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//// 静态数组
//typedef int SLDataType;  // 顺序表想管理int、char、double类型数组在这里改即可
//                         // 或者存通讯录改成ContactInfo，ContactInfo结构体得提前定义
//
//#define N 100  // 静态数组的最大容量N为100
//
//typedef struct SeqList  // 加上typedef重定义结构体，否则创建结构体书写太长麻烦
//{                       // 创建结构体从struct SeqList ps变成SL ps，简单很多
//
//	SLDataType a[N];  // []内最好不要用数字，否则以后改数组长度麻烦，用define定义标识符常量
//	                  // 最好不要用int，否则顺序表想存字符或其他结构修改麻烦，用typedef重定义
//
//	int size;  // 表示数组中存储了多少个数据
//
//}SL;


// 动态数组
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;  // 指针指向动态开辟的数组
	                // 可以malloc动态开辟数组，realloc实现扩容，free释放空间

	int size;  // 表示数组中存储了多少个数据

	int capacity;  // 数组实际能存数据的空间容量是多大（不是字节数，是数据个数）
}SL;


//接口函数
void SeqListInit(SL* ps);
void SeqListDestroy(SL* ps);
void SeqListPrint(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
int SeqListFind(SL* ps, SLDataType x);
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);

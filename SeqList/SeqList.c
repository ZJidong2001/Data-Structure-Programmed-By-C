#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

// 顺序表初始化
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}


// 顺序表销毁
void SeqListDestroy(SL* ps)
{
	// 内存空间是在堆上malloc、realloc开辟的，如果不用了不及时销毁的话会造成内存泄漏
	free(ps->a);  // 把开辟的空间free掉，将空间归还给系统
	ps->a = NULL; // 防止野指针乱指其他空间
	ps->size = ps->capacity = 0;
}


// 顺序表打印
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}


// 检查空间，如果满了，进行增容
void SeqListCheckCapacity(SL* ps)
{
	// 如果没有空间或空间不足，我们就扩容
	if (ps->size == ps->capacity)
	{
		// 动态数组扩容最好不要一个一个增，扩容会有一定程度的时间消耗
		// 扩二倍是一个比较适中的方式：扩太少会频繁扩容，产生消耗;扩太大会浪费空间
		// 如果没有空间，开辟4个空间;如果已经开辟了空间但空间已满，那就空间扩2倍
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;

		// 我们先定义一个临时数组存放扩容的数组
		// 注意扩容空间不是数据个数，而是字节数，所以newcapacity后面得乘以sizeof(SLDataType)
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));

		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);  // 通过退出函数异常退出（需包含stdlib.h）程序正常退出返回0，-1是程序异常
			           // 不能用return; return只是结束了该函数，程序还会继续运行
		}

		//如果程序运行到这一行，说明空间开辟成功
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}


// 顺序表尾插
void SeqListPushBack(SL* ps, SLDataType x)
{
	// 分析顺序表尾插的过程，可能会出现以下三种情况
	// 1.整个顺序表没有空间
	// 2.空间不够，扩容
	// 3.空间足够，直接插入数据即可
	SeqListCheckCapacity(ps);  // 1.和2.两种情况在扩容函数里均已考虑到并实现

	ps->a[ps->size] = x;
	ps->size++;
}


// 顺序表尾删
void SeqListPopBack(SL* ps)
{
	assert(ps->size > 0);  // 断言函数：条件为真继续执行；条件为假终止程序，断言失败（需包含assert.h）

	ps->size--;
}


// 顺序表头插
void SeqListPushFront(SL* ps, SLDataType x)
{
	// 检查增容
	SeqListCheckCapacity(ps);

	// 挪动元素
	// 因为数据是连续存储的，所以需要将所有数据往后挪，（从后往前依次）依次挪动元素
	int end = ps->size - 1;  // 找到数组的最后一个数据
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}

	ps->a[0] = x;
	ps->size++;
}


// 顺序表头删
void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);  //断言函数，判断数组是否为空

	// 挪动数据
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}

	ps->size--;  // 只ps->size--不行，这样就成尾删了；头删得往前挪动元素，再ps->size--
}


// 顺序表查找返回数组下标
int SeqListFind(SL* ps, SLDataType x)
{
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}

	return -1;
}


// 顺序表在pos下标位置插入x
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	// pos取值范围是[0,ps->size]，超出该范围pos非法
	assert(pos >= 0 && pos <= ps->size);

	// 检查空间是否足够
	SeqListCheckCapacity(ps);

	// 挪动数据
	int end = ps->size - 1;
	while (end >= pos) {
		ps->a[end + 1] = ps->a[end];
		--end;
	}

	ps->a[pos] = x;
	ps->size++;
}

// 顺序表删除pos下标位置的值
void SeqListErase(SL* ps, int pos)
{
	// pos取值范围是[0,ps->size-1],超出该范围pos非法
	// 这句代码既判断了pos是否合法，也判断了数组是否为空，请读者仔细思考
	assert(pos >= 0 && pos < ps->size);

	// 挪动数据
	int begin = pos + 1;
	while (begin < ps->size) {
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}

	ps->size--;
}
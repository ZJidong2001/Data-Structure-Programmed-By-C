#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

// ˳����ʼ��
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}


// ˳�������
void SeqListDestroy(SL* ps)
{
	// �ڴ�ռ����ڶ���malloc��realloc���ٵģ���������˲���ʱ���ٵĻ�������ڴ�й©
	free(ps->a);  // �ѿ��ٵĿռ�free�������ռ�黹��ϵͳ
	ps->a = NULL; // ��ֹҰָ����ָ�����ռ�
	ps->size = ps->capacity = 0;
}


// ˳����ӡ
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}


// ���ռ䣬������ˣ���������
void SeqListCheckCapacity(SL* ps)
{
	// ���û�пռ��ռ䲻�㣬���Ǿ�����
	if (ps->size == ps->capacity)
	{
		// ��̬����������ò�Ҫһ��һ���������ݻ���һ���̶ȵ�ʱ������
		// ��������һ���Ƚ����еķ�ʽ����̫�ٻ�Ƶ�����ݣ���������;��̫����˷ѿռ�
		// ���û�пռ䣬����4���ռ�;����Ѿ������˿ռ䵫�ռ��������ǾͿռ���2��
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;

		// �����ȶ���һ����ʱ���������ݵ�����
		// ע�����ݿռ䲻�����ݸ����������ֽ���������newcapacity����ó���sizeof(SLDataType)
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));

		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);  // ͨ���˳������쳣�˳��������stdlib.h�����������˳�����0��-1�ǳ����쳣
			           // ������return; returnֻ�ǽ����˸ú��������򻹻��������
		}

		//����������е���һ�У�˵���ռ俪�ٳɹ�
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}


// ˳���β��
void SeqListPushBack(SL* ps, SLDataType x)
{
	// ����˳���β��Ĺ��̣����ܻ���������������
	// 1.����˳���û�пռ�
	// 2.�ռ䲻��������
	// 3.�ռ��㹻��ֱ�Ӳ������ݼ���
	SeqListCheckCapacity(ps);  // 1.��2.������������ݺ�������ѿ��ǵ���ʵ��

	ps->a[ps->size] = x;
	ps->size++;
}


// ˳���βɾ
void SeqListPopBack(SL* ps)
{
	assert(ps->size > 0);  // ���Ժ���������Ϊ�����ִ�У�����Ϊ����ֹ���򣬶���ʧ�ܣ������assert.h��

	ps->size--;
}


// ˳���ͷ��
void SeqListPushFront(SL* ps, SLDataType x)
{
	// �������
	SeqListCheckCapacity(ps);

	// Ų��Ԫ��
	// ��Ϊ�����������洢�ģ�������Ҫ��������������Ų�����Ӻ���ǰ���Σ�����Ų��Ԫ��
	int end = ps->size - 1;  // �ҵ���������һ������
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}

	ps->a[0] = x;
	ps->size++;
}


// ˳���ͷɾ
void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);  //���Ժ������ж������Ƿ�Ϊ��

	// Ų������
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}

	ps->size--;  // ֻps->size--���У������ͳ�βɾ�ˣ�ͷɾ����ǰŲ��Ԫ�أ���ps->size--
}


// ˳�����ҷ��������±�
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


// ˳�����pos�±�λ�ò���x
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	// posȡֵ��Χ��[0,ps->size]�������÷�Χpos�Ƿ�
	assert(pos >= 0 && pos <= ps->size);

	// ���ռ��Ƿ��㹻
	SeqListCheckCapacity(ps);

	// Ų������
	int end = ps->size - 1;
	while (end >= pos) {
		ps->a[end + 1] = ps->a[end];
		--end;
	}

	ps->a[pos] = x;
	ps->size++;
}

// ˳���ɾ��pos�±�λ�õ�ֵ
void SeqListErase(SL* ps, int pos)
{
	// posȡֵ��Χ��[0,ps->size-1],�����÷�Χpos�Ƿ�
	// ��������ж���pos�Ƿ�Ϸ���Ҳ�ж��������Ƿ�Ϊ�գ��������ϸ˼��
	assert(pos >= 0 && pos < ps->size);

	// Ų������
	int begin = pos + 1;
	while (begin < ps->size) {
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}

	ps->size--;
}
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//// ��̬����
//typedef int SLDataType;  // ˳��������int��char��double��������������ļ���
//                         // ���ߴ�ͨѶ¼�ĳ�ContactInfo��ContactInfo�ṹ�����ǰ����
//
//#define N 100  // ��̬������������NΪ100
//
//typedef struct SeqList  // ����typedef�ض���ṹ�壬���򴴽��ṹ����д̫���鷳
//{                       // �����ṹ���struct SeqList ps���SL ps���򵥺ܶ�
//
//	SLDataType a[N];  // []����ò�Ҫ�����֣������Ժ�����鳤���鷳����define�����ʶ������
//	                  // ��ò�Ҫ��int������˳�������ַ��������ṹ�޸��鷳����typedef�ض���
//
//	int size;  // ��ʾ�����д洢�˶��ٸ�����
//
//}SL;


// ��̬����
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;  // ָ��ָ��̬���ٵ�����
	                // ����malloc��̬�������飬reallocʵ�����ݣ�free�ͷſռ�

	int size;  // ��ʾ�����д洢�˶��ٸ�����

	int capacity;  // ����ʵ���ܴ����ݵĿռ������Ƕ�󣨲����ֽ����������ݸ�����
}SL;


//�ӿں���
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

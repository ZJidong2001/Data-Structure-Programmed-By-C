#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

void menu()
{
	printf("***********************************\n");
	printf("    1.˳���β��                   \n");
	printf("    2.˳���βɾ                   \n");
	printf("    3.˳���ͷ��                   \n");
	printf("    4.˳���ͷɾ                   \n");
	printf("    5.˳�����ҷ��������±�       \n");
	printf("    6.˳�����pos�±�λ�ò���x     \n");
	printf("    7.˳���ɾ��pos�±�λ�õ�ֵ    \n");
	printf("    0.�˳�����                     \n");
	printf("***********************************\n");
}

int main()
{
	SL sl;
	SeqListInit(&sl);
	
	int input = 0;
	int x = 0;
	int pos = 0;

	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &x);
			SeqListPushBack(&sl, x);
			SeqListPrint(&sl);
			break;
		case 2:
			SeqListPopBack(&sl);
			SeqListPrint(&sl);
			break;
		case 3:
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &x);
			SeqListPushFront(&sl, x);
			SeqListPrint(&sl);
			break;
		case 4:
			SeqListPopFront(&sl);
			SeqListPrint(&sl);
			break;
		case 5:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &x);
			SeqListPrint(&sl);
			printf("��Ҫ���ҵ�ֵ�����±�Ϊ%d\n", SeqListFind(&sl, x));
			break;
		case 6:
			SeqListPrint(&sl);
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &x);
			printf("������Ҫ������±�:>");
			scanf("%d", &pos);
			SeqListInsert(&sl, pos, x);
			SeqListPrint(&sl);
			break;
		case 7:
			SeqListPrint(&sl);
			printf("������Ҫɾ�����±�:>");
			scanf("%d", &pos);
			SeqListErase(&sl, pos);
			SeqListPrint(&sl);
			break;
		case 0:
			SeqListDestroy(&sl);
			printf("�����˳�\n");
			break;
		default:
			printf("�����������������\n");
			break;

		}
	} while (input);
	return 0;
}
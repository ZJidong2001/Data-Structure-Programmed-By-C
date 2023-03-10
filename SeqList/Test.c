#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

void menu()
{
	printf("***********************************\n");
	printf("    1.顺序表尾插                   \n");
	printf("    2.顺序表尾删                   \n");
	printf("    3.顺序表头插                   \n");
	printf("    4.顺序表头删                   \n");
	printf("    5.顺序表查找返回数组下标       \n");
	printf("    6.顺序表在pos下标位置插入x     \n");
	printf("    7.顺序表删除pos下标位置的值    \n");
	printf("    0.退出程序                     \n");
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
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入要插入的值:>");
			scanf("%d", &x);
			SeqListPushBack(&sl, x);
			SeqListPrint(&sl);
			break;
		case 2:
			SeqListPopBack(&sl);
			SeqListPrint(&sl);
			break;
		case 3:
			printf("请输入要插入的值:>");
			scanf("%d", &x);
			SeqListPushFront(&sl, x);
			SeqListPrint(&sl);
			break;
		case 4:
			SeqListPopFront(&sl);
			SeqListPrint(&sl);
			break;
		case 5:
			printf("请输入要查找的值:>");
			scanf("%d", &x);
			SeqListPrint(&sl);
			printf("您要查找的值数组下标为%d\n", SeqListFind(&sl, x));
			break;
		case 6:
			SeqListPrint(&sl);
			printf("请输入要插入的值:>");
			scanf("%d", &x);
			printf("请输入要插入的下标:>");
			scanf("%d", &pos);
			SeqListInsert(&sl, pos, x);
			SeqListPrint(&sl);
			break;
		case 7:
			SeqListPrint(&sl);
			printf("请输入要删除的下标:>");
			scanf("%d", &pos);
			SeqListErase(&sl, pos);
			SeqListPrint(&sl);
			break;
		case 0:
			SeqListDestroy(&sl);
			printf("程序退出\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;

		}
	} while (input);
	return 0;
}
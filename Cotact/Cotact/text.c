#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)

#include"Contact.h"

void menu()
{
	printf("***************************************************\n");
	printf("******1.Add                     2.Del        ******\n");
	printf("******3.Find                    4.Modify     ******\n");
	printf("******5.Show                    6.Sort       ******\n");
	printf("******0.exit                                 ******\n");
	printf("***************************************************\n");
}

enum options
{
	EXIT,
	ADD,
	DEL,
	FIND,
	MODIFY,
	SHOW,
	SORT
};

int main()
{
	int input = 0;
	int ret = 0;
	Contact con;
	char name[10] = {0};
	InitContact(&con);
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			Add(&con);
			break;
		case DEL:
			Del(&con);
			break;
		case FIND:
			printf("name,please\n");
			scanf("%s", name);
		    Findbyname(&con,name);
			break;	
		case MODIFY:
			Modify(&con);
			break;		
		case SHOW:
			Show(&con);
			break;
		case SORT:
			Sort(&con);
			break;
		case EXIT:
			Save(&con);
			Destory(&con);
			break;
		default:
			printf("错误数字，请重新输入\n");
			break;
		}
	} while(input);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)

#include"Contact.h"

//static InitContact vertion
//void InitContact(Contact* pc)
//{
//	pc->count= 0;
//	memset(pc->date, 0, sizeof(pc->date));
//}
// done


void Is_expend(Contact* pc)
{
	if (pc->count == pc->capacity)
	{
		Contact* ptr = (Contact*)realloc(pc->date, DEFAULT_INC * sizeof(PeopInfo));
		if (ptr == NULL)
		{
			printf(" Is_expend::%s", strerror(errno));
		}
		pc->date = ptr;
		printf("增容成功\n");
	}

	return;
}

void LoadContact( Contact* pc)
{
	printf("loading Contact...\n");
	FILE* pf = fopen("Contact.txt", "rb");
	if (pf == NULL)
	{
		perror("LoadContact");
		return 1;
	}
	PeopInfo tmp = { 0 };
	while (fread(&tmp, sizeof(Contact), 1, pf) == 1)
	{
		Is_expend(pc);
		pc->date[pc->count] = tmp;
		pc->count++;
	}
	printf("load finish\n");
	fclose(pf);
	pf = NULL;

}

//dynamic InitContact vertion
void InitContact(Contact* pc)
{
	
	pc->capacity = DEFAULT;
	pc->count = 0;
	pc->date = (Contact*)calloc(DEFAULT, sizeof(PeopInfo));
	if (pc->date == NULL)
	{
		printf("InitContact::%s", strerror(errno));
		return 1;
	}
	LoadContact(pc);
}
// done

void Destory(Contact* pc)
{
	free(pc->date);
	pc->date = NULL;
}

//static Add vertion
//void Add(Contact *pc)
//{
//	printf("name,please\n");
//	scanf("%s", pc->date[pc->count].name);
//	printf("sex,please\n");
//	scanf("%s", pc->date[pc->count].sex);
//	printf("tele,please\n");
//	scanf("%s", pc->date[pc->count].tele);                	                     
//	pc->count++;
//	printf("add,success\n");
//}
// done


//dynamic Add vertion


void Add(Contact* pc)
{ 
	Is_expend(pc);
	printf("name,please\n");
	scanf("%s", pc->date[pc->count].name);
	printf("sex,please\n");
	scanf("%s", pc->date[pc->count].sex);
	printf("tele,please\n");
	scanf("%s", pc->date[pc->count].tele);                	                     
	pc->count++;
	printf("add,success\n");
}
// done

void Show(const Contact* pc)
{
	printf("%-5s\t%-5s\t%-5s\t%-10s\t", "序号", "姓名", "性别", "电话"); 
	printf("\n");
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		printf("%-5d\t%-5s\t%-5s\t%-10s\n", 
			(i + 1),
			pc->date[i].name,
			pc->date[i].sex,
			pc->date[i].tele);
	}

}

int Findbyname(const Contact* pc,char name[])
{
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(name, pc->date[i].name) == 0)
		{
			printf("查找成功\n");
			printf("%-5s\t%-5s\t%-5s\t%-10s\t", "序号", "姓名", "性别", "电话");
			printf("\n");
			printf("%-5d\t%-5s\t%-5s\t%-10s\t\n",
				(i+1),
				pc->date[i].name,
				pc->date[i].sex,
				pc->date[i].tele);
			return i;
		}	
	}
	printf("查找失败\n");
	return -1;	
}

void Del(Contact* pc)
{
	int ret = 0;
	int i = 0;
	char input = 0;
	char name[10];
	printf("name,please\n");
	scanf("%s", name);
	getchar();
	ret = Findbyname(pc, name);
	printf("确认删除y,取消n\n");
	scanf("%c", &input);
	switch (input)
	{
	case 'y':
		for (i = ret; i < pc->count; i++)
		{
			pc->date[i] = pc->date[i + 1];
	}
		printf("del,success\n");
		break;
	case'n':
		break;
	default:
		printf("wromg choose\n");
		break;
	}

}

void Modify(Contact* pc)
{
	int ret = 0;
	char name[10] = { 0 };
	printf("name,please\n");
	scanf("%s", name);
	ret = Findbyname(pc, name);
	printf("name,please\n");
	scanf("%s", pc->date[ret].name);
	printf("sex,please\n");
	scanf("%s", pc->date[ret].sex);
	printf("tele,please\n");
	scanf("%s", pc->date[ret].tele);
	printf("done\n");

}

int cmp_name(const void* e1,const void* e2)
{
	return strcmp(((PeopInfo*)e1)->name, ((PeopInfo*)e2)->name);

}

void Sort(Contact* pc)
{
	qsort(pc->date, pc->count, sizeof(PeopInfo), cmp_name);
		printf("success\n");
}

void Save(Contact* pc)
{
	FILE* pWrite = fopen("Contact.txt", "wb");
	if (pWrite == NULL)
	{
		perror("Save");
		return 1;
	}
	fwrite(pc, sizeof(Contact), pc->count, pWrite);
	perror("fwrite");
	fclose(pWrite);
	pWrite = NULL;
	printf("save success\n");
}
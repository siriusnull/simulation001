#include"game.h"

void meue(void)
{
	printf("----------------------\n");
	printf("----1.play   0.exit---\n");
	printf("----------------------\n");
}
void game()
{

	char mine[ROWS][COLS] = {0};//存放已经有的雷
	char show[ROWS][COLS] = {0};//存放排查出的雷信息
	//初始化内容为指定内容mine数组为‘0’
	InitBoard(mine, ROWS, COLS,'0');
	//show数组为‘*’,多引入一个参数来区分初始化内容的不同
	InitBoard(show, ROWS, COLS,'*');
	//设雷,只需要9*9
	SetMine(mine, ROW, COL);
	//打印查看初始化内容只需要9*9的内容 
	DisplayBoard(show, ROW, COL);
	//排查雷，有雷结束，没雷跟新show
	FindMine(show, mine, ROW, COL);

}


int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
	meue();
	printf("make a choose:>\n");
	scanf_s("%d", &input);
	switch (input)
	{
	case 1:
		game();
	case 0:
		break;
	default:
		printf("input again\n");
	}

	} while (input);
	return 0;
}
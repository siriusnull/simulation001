#include"game.h"

void game()
{
	int ret = 0;
	char board[ROW][COL] = {0};//创建完记得初始化
	InitBoard(board, ROW, COL);
	DispalyBoard(board, ROW, COL);
	while(1)
	{
		PlayerMove(board, ROW, COL);
		ret=IsWin(board, ROW, COL);//判断输赢
		if (ret != 'c')
		{
			break;//将其他判断放进循环会让循环提前结束
		}
		DispalyBoard(board, ROW, COL);
		ComputerMove(board, ROW, COL);
		ret=IsWin(board, ROW, COL);//判断输赢
		if (ret != 'c')
		{
			break;
		}
		DispalyBoard(board, ROW, COL);
	}
	if (ret == '#')
	{
		printf("玩家赢\n");
		DispalyBoard(board, ROW, COL);

	}
	else if (ret == '*')
	{
		printf("电脑赢\n");
		DispalyBoard(board, ROW, COL);

	}
	else if (ret == 'q')
	{
		printf("平局\n");
		DispalyBoard(board, ROW, COL);
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int input=0;
	do{
		meun();//打印菜单
		printf("请输入:>\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("game on\n");
			game();
			break;
		case 0:
			printf("game off\n");
			break;
		default:
			printf("wrong number\n");
			break;
		}
	} while (input);

	
	return 0;
}

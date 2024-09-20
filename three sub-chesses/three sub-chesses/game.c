#include"game.h"
void  meun()
{
		printf("------------------\n");
		printf("--1.start 0.exit--\n");
		printf("------------------\n");	
}


void InitBoard(char board[ROW][COL], int row, int col)
{

	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
			board[i][j] = ' ';
	}
}


void DispalyBoard(char board[ROW][COL], int row, int col) 
{
	int i = 0;
	int j = 0;
	//外层循环打印行
	for(i=0;i<row;i++)
	{
		//内层循环打印一行的每一列
		for(j=0;j<col;j++)
		{
			//“ # | # | #|”
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//打印分割符
		//---|---|---
			for (j = 0; j < col; j++)
			{
				printf("---", board[i][j]);
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
	}

}


void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("玩家下棋，请输入坐标x，y\n");
	int x = 0, y = 0;
	while (1)//坐标不合法需要重复输入，合法跳出
	{
	    scanf_s("%d%d", &x, &y);
		if (x <= 3 && y <= 3 && x > 0 && y > 0)//判断坐标大小合法
		{
			if (board[x - 1][y - 1] == ' ')//判断坐标是否被占用
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
				printf("坐标被占用，请重新输入\n");
		}
		else
			printf("坐标不合法\n");
	}
	
}


void RandMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋:>\n");
	int x = 0;
	int y = 0;
	while(1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '*';
			break;
		}
	}
}


int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0;i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;	
		}

	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//三个成行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	//三个成列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[0][0];
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		return board[0][2];

	//判断是否平局
	if (IsFull(board, row, col))
	{
		return 'q';
	}
	return 'c';
}

int IsDefense(char board[ROW][COL], int row, int col)
{
	//判断attack move/rand move/defense move
	//row

	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == '#' && board[i][2] == ' ')
		{
			board[i][2] = '*';
			return 0;
		}
		if (board[i][0] == board[i][1] && board[i][2] == '#' && board[i][1] == ' ')
		{
			board[i][1] = '*';
			return 0;
		}
		if (board[i][1] == board[i][1] && board[i][2] == '#' && board[i][0] == ' ')
		{
			board[i][0] = '*';
			return 0;
		}

	}
	//col
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[0][j] == '#' && board[2][j] == ' ')
		{
			board[2][j] = '*';
			return 0;

		}
		if (board[0][j] == board[2][j] && board[2][j] == '#' && board[1][j] == ' ')
		{
			board[1][j] = '*';
			return 0;
		}
		if (board[1][j] == board[2][j] && board[1][j] == '#' && board[0][j] == ' ')
		{
			board[0][j] = '*';
			return 0;
		}

	}
	//diagonal
	if (board[1][1] == board[0][2] && board[1][1] == '#' && board[2][0] == ' ')
	{
		board[2][0] = '*';
		return 0;
	}
	if (board[1][1] == board[2][0] && board[1][1] == '#' && board[0][2] == ' ')
	{
		board[0][2] = '*';
		return 0;
	}
	if (board[0][2] == board[2][0] && board[2][0] == '#' && board[1][1] == ' ')
	{
		board[1][1] = '*';
		return 0;
	}
	if (board[0][0] == board[2][2] && board[2][2] == '#' && board[1][1] == ' ')
	{
		board[1][1] = '*';
		return 0;
	}
	if (board[1][1] == board[0][0] && board[1][1] == '#' && board[2][2] == ' ')
	{
		board[2][2] = '*';
		return 0;
	}
	if (board[1][1] == board[2][2] && board[1][1] == '#' && board[0][0] == ' ')
	{
		board[0][0] = '*';
		return 0;
	}
	return 1;
}

int IsAttack(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == '*' && board[i][2] == ' ')
		{
			board[i][2] = '#';
			return 0;
		}
		if (board[i][0] == board[i][1] && board[i][2] == '*' && board[i][1] == ' ')
		{
			board[i][1] = '#';
			return 0;
		}
		if (board[i][1] == board[i][1] && board[i][2] == '*' && board[i][0] == ' ')
		{
			board[i][0] = '#';
			return 0;
		}

	}
	//col
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[0][j] == '*' && board[2][j] == ' ')
		{
			board[2][j] = '#';
			return 0;

		}
		if (board[0][j] == board[2][j] && board[2][j] == '*' && board[1][j] == ' ')
		{
			board[1][j] = '#';
			return 0;
		}
		if (board[1][j] == board[2][j] && board[1][j] == '*' && board[0][j] == ' ')
		{
			board[0][j] = '#';
			return 0;
		}

	}
	//diagonal
	if (board[1][1] == board[0][2] && board[1][1] == '*' && board[2][0] == ' ')
	{
		board[2][0] = '#';
		return 0;
	}
	if (board[1][1] == board[2][0] && board[1][1] == '*' && board[0][2] == ' ')
	{
		board[0][2] = '#';
		return 0;
	}
	if (board[0][2] == board[2][0] && board[2][0] == '*' && board[1][1] == ' ')
	{
		board[1][1] = '#';
		return 0;
	}
	if (board[0][0] == board[2][2] && board[2][2] == '*' && board[1][1] == ' ')
	{
		board[1][1] = '#';
		return 0;
	}
	if (board[1][1] == board[0][0] && board[1][1] == '*' && board[2][2] == ' ')
	{
		board[2][2] = '#';
		return 0;
	}
	if (board[1][1] == board[2][2] && board[1][1] == '*' && board[0][0] == ' ')
	{
		board[0][0] = '#';
		return 0;
	}
	return 1;
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int ret1 = 0;
	int ret2 = 0;
	ret1=IsAttack(board, row, col);
	ret2=IsDefense(board, row, col);
	if (ret1&&ret2);
	{
		RandMove(board, row, col);
	}

}







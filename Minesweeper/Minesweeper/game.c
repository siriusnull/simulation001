#include"game.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			board[i][j] = set;
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-----minesweeper  on-----\n");
	//打印列号
	for (j = 0; j <= col; j++)
		printf("%d ",j);
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//答应一下行号
		for (j = 1; j <= col; j++)
			printf("%c ", board[i][j]);
		printf("\n");
	}
	printf("-----minesweeper  off----\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//%9的范围0-8，要求xy 1-9
		int y = rand() % col + 1;
		if(board[x][y] =='0')//注意如果随机坐标生成重复，则会少雷
		{
			board[x][y] = '1';
			count--;
		}
	}

}

int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	return board[x - 1][y - 1] +
		board[x - 1][y] +
		board[x - 1][y + 1] +
		board[x][y - 1] +
		board[x][y + 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] - 8 * '0';
}

void FindMine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("input x and y:>\n");
	int win = 0;//找到非雷的个数
	while(win<row*col- EASY_COUNT)
	{
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("have sweeped\n");
			}
			if (mine[x][y] == '1')
			{
				printf("you lose\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//统计周围的雷，非雷个数加一
				win++;
				int count = get_mine_count(mine, x, y);
				show[x][y] = ('0' + count);//加字符0是为了将int类型转换为字符型
				DisplayBoard(show, row, col);
		
			}
		}
		else
			printf("x,y are not legal\n");
	}
	if (win == row * col - EASY_COUNT)
		printf("game win\n");
	DisplayBoard(mine, row, col);
}





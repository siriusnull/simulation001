#include"game.h"

void game()
{
	int ret = 0;
	char board[ROW][COL] = {0};//������ǵó�ʼ��
	InitBoard(board, ROW, COL);
	DispalyBoard(board, ROW, COL);
	while(1)
	{
		PlayerMove(board, ROW, COL);
		ret=IsWin(board, ROW, COL);//�ж���Ӯ
		if (ret != 'c')
		{
			break;//�������жϷŽ�ѭ������ѭ����ǰ����
		}
		DispalyBoard(board, ROW, COL);
		ComputerMove(board, ROW, COL);
		ret=IsWin(board, ROW, COL);//�ж���Ӯ
		if (ret != 'c')
		{
			break;
		}
		DispalyBoard(board, ROW, COL);
	}
	if (ret == '#')
	{
		printf("���Ӯ\n");
		DispalyBoard(board, ROW, COL);

	}
	else if (ret == '*')
	{
		printf("����Ӯ\n");
		DispalyBoard(board, ROW, COL);

	}
	else if (ret == 'q')
	{
		printf("ƽ��\n");
		DispalyBoard(board, ROW, COL);
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int input=0;
	do{
		meun();//��ӡ�˵�
		printf("������:>\n");
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

#include"game.h"

void meue(void)
{
	printf("----------------------\n");
	printf("----1.play   0.exit---\n");
	printf("----------------------\n");
}
void game()
{

	char mine[ROWS][COLS] = {0};//����Ѿ��е���
	char show[ROWS][COLS] = {0};//����Ų��������Ϣ
	//��ʼ������Ϊָ������mine����Ϊ��0��
	InitBoard(mine, ROWS, COLS,'0');
	//show����Ϊ��*��,������һ�����������ֳ�ʼ�����ݵĲ�ͬ
	InitBoard(show, ROWS, COLS,'*');
	//����,ֻ��Ҫ9*9
	SetMine(mine, ROW, COL);
	//��ӡ�鿴��ʼ������ֻ��Ҫ9*9������ 
	DisplayBoard(show, ROW, COL);
	//�Ų��ף����׽�����û�׸���show
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
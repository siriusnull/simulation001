#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9//ʵ�ʴ洢���ݵ������С9*9
#define COL 9

#define ROWS ROW+2//Ϊ��������ΧһȦ����������
#define COLS COL+2

#define EASY_COUNT 10//����

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);

//���ε�ʱ����Ȼ��11*11����mine��show����11*11�����飬ֻ��row��col����������
//������9����ʾ��ֻʹ��9*9�Ŀռ�
void DisplayBoard(char board[ROWS][COLS], int row, int col);

void SetMine(char board[ROWS][COLS], int row, int col);

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);



#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9//实际存储数据的数组大小9*9
#define COL 9

#define ROWS ROW+2//为了描述周围一圈将数组扩充
#define COLS COL+2

#define EASY_COUNT 10//雷数

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);

//传参的时候依然是11*11数组mine和show就是11*11的数组，只是row，col这两个参数
//可以是9，表示我只使用9*9的空间
void DisplayBoard(char board[ROWS][COLS], int row, int col);

void SetMine(char board[ROWS][COLS], int row, int col);

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);



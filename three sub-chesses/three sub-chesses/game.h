#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3


void meun();


void InitBoard(char board[ROW][COL], int row, int col);


void DispalyBoard (char board[ROW][COL], int row, int col);


void PlayerMove(char board[ROW][COL], int row, int col);


void ComputerMove(char board[ROW][COL], int row, int col);


char IsWin(char board[ROW][COL], int row, int col);


int IsFull(char board[ROW][COL], int row, int col);
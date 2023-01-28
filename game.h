#pragma once

#include <windows.h>
#include <time.h>
#include <stdio.h>

#define ROW 3  //行
#define COL 3  //列

//初始化,将数组元素初始化成空格
void InitBoard(char board[ROW][COL], int row, int col);
//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);
//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);
//判断局势
char isWin(char board[ROW][COL], int row, int col);
//检查是否平局
int isFull(char board[ROW][COL], int row, int col);
#pragma once

#include <windows.h>
#include <time.h>
#include <stdio.h>

#define ROW 3  //��
#define COL 3  //��

//��ʼ��,������Ԫ�س�ʼ���ɿո�
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);
//�������
void PlayerMove(char board[ROW][COL], int row, int col);
//��������
void ComputerMove(char board[ROW][COL], int row, int col);
//�жϾ���
char isWin(char board[ROW][COL], int row, int col);
//����Ƿ�ƽ��
int isFull(char board[ROW][COL], int row, int col);
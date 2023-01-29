#include "game.h"

//初始化
void InitBoard(char board[ROW][COL], int row, int col)
{
	for(int i=0;i<row;i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)//优化*****************显示行列下标
{
	for (int i = 0; i < row; i++)
	{
		
		for (int j = 0; j < col; j++)
		{
				printf(" %c ", board[i][j]);
				if (j < col - 1)
				{
					printf("|");
				}
		}
		printf("\n");

		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("你的回合>\n");
	printf("输入要下的坐标>\n");

	while (true)
	{
		scanf_s("%d%d", &x, &y);
		//判断输入坐标合法性
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			//判断玩家选择的坐标是否有棋子
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("这个位置已经有棋子，请重新下！\n");
			}
		}
		else
		{
			printf("下标不合法，请重新输入！\n");
		}
	}
}

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	printf("对方回合>\n");

	while (true)
	{
		x = rand() % ROW;
		y = rand() % COL;
			//判断玩家选择的坐标是否有棋子
			if (board[x][y] == ' ')
			{
				board[x][y] = '#';
				break;
			}
	}
}

/*判断当前局势:
* 玩家获胜返回 *
* 电脑获胜返回 #
* 平局返回 P
* 继续返回 J*/
char isWin(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{	
		for (int j = 0; j < col; j++)
		{ 
			//一行相等
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			{
				return board[i][0];
			}
			//一列相等
			if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
			{
				return board[0][j];
			}
			//正对角线
			if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
			//反对角线
			if (board[i][col - j - 1] == board[i + 1][col - j - 2] && board[i + 1][col - j - 2] == board[i + 2][col - j - 3] && board[i][col - j - 1] != ' ')//只要任意一个元素不等于空格
			{
				return board[i][col - j - 1];
			}
		}
	}
	
	//检查是否平局,棋盘满1，未满0
	int flag=isFull(board,ROW,COL);
	if (flag == 1)
	{
		return 'P';
	}
	//继续
	return 'J';
}

//检查是否平局,棋盘满返回1，未满返回0
int isFull(char board[ROW][COL], int row, int col)
{
	for(int i=0;i<row;i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
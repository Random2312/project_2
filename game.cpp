#include "game.h"

//��ʼ��
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

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
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

//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("��Ļغ�>\n");
	printf("����Ҫ�µ�����>\n");

	while (true)
	{
		scanf_s("%d%d", &x, &y);
		//�ж���������Ϸ���
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			//�ж����ѡ��������Ƿ�������
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���λ���Ѿ������ӣ��������£�\n");
			}
		}
		else
		{
			printf("�±겻�Ϸ������������룡\n");
		}
	}
}

//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	printf("�Է��غ�>\n");

	while (true)
	{
		x = rand() % ROW;
		y = rand() % COL;
			//�ж����ѡ��������Ƿ�������
			if (board[x][y] == ' ')
			{
				board[x][y] = '#';
				break;
			}
	}
}

/*�жϵ�ǰ����:
* ��һ�ʤ���� *
* ���Ի�ʤ���� #
* ƽ�ַ��� P
* �������� J*/
char isWin(char board[ROW][COL], int row, int col)/************************�˺������Ż�******************************/
{
	//һ�����
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')

			return board[i][0];
	}
	//һ�����
	for (int j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		
			return board[0][j];
	}
	//�Խ������   (�Ż�������������)
	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' '))
		return board[0][0];

	//����Ƿ�ƽ��,������1��δ��0
	int flag=isFull(board,ROW,COL);
	if (flag == 1)
	{
		return 'P';
	}
	//����
	return 'J';
}


//����Ƿ�ƽ��
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
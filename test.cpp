#include "game.h"
//������Ϸ

//��ҳ��
void menu()
{
	printf("--------------------------------------\n");
	printf("------1.play--------------0.exit------\n");
	printf("--------------------------------------\n");
}

//��Ϸ����
void game()
{
	char flag;
	//��������-->����߳���������Ϣ,���в����궨�������ʹ��
	char board[ROW][COL] = { 0 };
	//���̳�ʼ��
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);

	//����
	while (1)
	{
		//�����
		PlayerMove(board,ROW,COL);
		system("cls");
		DisplayBoard(board, ROW, COL);//�������Ӻ���ʾ

		//�жϾ���
		flag=isWin(board, ROW, COL);
		if (flag != 'J')
		{
			break;
		}
		
		//������
		ComputerMove(board, ROW, COL);
		Sleep(1000);
		system("cls");
		DisplayBoard(board, ROW, COL);//�������Ӻ���ʾ

		//�жϾ���
		flag = isWin(board, ROW, COL);
		if (flag != 'J')
		{
			break;
		}
	}

	system("cls");
	//��ʾ��Ϸ���
	if (flag == '*')
	{
		printf("��Ӯ�ˣ�\n");
	}
	if (flag == '#')
	{
		printf("�ٽ�������\n");
	}
	if (flag == 'P')
	{
		printf("ƽ��\n");
	}
	DisplayBoard(board, ROW, COL);

	printf("\n\n������\n");
}

//������Ϸ,���Լ�������ƿ��
void test()
{
	int input = 0;

	//��ʱ������������������
	srand((unsigned int)time(NULL));

	do
	{
		menu();//��ҳ
		printf("��ѡ��:>");
		scanf_s("%d",&input);
		
		system("cls");

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
	system("pause");
}
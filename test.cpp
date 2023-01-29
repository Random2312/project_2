#include "game.h"
//测试游戏

//主页面
void menu()
{
	printf("--------------------------------------\n");
	printf("------1.play--------------0.exit------\n");
	printf("--------------------------------------\n");
}

//游戏代码
void game()
{
	char flag;
	//创建数组-->存放走出的棋盘信息,行列参数宏定义更方便使用
	char board[ROW][COL] = { 0 };
	//棋盘初始化
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);

	//下棋
	while (1)
	{
		//玩家下
		PlayerMove(board,ROW,COL);
		system("cls");
		DisplayBoard(board, ROW, COL);//下完棋子后显示

		//判断局势
		flag=isWin(board, ROW, COL);
		if (flag != 'J')
		{
			break;
		}
		
		//电脑下
		ComputerMove(board, ROW, COL);
		Sleep(1000);
		system("cls");
		DisplayBoard(board, ROW, COL);//下完棋子后显示

		//判断局势
		flag = isWin(board, ROW, COL);
		if (flag != 'J')
		{
			break;
		}
	}

	system("cls");
	//显示游戏结果
	if (flag == '*')
	{
		printf("你赢了！\n");
	}
	if (flag == '#')
	{
		printf("再接再厉！\n");
	}
	if (flag == 'P')
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);

	printf("\n\n还玩吗？\n");
}

//测试游戏,可以继续，设计框架
void test()
{
	int input = 0;

	//用时间戳设置随机数生成器
	srand((unsigned int)time(NULL));

	do
	{
		menu();//主页
		printf("请选择:>");
		scanf_s("%d",&input);
		
		system("cls");

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重试\n");
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
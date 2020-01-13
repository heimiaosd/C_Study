#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>

HANDLE hout;

//-------------------定义数据部分----------------//
//行和列
int row, col;

//存储玩家姓名
char player1PName[100];
char player2PName[100];
//存储玩家棋子类型
char chess1PType = ' ';
char chess2PType = ' ';
//初始化黑白棋子
char WHITE = '●';
char BLACK = '○';

//棋子数据的结构体
struct ChessPiece
{
	int x = 0;
	int y = 0;
	char chessType;
};

//玩家
enum Player{Player1P,Player2P, ComputerPlayer};

//棋盘数据
char chessData[100][100][100];

//---------------函数声明部分-------------------//

//游戏开始界面
int initGameInterface();

//游戏模式选择
int chooseGameMode();

//遍历棋盘
void playChess(int x, int y, char ch);

//初始化棋盘
void printcheckerboard(int row, int col);

//判断是否存在棋子函数
bool isExistChessPiece(ChessPiece che);

//判断是否胜利函数
bool isGameWin(ChessPiece che);

//更新最新的棋盘
void printChessboard();

//获取键盘输入
ChessPiece get_input(Player);

//胜利的界面
int gameWin(Player);

//游戏逻辑判断
int gameLogicalJudgment(Player p);

int main()
{
#if 1
	//随机数初始化
	srand((unsigned)time(NULL));

	//获取选择内容
GAME_START:
	//游戏初始化界面  
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand()%15);
	int chooseNum = 0;
	while (true)
	{
		chooseNum = initGameInterface();
		if (chooseNum == 2)
			return 0;
		else if(chooseNum!=1)
		{
			system("cls");
			chooseNum = initGameInterface();
		}

		chooseNum = chooseGameMode();
		if (chooseNum == 1)
			break;
		else if (chooseNum == 2)
			break;
		else
		{
			system("cls");
			chooseNum = chooseGameMode();
		}
	}
	
	//输入玩家姓名
	
	int x = 0, y = 0;
	int n = 0;
	while (true)
	{
		system("cls");
		//输入玩家姓名
		getchar();
		printf("请输入玩家1P的姓名:\n");
		gets_s(player1PName);
		
		
		while (true)
		{
			system("cls");
			printf("***************:\n");
			printf("请%s选择棋子：\n", player1PName);
			printf("***************:\n");
			printf("****1.白棋******:\n");
			printf("****2.黑棋******:\n");
			printf("***************:\n");
			scanf("%d", &n);
			if (n == 1)
			{
				chess1PType = WHITE;
				break;
			}
				
			else if (n == 2)
			{
				chess1PType = BLACK;
				break;
			}
		}

		system("cls");
		if (chooseNum == 2)
		{
			getchar();
		RENAME:
			printf("请输入玩家2P的姓名:\n");
			gets_s(player2PName);
			if (strcmp(player2PName, player1PName) == 0)
			{
				printf("该昵称已被%s使用，请重新输入\n",player1PName);
				goto RENAME;
			}
			while (true)
			{
				printf("***************:\n");
				printf("请%s选择棋子：\n", player2PName);
				printf("***************:\n");
				printf("****1.白棋******:\n");
				printf("****2.黑棋******:\n");
				printf("***************:\n");
				scanf("%d", &n);
				if (n == 1)
				{
					chess2PType = WHITE;
					if (chess2PType == chess1PType)
					{
						system("cls");
						printf("玩家%s已经选择该棋子请重新选择:\n", player1PName);
						continue;
					}
					break;
				}
				else if (n == 2)
				{
					chess2PType = BLACK;
					if (chess2PType == chess1PType)
					{
						system("cls");
						printf("玩家%s已经选择该棋子请重新选择:\n", player1PName);
						continue;
					}
					break;
				}
				system("cls");
			}
		}

		if (chooseNum == 1)
		{
			if (chess1PType != ' ')
				break;
		}
		else if (chooseNum == 2)
		{
			if (chess1PType != ' ' && chess2PType != ' ')
				break;
		}
	}

	//画棋盘
	system("cls");
	printf("请输入棋盘的宽和高（中间以空格分隔）：\n");
	scanf("%d%d", &row, &col);
	system("cls");
	printcheckerboard(row, col);

	while (true)
	{
		//玩家1
		int m = gameLogicalJudgment(Player::Player1P);
		if (m == 1)
			goto GAME_START;
		else if (m == 2)
			return 0;
		if (chooseNum == 2)
		{
			//玩家2
			m = gameLogicalJudgment(Player::Player2P);
			if (m == 1)
				goto GAME_START;
			else if (m == 2)
				return 0;
		}
		else
		{
			//电脑
			m = gameLogicalJudgment(Player::ComputerPlayer);
			if (m == 1)
				goto GAME_START;
			else if (m == 2)
				return 0;
		}
	}
	
#endif // 0
	return 0;
}

//---------------函数实现部分-------------------//
void printcheckerboard(int row, int col)
{
	for (int i = 0; i < row+1; i++)
	{
		for (int j = 0; j < col+1; j++)
		{
			if (i == 0)
			{
				if (j == 0)
				{
					printf("┌─");
					strcpy(chessData[i][j], "┌─");
				}

				else if (j == col)
				{
					printf("┐");
					strcpy(chessData[i][j], "┐");
				}

				else 
				{
					printf("┬─");
					strcpy(chessData[i][j], "┬─");
				}

			}
			else if (i == row)
			{
				if (j == 0)
				{
					printf("└─");
					strcpy(chessData[i][j], "└─");
				}
				else if (j == col)
				{
					printf("┘");
					strcpy(chessData[i][j], "┘");

				}
				else
				{
					printf("┴─");
					strcpy(chessData[i][j], "┴─");
				}
			}
			else 
			{
				if (j == 0)
				{
					printf("├");
					strcpy(chessData[i][j], "├");
				}

				else if (j == col)
				{
					printf("┤");
					strcpy(chessData[i][j], "┤");
				}

				else
				{
					if (j == 1)
					{
						printf("─┼─");
						strcpy(chessData[i][j], "─┼─");
					}
					else
					{
						printf("┼─");
						strcpy(chessData[i][j], "┼─");
					}
				}
			}
		}
		printf("\n");
		Sleep(100);
	}
}

int initGameInterface()
{
	system("cls");
	int s = 100;
	printf("*************************\n");
	Sleep(s);
	printf("*********欢迎来到********\n");
	Sleep(s);
	printf("*************************\n");
	Sleep(s);
	printf("******绿初蓝末五子棋*****\n");
	Sleep(s);
	printf("*************************\n");
	Sleep(s);
	printf("*******1.开始游戏********\n");
	Sleep(s);
	printf("*******2.退出************\n");
	Sleep(s);
	printf("*************************\n");
	Sleep(s);
	printf("*************************\n");
	Sleep(s);
	printf("请输入选择内容:\n");
	int a = 0;
	scanf("%d", &a);
	return a;
}

int chooseGameMode()
{
	system("cls");
	int s = 100;	
	printf("*************************\n");
	Sleep(s);
	printf("*********对战选择********\n");
	Sleep(s);
	printf("*************************\n");
	Sleep(s);
	printf("******绿初蓝末五子棋*****\n");
	Sleep(s);
	printf("*************************\n");
	Sleep(s);
	printf("*******1.人机对战********\n");
	Sleep(s);
	printf("*******2.双人对战********\n");
	Sleep(s);
	printf("*************************\n");
	Sleep(s);
	printf("*************************\n");
	Sleep(s);
	printf("请选择游戏模式:\n");
	int a = 0;
	scanf("%d", &a);
	return a;
}

void playChess(int x, int y, char ch)
{
	for (int i = 0; i < row + 2; i++)
	{
		for (int j = 0; j < col + 2; j++)
		{
			if (i == x && j == y)
			{
				if (j == 2)
				{
					if (ch == WHITE)
						strcpy(chessData[i][j], "─●");
					else
						strcpy(chessData[i][j], "─○");
				}
				else
				{
					if (ch == WHITE)
						strcpy(chessData[i][j], "●");
					else
						strcpy(chessData[i][j], "○");
				}
			}
		}
	}
	printChessboard();
}

void printChessboard()
{
	system("cls");

	for (int i = 0; i < row + 2; i++)
	{
		for (int j = 0; j < col + 2; j++)
		{
			printf("%s", chessData[i][j]);
		}
		printf("\n");
	}
}

bool isExistChessPiece(ChessPiece che)
{
	bool b = false;
	for (int i = 0; i < row + 2; i++)
	{
		for (int j = 0; j < col + 2; j++)
		{
			if (i == che.x && j == che.y)
			{
				if (strcmp(chessData[i][j], "─┼─") != 0 && strcmp(chessData[i][j], "┼─") != 0)
				{
					b = true;
					break;
				}
			}
		}
		printf("\n");
	}
	return b;
}

bool isGameWin(ChessPiece che)
{
	//记录 正方向和反方向的个数
	int hnum = 0, znum = 0, zxnum = 0, yxnum = 0;

	//往左找
	for (int n = 0; n < 2; n++)
	{
		int h = 0, z = 0, zx = 0, yx = 0;
		for (int i = 1; i < 5; i++)
		{

			if (che.chessType == WHITE)
			{
				if (n == 0)
				{
					int index = 0;
					//横向
					if (h == i && strcmp(chessData[che.x][che.y - i], "─●") == 0 || strcmp(chessData[che.x][che.y - i], "●") == 0)
					{
						hnum++;
						index++;
						h++;
					}
					if (z == i && strcmp(chessData[che.x - i][che.y], "─●") == 0 || strcmp(chessData[che.x - i][che.y], "●") == 0)
					{
						znum++;
						index++;
						z++;
					}
					if (zx == i && strcmp(chessData[che.x - i][che.y - i], "─●") == 0 || strcmp(chessData[che.x - i][che.y - i], "●") == 0)
					{
						zxnum++;
						index++;
						zx++;
					}

					if (yx == i && strcmp(chessData[che.x + i][che.y - i], "─●") == 0 || strcmp(chessData[che.x + i][che.y - i], "●") == 0)
					{
						yxnum++;
						index++;
						yx++;
					}
					if (index == 0)
						break;
				}
				else if (n == 1)
				{
					int index = 0;
					if (h == i && strcmp(chessData[che.x][che.y + i], "─●") == 0 || strcmp(chessData[che.x][che.y + i], "●") == 0)
					{
						hnum++;
						index++;
						h++;
					}
					if (z == i && strcmp(chessData[che.x + i][che.y], "─●") == 0 || strcmp(chessData[che.x + i][che.y], "●") == 0)
					{
						znum++;
						index++;
						z++;
					}
					if (zx == i && strcmp(chessData[che.x + i][che.y + i], "─●") == 0 || strcmp(chessData[che.x + i][che.y + i], "●") == 0)
					{
						zxnum++;
						index++;
						zx++;
					}
					if (yx == i && strcmp(chessData[che.x - i][che.y + i], "─●") == 0 || strcmp(chessData[che.x - i][che.y + i], "●") == 0)
					{
						yxnum++;
						index++;
						yx++;
					}
					if (index == 0)
						break;
				}
			}
			else
			{
				if (n == 0)
				{
					int index = 0;
					//横向
					if (h == i && strcmp(chessData[che.x][che.y - i], "─○") == 0 || strcmp(chessData[che.x][che.y - i], "○") == 0)
					{
						hnum++;
						index++;
						h++;
					}
					if (z == i && strcmp(chessData[che.x - i][che.y], "─○") == 0 || strcmp(chessData[che.x - i][che.y], "○") == 0)
					{
						znum++;
						index++;
						z++;
					}
					if (zx == i && strcmp(chessData[che.x - i][che.y - i], "─○") == 0 || strcmp(chessData[che.x - i][che.y - i], "○") == 0)
					{
						zxnum++;
						index++;
						zx++;
					}
					if (yx == i && strcmp(chessData[che.x + i][che.y - i], "─○") == 0 || strcmp(chessData[che.x + i][che.y - i], "○") == 0)
					{
						yxnum++;
						index++;
						yx++;
					}
					if (index == 0)
						break;
				}
				else if (n == 1)
				{
					int index = 0;
					if (h == i && strcmp(chessData[che.x][che.y + i], "─○") == 0 || strcmp(chessData[che.x][che.y + i], "○") == 0)
					{
						hnum++;
						index++;
						h++;
					}
					if (z == i && strcmp(chessData[che.x + i][che.y], "─○") == 0 || strcmp(chessData[che.x + i][che.y], "○") == 0)
					{
						znum++;
						index++;
						z++;
					}
					if (zx == i && strcmp(chessData[che.x + i][che.y + i], "─○") == 0 || strcmp(chessData[che.x + i][che.y + i], "○") == 0)
					{
						zxnum++;
						index++;
						zx++;
					}
					if (yx == i && strcmp(chessData[che.x - i][che.y + i], "─○") == 0 || strcmp(chessData[che.x - i][che.y + i], "○") == 0)
					{
						yxnum++;
						index++;
						yx++;
					}
					if (index == 0)
						break;
				}
			}
		}
	}
	if (hnum >= 4 || znum >= 4 || zxnum >= 4 || yxnum >= 4)
		return true;


	return false;
}

ChessPiece get_input(Player p)
{
	int ch;			//输入字符串

	COORD coord;	//设置屏幕上的坐标
	CONSOLE_SCREEN_BUFFER_INFO csbi;	//控制台屏幕缓冲区信息

	coord.X = row;	//设置光标坐标
	coord.Y = col/2;

	SetConsoleCursorPosition(hout, coord);//定位光标

	while (true)
	{
		ch = _getch();
		GetConsoleScreenBufferInfo(hout, &csbi);	//获取屏幕缓冲的光标位置,然后把当前光标位置赋给COORD
		coord.X = csbi.dwCursorPosition.X;			//得到坐标x的值
		coord.Y = csbi.dwCursorPosition.Y;			//y值
		coord.X < 0 ? coord.X = -coord.X : coord.X = coord.X;
		coord.Y < 0 ? coord.Y = -coord.Y : coord.Y = coord.Y;
		if (p == Player::Player1P)
		{
			if (ch == 119)//上
			{
				if (coord.Y >= 0)
					coord.Y--;
			}
			else if (ch == 115)//下 
			{
				if (coord.Y >= 0)
					coord.Y++;
			}   
			else if (ch == 97)//左
			{
				if (coord.X >= 0)
					coord.X--;
			}
			else if (ch == 100)//右
			{
				if (coord.X >= 0)//向右写79个字换行
					coord.X++;
			}
			else if(ch==32)
			{
				if (coord.X > 1 && coord.X < row * 2 && coord.Y>1 && coord.Y < col)
				{
					SetConsoleCursorPosition(hout, coord);//定位光标
					break;
				}
			}
		}
		else if (p == Player::Player2P)
		{
			if (ch == 0XE0 || ch == 0X0D)
			{
				if (ch == 0XE0)
				{
					ch = _getch();
					if (ch == 0x48)//上
					{
						if (coord.Y >= 0)
							coord.Y--;
					}
					else if (ch == 0x50)//下
					{
						if (coord.Y >= 0)
							coord.Y++;
					}
					else if (ch == 0x4b)//左
					{
						if (coord.X >= 0)
							coord.X--;
					}
					else if (ch == 0x4d)//右
					{
						if (coord.X > 0)//向右写79个字换行
							coord.X++;
					}
				}

				if (ch == 0X0D)//回车
				{
					if (coord.X > 1 && coord.X < row * 2 && coord.Y>1 && coord.Y < col)
					{
						SetConsoleCursorPosition(hout, coord);//定位光标
						break;
					}
				}
			}
		}
		SetConsoleCursorPosition(hout, coord);//定位光标
	}
	ChessPiece chpie;
	chpie.x = coord.Y;
	chpie.y = coord.X / 2;
	return chpie;	//普通按键就返回键值，输出对应的字符
}

int gameWin(Player p)
{
	system("cls");
	if (p == Player::ComputerPlayer)
		printf("笨蛋！！！\n连智障电脑都下不过\n*********************\n寂寞枯秤响泬寥，\n案淮秋老咽寒潮。\n白头灯影凉宵里，\n一局残横见六朝。\n*********************\n");
	else if (p == Player::Player1P)
		printf("玩家%s胜利\n*********************\n黑白谁能用入玄，\n千回生死体方圆。 \n空门说得恒沙劫，\n应笑终年为一先。\n*********************\n",player1PName);
	else if(p==Player::Player2P)
		printf("玩家%s胜利\n*********************\n宫棋布局不依经，\n黑白分明子数停。 \n巡拾玉沙天汉晓，\n犹残织女两三星。\n*********************\n",player2PName);
	Sleep(3000);
	int chooseNum = 0;
	int colorNum = 15;
	while (colorNum > 0)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
		printf("--------------------------\n");
		printf("---------1.重新开始-------\n");
		printf("---------2.退出-----------\n");
		printf("--------------------------\n");
		colorNum--;
		Sleep(200);
	}
	scanf("%d", &chooseNum);
	if (chooseNum == 1)
		return 1;
	else if (chooseNum == 2)
		return 2;
}

int gameLogicalJudgment(Player p)
{
	system("cls");
	printChessboard();
	ChessPiece pieData;
	while (true)
	{
		if (p == Player::Player1P)
		{
			printf("轮到玩家%s出手了！\n", player1PName);
			printf("请使用 w s a d 键控制上下左右，按空格键落子:\n");
			hout = GetStdHandle(STD_OUTPUT_HANDLE);
			pieData = get_input(Player::Player1P);
			pieData.chessType = chess1PType;
			if (!isExistChessPiece(pieData))
			{
				playChess(pieData.x, pieData.y, pieData.chessType);
				if (isGameWin(pieData))
					return gameWin(Player::Player1P);
				break;
			}
		}
		else if (p == Player::Player2P)
		{
			printf("轮到玩家%s出手了！\n", player2PName);
			printf("请使用 ↑ ↓ ← → 来控制光标移动 按 enter 键落子\n");
			hout = GetStdHandle(STD_OUTPUT_HANDLE);
			pieData = get_input(Player::Player2P);
			pieData.chessType = chess2PType;
			if (!isExistChessPiece(pieData))
			{
				playChess(pieData.x, pieData.y, pieData.chessType);
				if (isGameWin(pieData))
					return gameWin(Player::Player2P);
				break;
			}
		}
		else if (p == Player::ComputerPlayer)
		{
			//电脑随机数
			ChessPiece chpie;
			int dnx;
			int dny;
			char dnchessType = ' ';
			while (true)
			{
				dnx = (rand() % (row + 1)) + 2;
				dny = (rand() % (row + 1)) + 2;
				if (dnx > 1 && dnx < row + 1 && dny > 1 && dny < row + 1)
					break;
			}
			chess1PType == WHITE ? dnchessType = BLACK : dnchessType = WHITE;
			chpie.x = dnx;
			chpie.y = dny;
			chpie.chessType = dnchessType;
			if (!isExistChessPiece(chpie))
			{
				playChess(dnx, dny, dnchessType);
				if (isGameWin(chpie))
					return gameWin(Player::ComputerPlayer);
				break;
			}
		}
	}
}
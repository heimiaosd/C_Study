#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>

HANDLE hout;

//-------------------�������ݲ���----------------//
//�к���
int row, col;

//�洢�������
char player1PName[100];
char player2PName[100];
//�洢�����������
char chess1PType = ' ';
char chess2PType = ' ';
//��ʼ���ڰ�����
char WHITE = '��';
char BLACK = '��';

//�������ݵĽṹ��
struct ChessPiece
{
	int x = 0;
	int y = 0;
	char chessType;
};

//���
enum Player{Player1P,Player2P, ComputerPlayer};

//��������
char chessData[100][100][100];

//---------------������������-------------------//

//��Ϸ��ʼ����
int initGameInterface();

//��Ϸģʽѡ��
int chooseGameMode();

//��������
void playChess(int x, int y, char ch);

//��ʼ������
void printcheckerboard(int row, int col);

//�ж��Ƿ�������Ӻ���
bool isExistChessPiece(ChessPiece che);

//�ж��Ƿ�ʤ������
bool isGameWin(ChessPiece che);

//�������µ�����
void printChessboard();

//��ȡ��������
ChessPiece get_input(Player);

//ʤ���Ľ���
int gameWin(Player);

//��Ϸ�߼��ж�
int gameLogicalJudgment(Player p);

int main()
{
#if 1
	//�������ʼ��
	srand((unsigned)time(NULL));

	//��ȡѡ������
GAME_START:
	//��Ϸ��ʼ������  
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
	
	//�����������
	
	int x = 0, y = 0;
	int n = 0;
	while (true)
	{
		system("cls");
		//�����������
		getchar();
		printf("���������1P������:\n");
		gets_s(player1PName);
		
		
		while (true)
		{
			system("cls");
			printf("***************:\n");
			printf("��%sѡ�����ӣ�\n", player1PName);
			printf("***************:\n");
			printf("****1.����******:\n");
			printf("****2.����******:\n");
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
			printf("���������2P������:\n");
			gets_s(player2PName);
			if (strcmp(player2PName, player1PName) == 0)
			{
				printf("���ǳ��ѱ�%sʹ�ã�����������\n",player1PName);
				goto RENAME;
			}
			while (true)
			{
				printf("***************:\n");
				printf("��%sѡ�����ӣ�\n", player2PName);
				printf("***************:\n");
				printf("****1.����******:\n");
				printf("****2.����******:\n");
				printf("***************:\n");
				scanf("%d", &n);
				if (n == 1)
				{
					chess2PType = WHITE;
					if (chess2PType == chess1PType)
					{
						system("cls");
						printf("���%s�Ѿ�ѡ�������������ѡ��:\n", player1PName);
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
						printf("���%s�Ѿ�ѡ�������������ѡ��:\n", player1PName);
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

	//������
	system("cls");
	printf("���������̵Ŀ�͸ߣ��м��Կո�ָ�����\n");
	scanf("%d%d", &row, &col);
	system("cls");
	printcheckerboard(row, col);

	while (true)
	{
		//���1
		int m = gameLogicalJudgment(Player::Player1P);
		if (m == 1)
			goto GAME_START;
		else if (m == 2)
			return 0;
		if (chooseNum == 2)
		{
			//���2
			m = gameLogicalJudgment(Player::Player2P);
			if (m == 1)
				goto GAME_START;
			else if (m == 2)
				return 0;
		}
		else
		{
			//����
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

//---------------����ʵ�ֲ���-------------------//
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
					printf("����");
					strcpy(chessData[i][j], "����");
				}

				else if (j == col)
				{
					printf("��");
					strcpy(chessData[i][j], "��");
				}

				else 
				{
					printf("�Щ�");
					strcpy(chessData[i][j], "�Щ�");
				}

			}
			else if (i == row)
			{
				if (j == 0)
				{
					printf("����");
					strcpy(chessData[i][j], "����");
				}
				else if (j == col)
				{
					printf("��");
					strcpy(chessData[i][j], "��");

				}
				else
				{
					printf("�ة�");
					strcpy(chessData[i][j], "�ة�");
				}
			}
			else 
			{
				if (j == 0)
				{
					printf("��");
					strcpy(chessData[i][j], "��");
				}

				else if (j == col)
				{
					printf("��");
					strcpy(chessData[i][j], "��");
				}

				else
				{
					if (j == 1)
					{
						printf("���੤");
						strcpy(chessData[i][j], "���੤");
					}
					else
					{
						printf("�੤");
						strcpy(chessData[i][j], "�੤");
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
	printf("*********��ӭ����********\n");
	Sleep(s);
	printf("*************************\n");
	Sleep(s);
	printf("******�̳���ĩ������*****\n");
	Sleep(s);
	printf("*************************\n");
	Sleep(s);
	printf("*******1.��ʼ��Ϸ********\n");
	Sleep(s);
	printf("*******2.�˳�************\n");
	Sleep(s);
	printf("*************************\n");
	Sleep(s);
	printf("*************************\n");
	Sleep(s);
	printf("������ѡ������:\n");
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
	printf("*********��սѡ��********\n");
	Sleep(s);
	printf("*************************\n");
	Sleep(s);
	printf("******�̳���ĩ������*****\n");
	Sleep(s);
	printf("*************************\n");
	Sleep(s);
	printf("*******1.�˻���ս********\n");
	Sleep(s);
	printf("*******2.˫�˶�ս********\n");
	Sleep(s);
	printf("*************************\n");
	Sleep(s);
	printf("*************************\n");
	Sleep(s);
	printf("��ѡ����Ϸģʽ:\n");
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
						strcpy(chessData[i][j], "����");
					else
						strcpy(chessData[i][j], "����");
				}
				else
				{
					if (ch == WHITE)
						strcpy(chessData[i][j], "��");
					else
						strcpy(chessData[i][j], "��");
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
				if (strcmp(chessData[i][j], "���੤") != 0 && strcmp(chessData[i][j], "�੤") != 0)
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
	//��¼ ������ͷ�����ĸ���
	int hnum = 0, znum = 0, zxnum = 0, yxnum = 0;

	//������
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
					//����
					if (h == i && strcmp(chessData[che.x][che.y - i], "����") == 0 || strcmp(chessData[che.x][che.y - i], "��") == 0)
					{
						hnum++;
						index++;
						h++;
					}
					if (z == i && strcmp(chessData[che.x - i][che.y], "����") == 0 || strcmp(chessData[che.x - i][che.y], "��") == 0)
					{
						znum++;
						index++;
						z++;
					}
					if (zx == i && strcmp(chessData[che.x - i][che.y - i], "����") == 0 || strcmp(chessData[che.x - i][che.y - i], "��") == 0)
					{
						zxnum++;
						index++;
						zx++;
					}

					if (yx == i && strcmp(chessData[che.x + i][che.y - i], "����") == 0 || strcmp(chessData[che.x + i][che.y - i], "��") == 0)
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
					if (h == i && strcmp(chessData[che.x][che.y + i], "����") == 0 || strcmp(chessData[che.x][che.y + i], "��") == 0)
					{
						hnum++;
						index++;
						h++;
					}
					if (z == i && strcmp(chessData[che.x + i][che.y], "����") == 0 || strcmp(chessData[che.x + i][che.y], "��") == 0)
					{
						znum++;
						index++;
						z++;
					}
					if (zx == i && strcmp(chessData[che.x + i][che.y + i], "����") == 0 || strcmp(chessData[che.x + i][che.y + i], "��") == 0)
					{
						zxnum++;
						index++;
						zx++;
					}
					if (yx == i && strcmp(chessData[che.x - i][che.y + i], "����") == 0 || strcmp(chessData[che.x - i][che.y + i], "��") == 0)
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
					//����
					if (h == i && strcmp(chessData[che.x][che.y - i], "����") == 0 || strcmp(chessData[che.x][che.y - i], "��") == 0)
					{
						hnum++;
						index++;
						h++;
					}
					if (z == i && strcmp(chessData[che.x - i][che.y], "����") == 0 || strcmp(chessData[che.x - i][che.y], "��") == 0)
					{
						znum++;
						index++;
						z++;
					}
					if (zx == i && strcmp(chessData[che.x - i][che.y - i], "����") == 0 || strcmp(chessData[che.x - i][che.y - i], "��") == 0)
					{
						zxnum++;
						index++;
						zx++;
					}
					if (yx == i && strcmp(chessData[che.x + i][che.y - i], "����") == 0 || strcmp(chessData[che.x + i][che.y - i], "��") == 0)
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
					if (h == i && strcmp(chessData[che.x][che.y + i], "����") == 0 || strcmp(chessData[che.x][che.y + i], "��") == 0)
					{
						hnum++;
						index++;
						h++;
					}
					if (z == i && strcmp(chessData[che.x + i][che.y], "����") == 0 || strcmp(chessData[che.x + i][che.y], "��") == 0)
					{
						znum++;
						index++;
						z++;
					}
					if (zx == i && strcmp(chessData[che.x + i][che.y + i], "����") == 0 || strcmp(chessData[che.x + i][che.y + i], "��") == 0)
					{
						zxnum++;
						index++;
						zx++;
					}
					if (yx == i && strcmp(chessData[che.x - i][che.y + i], "����") == 0 || strcmp(chessData[che.x - i][che.y + i], "��") == 0)
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
	int ch;			//�����ַ���

	COORD coord;	//������Ļ�ϵ�����
	CONSOLE_SCREEN_BUFFER_INFO csbi;	//����̨��Ļ��������Ϣ

	coord.X = row;	//���ù������
	coord.Y = col/2;

	SetConsoleCursorPosition(hout, coord);//��λ���

	while (true)
	{
		ch = _getch();
		GetConsoleScreenBufferInfo(hout, &csbi);	//��ȡ��Ļ����Ĺ��λ��,Ȼ��ѵ�ǰ���λ�ø���COORD
		coord.X = csbi.dwCursorPosition.X;			//�õ�����x��ֵ
		coord.Y = csbi.dwCursorPosition.Y;			//yֵ
		coord.X < 0 ? coord.X = -coord.X : coord.X = coord.X;
		coord.Y < 0 ? coord.Y = -coord.Y : coord.Y = coord.Y;
		if (p == Player::Player1P)
		{
			if (ch == 119)//��
			{
				if (coord.Y >= 0)
					coord.Y--;
			}
			else if (ch == 115)//�� 
			{
				if (coord.Y >= 0)
					coord.Y++;
			}   
			else if (ch == 97)//��
			{
				if (coord.X >= 0)
					coord.X--;
			}
			else if (ch == 100)//��
			{
				if (coord.X >= 0)//����д79���ֻ���
					coord.X++;
			}
			else if(ch==32)
			{
				if (coord.X > 1 && coord.X < row * 2 && coord.Y>1 && coord.Y < col)
				{
					SetConsoleCursorPosition(hout, coord);//��λ���
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
					if (ch == 0x48)//��
					{
						if (coord.Y >= 0)
							coord.Y--;
					}
					else if (ch == 0x50)//��
					{
						if (coord.Y >= 0)
							coord.Y++;
					}
					else if (ch == 0x4b)//��
					{
						if (coord.X >= 0)
							coord.X--;
					}
					else if (ch == 0x4d)//��
					{
						if (coord.X > 0)//����д79���ֻ���
							coord.X++;
					}
				}

				if (ch == 0X0D)//�س�
				{
					if (coord.X > 1 && coord.X < row * 2 && coord.Y>1 && coord.Y < col)
					{
						SetConsoleCursorPosition(hout, coord);//��λ���
						break;
					}
				}
			}
		}
		SetConsoleCursorPosition(hout, coord);//��λ���
	}
	ChessPiece chpie;
	chpie.x = coord.Y;
	chpie.y = coord.X / 2;
	return chpie;	//��ͨ�����ͷ��ؼ�ֵ�������Ӧ���ַ�
}

int gameWin(Player p)
{
	system("cls");
	if (p == Player::ComputerPlayer)
		printf("����������\n�����ϵ��Զ��²���\n*********************\n��į�ݳ��웉�ȣ�\n���������ʺ�����\n��ͷ��Ӱ�����\nһ�ֲк��������\n*********************\n");
	else if (p == Player::Player1P)
		printf("���%sʤ��\n*********************\n�ڰ�˭����������\nǧ�������巽Բ�� \n����˵�ú�ɳ�٣�\nӦЦ����Ϊһ�ȡ�\n*********************\n",player1PName);
	else if(p==Player::Player2P)
		printf("���%sʤ��\n*********************\n���岼�ֲ�������\n�ڰ׷�������ͣ�� \nѲʰ��ɳ�캺����\n�̲�֯Ů�����ǡ�\n*********************\n",player2PName);
	Sleep(3000);
	int chooseNum = 0;
	int colorNum = 15;
	while (colorNum > 0)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
		printf("--------------------------\n");
		printf("---------1.���¿�ʼ-------\n");
		printf("---------2.�˳�-----------\n");
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
			printf("�ֵ����%s�����ˣ�\n", player1PName);
			printf("��ʹ�� w s a d �������������ң����ո������:\n");
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
			printf("�ֵ����%s�����ˣ�\n", player2PName);
			printf("��ʹ�� �� �� �� �� �����ƹ���ƶ� �� enter ������\n");
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
			//���������
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
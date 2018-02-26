#include "Head.h"

/*********************  ��Դ��CSDN zhaoxaun666 *********************/

#define ROW 10
#define LOW 10
#define ROWS ROW+2
#define LOWS LOW+2
#define  COUNT 10

void Menu();
void Game();
void set(char board[ROWS][LOWS], int row, int low, char M);
void show(char board[ROWS][LOWS], int row, int low);
void insert(char board[ROWS][LOWS], int count);
void Play1(char mine[ROWS][LOWS], char look[ROWS][LOWS], int x, int y);
int jishu(char mine[ROWS][LOWS], int x, int y);

int GameSweep(void)
{
	int n = 0;
	srand((unsigned)time(NULL));
	do
	{
		Menu();
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			Game();
			//system("cls");
			break;
		case 2:
			break;
		default:printf("����������������룺\n");
		}
		if (n == 2)
		{
			break;
		}
	} while (n);
}
void Menu()
{
	printf("******************************\n");
	printf("******************************\n");
	printf("******************************\n");
	printf("*******    1.Play1     ********\n");
	printf("*******    2.Exit     ********\n");
	printf("******************************\n");
	printf("******************************\n");
	printf("******************************\n");
}
void Game()
{
	int x, y;
	int m;
	int n = 0;
	int lei = 0;
	char mine[ROWS][LOWS] = { 0 };
	char look[ROWS][LOWS] = { 0 };
	set(mine, ROWS, LOWS, '0');//������������
	set(look, ROWS, LOWS, '*');//�������ӽ�������
	insert(mine, COUNT);//����


	do
	{
		int select;
		system("cls");
		//show(mine,ROW,LOW);
		show(look, ROW, LOW);//��ʾ�Ź�����
		printf("-------1.ɨ��-----2.�����--------\n");
		scanf("%d", &select);
		if (select == 1)
		{
			printf("���������꣺");
			scanf("%d%d", &x, &y);
			if (mine[x][y] == '1'&&n == 0)//��֤��һ�βȵ��Ĳ�����
			{
				set(mine, ROWS, LOWS, '0');
				insert(mine, COUNT);
			}
			if (mine[x][y] == '0'&&look[x][y] == '*')
			{
				Play1(mine, look, x, y);
				show(look, ROW, LOW);
			}
			if (mine[x][y] == '1'&&look[x][y] == '*')
			{
				m = 0;
				look[x][y] = '@';
				show(look, ROW, LOW);
				printf("��Ϸ������������ˣ�����\n");
			}
			n++;
		}
		if (select == 2)
		{

			printf("���������׵����꣺");
			scanf("%d%d", &x, &y);

			if (mine[x][y] == '1'&&look[x][y] == '*')
			{
				look[x][y] = 'X';
				lei++;
				show(look, ROW, LOW);

			}
			if (mine[x][y] == '0'&&look[x][y] == '*')
			{
				m = 0;//<span style="white-space:pre">  </span>//Ϊ������ѭ��


				printf("��Ϸ���������ױ�Ǵ����ˣ�����\n");
			}
			if (lei == COUNT)
			{
				m = 0;  //Ϊ������ѭ��
				printf("��ϲ�����׳ɹ�������\n");
			}
		}

	} while (m);
}
void set(char board[ROWS][LOWS], int row, int low, char M)
{
	int i, j;
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<low; j++)
		{
			board[i][j] = M;
		}
	}
}
void show(char board[ROWS][LOWS], int row, int low)
{
	int i, j;

	printf("    ");//Ϊ�����̵�����
	for (i = 1; i <= row; i++)
	{
		printf(" %d ", i);
	}
	printf("\n    ------------------------------\n");
	for (i = 1; i <= row; i++)
	{
		printf("%2d |", i);
		for (j = 1; j <= low; j++)
		{
			printf(" %c ", board[i][j]);
			if (j == low)
			{
				printf("|");
			}
		}
		printf("\n");
	}
	printf("    ------------------------------\n");
}
void insert(char board[ROWS][LOWS], int count)
{
	while (count)
	{
		int x, y;
		x = rand() % ROW + 1;
		y = rand() % LOW + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
void Play1(char mine[ROWS][LOWS], char look[ROWS][LOWS], int x, int y)//Ӧ�õݹ��ų���Χû���׵�����
{
	int ret;
	ret = jishu(mine, x, y);
	if (ret == 0)
	{
		look[x][y] = ' ';
		if ((x - 1)>0 && (y - 1)>0 && (look[x - 1][y - 1] == '*'))
			Play1(mine, look, x - 1, y - 1);
		if ((x - 1)>0 && (y)>0 && (look[x - 1][y] == '*'))
			Play1(mine, look, x - 1, y);
		if ((x - 1)>0 && (y + 1)>0 && (look[x - 1][y + 1] == '*'))
			Play1(mine, look, x - 1, y + 1);
		if ((x)>0 && (y - 1)>0 && (look[x][y - 1] == '*'))
			Play1(mine, look, x, y - 1);
		if ((x)>0 && (y + 1)>0 && (look[x][y + 1] == '*'))
			Play1(mine, look, x, y + 1);
		if ((x + 1)>0 && (y - 1)>0 && (look[x + 1][y - 1] == '*'))
			Play1(mine, look, x + 1, y - 1);
		if ((x + 1)>0 && (y)>0 && (look[x + 1][y] == '*'))
			Play1(mine, look, x + 1, y);
		if ((x + 1)>0 && (y + 1)>0 && (look[x + 1][y + 1] == '*'))
			Play1(mine, look, x + 1, y + 1);
	}
	else
		look[x][y] = ret + '0';
}
int jishu(char mine[ROWS][LOWS], int x, int y)//ͳ����Χ������
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';

}

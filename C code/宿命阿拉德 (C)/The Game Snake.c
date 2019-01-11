#include "Head.h"

/*********************  ��Դ��CSDN Sriven *********************/

#define R 24
#define H 24
#define W 48
#define UP 'w'  //��
#define DOWN 's'  //��
#define LEFT 'a'  //��
#define RIGHT 'd'  //��
void getfood();//����ʳ��
void start();//��ʼ����
void gameover();//��Ϸ����
void Play();//��Ϸ����F
void gotoxy(int, int);//��λ����
void wall();//ǽ��
void gamerule();
void menu();//��Ϸ�˵�
void chushihua();//��ʼ����
void move();
void print();//��ӡ��
void HideCursor();//���ع��
void turn(char);//�ı䷽��
void getfood();//�����ȡʳ��
void eatfood();//��ʳ��
int die();//�ж��Ƿ�����
struct Snake
{
	int x[100];//x[0]��ʾ��β�ĺ�����
	int y[100];//y[0]��ʾ��β��������
	int length;//�ߵĳ���
	int speed;//�ߵ��ٶ�
	int count;//�߳Ե�ʳ������
}snake;
struct Food
{
	int x;
	int y;
}food;
int i, j;
int a[2];//a[1]������β�������꣬a[0]������β�ĺ�����
void HideCursor()//���ع��
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void toxy(int x, int y)//������ƶ���X,Y���괦
{
	COORD pos = { x , y };
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}
void start()//��Ч
{
	int x, y, i, j;
	system("color 72");
	for (i = 0; i<10; i++)
	{
		x = i;
		for (y = x; y<24 - x; y++)
		{
			toxy(2 * x, y);
			printf("0 ");
		}
		x = (23 - i);
		for (y = i; y <= x; y++)
		{
			toxy(2 * x, y);
			printf("0 ");
		}
		x = i;
		for (y = x; y<24 - x; y++)
		{
			toxy(2 * y, x);
			printf("0 ");
		}
		x = (23 - i);
		for (y = i; y <= x; y++)
		{
			toxy(2 * y, x);
			printf("0 ");
		}
		Sleep(100);
	}
	for (i = 0; i<10; i++)
	{
		x = i;
		for (y = x; y<R - x; y++)
		{
			toxy(2 * x, y);
			printf("  ");
		}
		x = (23 - i);
		for (y = i; y <= x; y++)
		{
			toxy(2 * x, y);
			printf("  ");
		}
		x = i;
		for (y = x; y<R - x; y++)
		{
			toxy(2 * y, x);
			printf("  ");
		}
		x = (23 - i);
		for (y = i; y <= x; y++)
		{
			toxy(2 * y, x);
			printf("  ");
		}
		Sleep(100);
	}

}
void wall()//�߽�
{
	system("color 74");
	system("cls");
	int i, j, map[H][W];
	for (i = 0; i<H; i++)
	{
		for (j = 0; j<W; j++)
		{
			if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
			{
				map[i][j] = '0';
			}
			else
			{
				map[i][j] = ' ';
			}
		}
	}
	for (i = 0; i<H; i++)
	{
		for (j = 0; j<W; j++)
		{
			//toxy(j,i);
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}
void menu()//�˵�
{
	toxy(20, 5);
	printf("̰����");
	toxy(19, 7);
	printf("1.��ʼ��Ϸ");
	toxy(19, 9);
	printf("2.��Ϸ����");
	toxy(19, 11);
	printf("3.�˳���Ϸ");
	toxy(19, 13);
	printf("By---Sriven");
}
void gamerule()
{
	system("cls");
	toxy(20, 11);
	printf("��Ϸ����");
	start();
	system("cls");
	wall();
	toxy(1, 1);
	printf("1.��w��s��a��d����̰���ߵķ���");
	toxy(1, 3);
	printf("2.��̰���߳Ե�ʳ���\n̰�������ӱ䳤");
	toxy(1, 5);
	printf("3.���̰���ߵ�ͷ������ǽ�ڻ��������Լ������壬\n����Ϸ����");
	getch();
	toxy(20, 11);
	printf("̰����");
	start();
}
void gameover()
{
	system("cls");
	system("color 71");
	wall();
	toxy(20, 11);
	printf("BY-BY");
	start();
	exit(0);
	getch();
}
void chushihua()//��ʼ����
{
	snake.length = 3;
	snake.speed = 500;
	snake.count = 0;
	snake.x[0] = 8;
	snake.y[0] = 10;
	for (i = 1; i<snake.length; i++)
	{
		snake.x[i] = snake.x[i - 1] + 1;
		snake.y[i] = snake.y[i - 1];
	}
}
void move()
{
	toxy(snake.x[0], snake.y[0]);
	printf(" ");
	for (i = 1; i<snake.length; i++)//���ߵ�ǰһ�����긳����һ��
	{
		snake.x[i - 1] = snake.x[i];
		snake.y[i - 1] = snake.y[i];
	}
	//snake.x[snake.length-1]=snake.x[snake.length-2]+2;
	//snake.y[snake.length-1]=snake.y[snake.length-2];
}
void print()//��ӡ��
{
	for (i = 0; i<snake.length; i++)
	{
		toxy(snake.x[i], snake.y[i]);
		if (i == 0)
		{
			printf("+");
		}
		else if (i == snake.length - 1)
		{
			printf("+");
		}
		else
		{
			printf("+");
		}
	}
	system("color 71");
	toxy(50, 11);
	/*printf("��0������Ϸ");
	toxy(50, 0);
	printf("������%d", 10 * snake.count);
	toxy(50, 2);
	printf("��ǰ�ٶ�Ϊ��%d", snake.speed);
	toxy(50, 5);
	printf("1.��w��s��a��d����̰���ߵķ���");
	toxy(50, 7);
	printf("2.��̰���߳Ե�ʳ���̰�������ӱ䳤,ÿ��5��ʳ��ٶ�����");
	toxy(50, 9);
	printf("3.���̰���ߵ�ͷ������ǽ�ڻ��������Լ������壬����Ϸ����");
	toxy(60, 15);
	printf("By---Sriven");*/
}
void turn(char direction)//��ȡ����
{
	if (direction == 'w')
	{
		snake.y[snake.length - 1]--;
	}
	else if (direction == 's')
	{
		snake.y[snake.length - 1]++;
	}
	else if (direction == 'a')
	{
		snake.x[snake.length - 1] -= 1;
	}
	else if (direction == 'd')
	{
		snake.x[snake.length - 1] += 1;
	}
}
void getfood()
{
	//wall();
	srand(time(NULL));
	while (1)
	{
		food.x = rand() % 44 + 2;
		food.y = rand() % 21 + 2;
		for (i = 0; i<snake.length; i++)
		{
			if (food.x == snake.x[i] && food.y == snake.y[i])
			{
				break;
			}
		}
		if (i == snake.length)
		{
			toxy(food.x, food.y);
			printf("*"); break;
		}
	}
}
void eatfood()
{
	if (food.x == snake.x[snake.length - 1] && food.y == snake.y[snake.length - 1])
	{
		snake.length++;
		snake.count++;
		for (i = snake.length - 1; i >= 1; i--)
		{
			snake.x[i] = snake.x[i - 1];
			snake.y[i] = snake.y[i - 1];
		}
		snake.x[0] = a[0];
		snake.y[0] = a[1];
		if (snake.count % 5 == 0)
		{
			if (snake.count >= 40)
			{
				snake.speed = 100;
			}
			else
				snake.speed -= 50;
		}
		getfood();
	}
}
int die()
{
	int flag = 0;
	for (i = 0; i<snake.length - 1; i++)
	{
		if (snake.x[snake.length - 1] == snake.x[i] && snake.y[snake.length - 1] == snake.y[i])
		{
			flag = 1;
		}
	}
	if (snake.x[snake.length - 1] == 0 || snake.x[snake.length - 1] == W - 1 || snake.y[snake.length - 1] == 0 || snake.y[snake.length - 1] == H - 1)
	{
		flag = 1;
	}
	return(flag);
}
void Play()
{
	toxy(20, 11);
	printf("��ʼ��Ϸ");
	start();
	system("cls");
	char t = 'd';
	wall();
	chushihua();
	getfood();
	while (1)
	{
		a[0] = snake.x[0];
		a[1] = snake.y[0];
		if (kbhit())//�ж��Ƿ��а���
		{
			t = getch();
		}
		if (t == '0')break;
		move();
		turn(t);
		eatfood();
		print();
		if (die())
		{
			toxy(20, 12);
			printf("Game over!");
			Sleep(2000);
			break;
		}
		Sleep(snake.speed);
	}
}
void GameSnake()
{
	system("color 72");
	HideCursor();//���ع��
	toxy(20, 11);
	printf("̰����");
	start();
	system("color 70");

	do
	{
		system("cls");
		HideCursor();
		char n;
		wall();
		menu();
		n = getch();
		switch (n)
		{
		case '1':Play(); break;
		case '2':gamerule(); break;
		case '3':gameover(); break;
		default:printf("Please input 1~3:"); break;
		}
	} while (1);//��ԶΪ��
}

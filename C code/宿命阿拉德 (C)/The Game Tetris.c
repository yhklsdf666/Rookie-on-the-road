#include "Head.h"

/*********************  ��Դ��CSDN ����_t *********************/

#define FrameX 4   //�������Ͻǵ�X������
#define FrameY 4   //�������Ͻǵ�Y������
#define Frame_height  20 //���ڵĸ߶�
#define Frame_width   18 //���ڵĿ��
struct Tetris
{
	int x;  //���ķ����x������
	int y;  //���ķ����y������
	int flag;//��Ƿ������ͺ�
	int next;//��һ������˹�������͵����
	int speed;//����˹�����ƶ����ٶ�
	int count;//��������˹����ĸ���
	int score;//��Ϸ�ķ���
	int level;//��Ϸ�ĵȼ�
};
enum keyvalue
{
	ESC = 0x1b, LeftArrow = 0x4be0, RightArrow = 0x4de0, Blank = 0x20, DownArrow = 0x50e0
};
int i, j, k, temp, temp1, temp2;//temp1,temp2,temp3������ס��ת�����������ֵ
int a[100][100] = { 0 };//1�����飬2����߽磬0����ո�
int b[4];//��¼�ĸ�����
struct Tetris *tetris;
short int getkey()//���干���壬���ܼ��̰���
{
	union key
	{
		unsigned short int value;
		unsigned char ch[2];
	} key1;
	key1.value = 0;
	if (kbhit())
	{
		key1.ch[0] = getch();
		if (kbhit())
			key1.ch[1] = getch();
	}
	return key1.value;
}
void Gotoxy(int x, int y)   //������Ƶ���ָλ��
{
	COORD pos;
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Make_tetris() //���ķ���λ�����꣬1-�У�0-��
{
	a[tetris->x][tetris->y] = b[0];
	switch (tetris->flag)
	{
	case 1:
		a[tetris->x][tetris->y - 1] = b[1];    //����
		a[tetris->x + 2][tetris->y - 1] = b[2];//����
		a[tetris->x + 2][tetris->y] = b[3];    //
		break;
	case 2:
		a[tetris->x - 2][tetris->y] = b[1];//
		a[tetris->x + 2][tetris->y] = b[2];//��������
		a[tetris->x + 4][tetris->y] = b[3];//
		break;
	case 3:
		a[tetris->x][tetris->y - 1] = b[1];//��
		a[tetris->x][tetris->y - 2] = b[2];//��
		a[tetris->x][tetris->y + 1] = b[3];//��
		break;                             //��
	case 4:
		a[tetris->x - 2][tetris->y] = b[1];//
		a[tetris->x + 2][tetris->y] = b[2];//������
		a[tetris->x][tetris->y + 1] = b[3];//  ��
		break;
	case 5:
		a[tetris->x][tetris->y - 1] = b[1];//  ��
		a[tetris->x][tetris->y + 1] = b[2];//����
		a[tetris->x - 2][tetris->y] = b[3];//  ��
		break;
	case 6:
		a[tetris->x][tetris->y - 1] = b[1];//  ��
		a[tetris->x - 2][tetris->y] = b[2];//������
		a[tetris->x + 2][tetris->y] = b[3];//
		break;
	case 7:
		a[tetris->x][tetris->y - 1] = b[1];//��
		a[tetris->x][tetris->y + 1] = b[2];//����
		a[tetris->x + 2][tetris->y] = b[3];//��
		break;
	case 8:
		a[tetris->x][tetris->y + 1] = b[1];    //
		a[tetris->x - 2][tetris->y] = b[2];    //����
		a[tetris->x + 2][tetris->y + 1] = b[3];//  ����
		break;
	case 9:
		a[tetris->x][tetris->y - 1] = b[1];    //  ��
		a[tetris->x - 2][tetris->y] = b[2];    //����
		a[tetris->x - 2][tetris->y + 1] = b[3];//��
		break;
	case 10:
		a[tetris->x][tetris->y - 1] = b[1];    //����
		a[tetris->x - 2][tetris->y - 1] = b[2];//  ����
		a[tetris->x + 2][tetris->y] = b[3];    //
		break;
	case 11:
		a[tetris->x][tetris->y + 1] = b[1];      //  ��
		a[tetris->x + 2][tetris->y - 1] = b[2];//����
		a[tetris->x + 2][tetris->y] = b[3];    //��
		break;
	case 12:
		a[tetris->x][tetris->y - 1] = b[1];  //����
		a[tetris->x][tetris->y + 1] = b[2];  //  ��
		a[tetris->x - 2][tetris->y - 1] = b[3];//  ��
		break;
	case 13:
		a[tetris->x - 2][tetris->y] = b[1];  //
		a[tetris->x - 2][tetris->y + 1] = b[2];//������
		a[tetris->x + 2][tetris->y] = b[3];  //��
		break;
	case 14:
		a[tetris->x][tetris->y - 1] = b[1];  // ��
		a[tetris->x][tetris->y + 1] = b[2];  // ��
		a[tetris->x + 2][tetris->y + 1] = b[3];// ����
		break;
	case 15:
		a[tetris->x - 2][tetris->y] = b[1];    //
		a[tetris->x + 2][tetris->y - 1] = b[2];//������
		a[tetris->x + 2][tetris->y] = b[3];    //    ��
		break;
	case 16:
		a[tetris->x][tetris->y + 1] = b[1];    //����
		a[tetris->x][tetris->y - 1] = b[2];    //��
		a[tetris->x + 2][tetris->y - 1] = b[3];//��
		break;
	case 17:
		a[tetris->x - 2][tetris->y] = b[1];    //��
		a[tetris->x - 2][tetris->y - 1] = b[2];//������
		a[tetris->x + 2][tetris->y] = b[3];    //
		break;
	case 18:
		a[tetris->x][tetris->y - 1] = b[1];    //  ��
		a[tetris->x][tetris->y + 1] = b[2];    //  ��
		a[tetris->x - 2][tetris->y + 1] = b[3];//����
		break;
	case 19:
		a[tetris->x - 2][tetris->y] = b[1];    //
		a[tetris->x + 2][tetris->y + 1] = b[2];//������
		a[tetris->x + 2][tetris->y] = b[3];    //    ��
		break;
	}
}
//������Ϸ����
void Make_Frame()
{
	Gotoxy(FrameX + Frame_width - 5, FrameY - 2);
	printf("����˹����");
	Gotoxy(FrameX, FrameY);
	a[FrameX][FrameY] = 2;
	printf("�X");                          //��������
	for (i = 2; i < 2 * Frame_width - 2; i += 2)
	{
		printf("�T");                      //��ӡ�Ϻ��
	}
	printf("�[");
	a[FrameX + 2 * Frame_width - 2][FrameY + Frame_height] = 2;
	for (i = 1; i < Frame_height; i++)
	{
		Gotoxy(FrameX, FrameY + i);
		printf("�U");                      //��ӡ������
		a[FrameX][FrameY + i] = 2;         //��ס��������ͼ��
	}
	Gotoxy(FrameX, FrameY + Frame_height);
	printf("�^");
	a[FrameX][FrameY + Frame_height] = 2;
	for (i = 1; i < Frame_height; i++)
	{
		Gotoxy(FrameX + 2 * Frame_width - 2, FrameY + i);
		printf("�U");                        //��ӡ�Һ��
		a[FrameX + 2 * Frame_width - 2][FrameY + i] = 2;//��ס��������ͼ��
	}
	Gotoxy(FrameX + 2, FrameY + Frame_height);
	for (i = 2; i<2 * Frame_width - 2; i += 2)
	{
		printf("�T");                        //��ӡ�º��
		a[FrameX + i][FrameY + Frame_height] = 2;//��ס�º����ͼ��
	}
	printf("�a");
	Gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 7);   //��ӡ�˵�
	printf("**********��һ������");
	Gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 13);
	printf("**********");
	Gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 15);
	printf("�ո��������");
	Gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 17);
	printf("����������");
	Gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 19);
	printf("����������");
}
//�жϷ����Ƿ�����ƶ�
bool Movable()
{
	if (a[tetris->x][tetris->y] != 0) //�����ķ���λ������ͼ��ʱ������false���������ƶ�
		return false;
	else
	{
		if (//��������ĸ�λ�õ�ֵ��Ϊ0������ͼ��ʱ�����ƶ�
			(tetris->flag == 1 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x + 2][tetris->y - 1] == 0 &&
				a[tetris->x + 2][tetris->y] == 0)) ||
				(tetris->flag == 2 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y] == 0 &&
					a[tetris->x + 4][tetris->y] == 0)) ||
					(tetris->flag == 3 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y - 2] == 0 &&
						a[tetris->x][tetris->y + 1] == 0)) ||
						(tetris->flag == 4 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y] == 0 &&
							a[tetris->x][tetris->y + 1] == 0)) ||
							(tetris->flag == 5 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 &&
								a[tetris->x - 2][tetris->y] == 0)) ||
								(tetris->flag == 6 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x - 2][tetris->y] == 0 &&
									a[tetris->x + 2][tetris->y] == 0)) ||
									(tetris->flag == 7 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 &&
										a[tetris->x + 2][tetris->y] == 0)) ||
										(tetris->flag == 8 && (a[tetris->x][tetris->y + 1] == 0 && a[tetris->x - 2][tetris->y] == 0 &&
											a[tetris->x + 2][tetris->y + 1] == 0)) ||
											(tetris->flag == 9 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x - 2][tetris->y] == 0 &&
												a[tetris->x - 2][tetris->y + 1] == 0)) ||
												(tetris->flag == 10 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x - 2][tetris->y - 1] == 0 &&
													a[tetris->x + 2][tetris->y] == 0)) ||
													(tetris->flag == 11 && (a[tetris->x][tetris->y + 1] == 0 && a[tetris->x + 2][tetris->y - 1] == 0 &&
														a[tetris->x + 2][tetris->y] == 0)) ||
														(tetris->flag == 12 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 &&
															a[tetris->x - 2][tetris->y - 1] == 0)) ||
															(tetris->flag == 13 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x - 2][tetris->y + 1] == 0 &&
																a[tetris->x + 2][tetris->y] == 0)) ||
																(tetris->flag == 14 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 &&
																	a[tetris->x + 2][tetris->y + 1] == 0)) ||
																	(tetris->flag == 15 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y - 1] == 0 &&
																		a[tetris->x + 2][tetris->y] == 0)) ||
																		(tetris->flag == 16 && (a[tetris->x][tetris->y + 1] == 0 && a[tetris->x][tetris->y - 1] == 0 &&
																			a[tetris->x + 2][tetris->y - 1] == 0)) ||
																			(tetris->flag == 17 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x - 2][tetris->y - 1] == 0 &&
																				a[tetris->x + 2][tetris->y] == 0)) ||
																				(tetris->flag == 18 && (a[tetris->x][tetris->y - 1] == 0 && a[tetris->x][tetris->y + 1] == 0 &&
																					a[tetris->x - 2][tetris->y + 1] == 0)) ||
																					(tetris->flag == 19 && (a[tetris->x - 2][tetris->y] == 0 && a[tetris->x + 2][tetris->y + 1] == 0 &&
																						a[tetris->x + 2][tetris->y] == 0)))
		{
			return true;
		}
	}
	return false;
}
//�����������˹�������͵����
void Get_flag()
{
	tetris->count++; //��ס��������ĸ���
	srand((unsigned)time(NULL));
	if (tetris->count == 1)
		tetris->flag = rand() % 19 + 1;//��ס��һ����������
	srand((unsigned)time(NULL));
	tetris->next = rand() % 19 + 1;//��ס��һ����������
}
//��ӡ����˹����
void Print_tetris()
{
	for (i = 0; i < 4; i++)
		b[i] = 1;
	Make_tetris();
	for (i = tetris->x - 2; i <= tetris->x + 4; i += 2)
	{
		for (j = tetris->y - 2; j <= tetris->y + 1; j++)
		{
			if (a[i][j] == 1 && j > FrameY)
			{
				Gotoxy(i, j);
				printf("��");           ///�����⣡����
			}
		}
	}
	//��ӡ�˵���Ϣ
	Gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 1);
	printf("level��%d", tetris->level);
	Gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 3);
	printf("score��%d", tetris->score);
	Gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 5);
	printf("speed��%dms", tetris->speed);
}
//�������˹����ĺۼ�
void Clear_tetris()
{
	for (i = 0; i < 4; i++)
		b[i] = 0;
	Make_tetris();
	for (i = tetris->x - 2; i <= tetris->x + 4; i += 2)
	{
		for (j = tetris->y - 2; j <= tetris->y + 1; j++)
		{
			if (a[i][j] == 0 && j>FrameY)
			{
				Gotoxy(i, j);
				printf("  ");
			}
		}
	}
}
//�ж��Ƿ����в�ɾ�����еĶ���˹����
void Del_full()
{
	int del_count = 0;

	for (j = FrameY + Frame_height - 1; j >= FrameY + 1; j--)
	{
		k = 0;//���ڼ�¼ĳ�з���ĸ���
		for (i = FrameX + 2; i < FrameX + 2 * Frame_width - 2; i += 2)
		{
			if (a[i][j] == 1)
			{
				k++;
				if (k == Frame_width - 2)//��������
				{
					for (k = FrameX + 2; k < FrameX + 2 * Frame_width - 2; k += 2)
					{
						a[k][j] = 0;
						Gotoxy(k, j);
						printf("  ");
						Sleep(1);
					}
					for (k = j - 1; k > FrameY; k--)
					{
						for (i = FrameX + 2; i < FrameX + 2 * Frame_width - 2; i += 2)
						{
							if (a[i][k] == 1)
							{
								a[i][k] = 0;
								Gotoxy(i, k);
								printf("  ");
								a[i][k + 1] = i;
								Gotoxy(i, k + 1);
								printf("��");
							}
						}
					}
					j++;//�������������ƺ������ж�ɾ�����Ƿ�����
					del_count++;//��¼ɾ�����������
				}
			}
		}
	}
	tetris->score += 10 * del_count;    //ûɾ��һ�У���10��
	if (del_count > 0 && tetris->score % 100 == 0)                //�����⣡����
	{
		tetris->speed -= 20;//����ۼ�����10�У��ٶȼӿ�20ms����һ��
		tetris->level++;
	}
}
//��ʼ��Ϸ
void Start_game()
{
	tetris = (struct Tetris*)malloc(sizeof(struct Tetris));
	int key = 0;//���̰���
	key = getkey();
	tetris->count = 0;//��ʼ������˹������Ϊ0��
	tetris->speed = 300;//��ʼ�ƶ��ٶ�Ϊ300ms
	tetris->score = 0;//��ʼ��Ϸ����Ϊ0��
	tetris->level = 1;//��ʼ��Ϸ��Ϊ��1��
	while (1)//ѭ���������飬ֱ����Ϸ����
	{
		Get_flag();
		temp = tetris->flag;
		//��ӡ��һ������˹�����ͼ�Σ��Ҵ��ڣ�
		tetris->x = FrameX + 2 * Frame_width + 6;
		tetris->y = FrameY + 10;
		tetris->flag = tetris->next;
		Print_tetris();
		tetris->x = FrameX + Frame_width;//��ʼ���ķ���x����
		tetris->y = FrameY - 1;
		tetris->flag = temp; //ȡ����ǰ�Ķ���˹�������
		while (1)//���Ʒ��鷽��ֱ�����鲻������
		{
			Print_tetris();
			Sleep(tetris->speed);
			Clear_tetris();
			temp1 = tetris->x;//��ס���ķ���ĺ�����
			temp2 = tetris->flag;//��ס��ǰ����˹�������
			if (kbhit())
			{
				key = getkey();
				switch (key)
				{
				case LeftArrow:
					tetris->x -= 2;//���ĺ�����-2
					break;
				case RightArrow:
					tetris->x += 2;//���ĺ�����+2
					break;
				case Blank://��ת
					if (tetris->flag == 2 || tetris->flag == 3)
					{
						tetris->flag++;
						tetris->flag %= 2;
						tetris->flag += 2;
					}
					else if (tetris->flag >= 4 && tetris->flag <= 7)
					{
						tetris->flag++;
						tetris->flag %= 4;
						tetris->flag += 4;
					}
					else if (tetris->flag >= 8 && tetris->flag <= 11)
					{
						tetris->flag++;
						tetris->flag %= 4;
						tetris->flag += 8;
					}
					else if (tetris->flag >= 12 && tetris->flag <= 15)
					{
						tetris->flag++;
						tetris->flag %= 4;
						tetris->flag += 12;
					}
					else if (tetris->flag >= 16 && tetris->flag <= 19)
					{
						tetris->flag++;
						tetris->flag %= 4;
						tetris->flag += 16;
					}
					break;
				}
				if (!Movable())//��������ƶ������������Ч
				{
					tetris->x = temp1;
					tetris->flag = temp2;
				}
			}
			tetris->y++;//���û�в���ָ����������ƶ�
			if (!Movable())//��������ƶ��Ҳ����ƶ���������ڴ˴�
			{
				tetris->y--;
				Print_tetris();
				Del_full();
				break;
			}
		}
		for (i = tetris->y - 2; i<tetris->y + 2; i++)
		{
			if (i == FrameY)
				j = 0;                             //��Ϸ����
		}
		if (j == 0)
		{
			for (j = 0; j<Frame_height + 1; j++)
			{
				Gotoxy(FrameX + 1, FrameY + j);
				for (i = 1; i<Frame_width; i++)
					printf("��");
			}
			Gotoxy(FrameX + Frame_width - 4, FrameY + Frame_height / 2);
			printf("GAME OVER!");
			Gotoxy(FrameX, FrameY + Frame_height + 1);
			getch();
			break;
		}
		//�����һ������˹�����ͼ�Σ��Ҵ��ڣ�
		tetris->flag = tetris->next;
		tetris->x = FrameX + 2 * Frame_width + 6;
		tetris->y = FrameY + 10;
		Clear_tetris();
	}
}
int GameTetris(void)
{
	Make_Frame();
	Start_game();
	getch();
	printf("�����������...");
	return 0;
}

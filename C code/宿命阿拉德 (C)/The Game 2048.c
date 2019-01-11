#include "Head.h"

/*********************  ��Դ��CSDN��С��  *********************/

typedef struct x_y {    //�������һ������
	int x;
	int y;
}x_y;
static x_y get_xy();
int a[4][4];
int empty;      //�����пո����Ŀ

void init();    //��ʼ������
void Show();    //��ӡ4X4������������
void to_up();   //���ռ������룬�����������ƶ�����
void to_down();
void to_left();
void to_right();
void add_num();     //������һ�����ֵ�����
void play();

int Game2048(void)
{
	printf("++++++++++++++++++++++++++++\n");
	printf("            2048            \n\n");
	printf("Control by:\n"
		" w/s/a/d or W/S/A/D\n");
	printf("press q or Q quit game!\n");
	printf("++++++++++++++++++++++++++++\n");
	printf("Any key to continue . . .\n");
	_getch();
	system("cls");
	init();
	Show();
	while (1)
		play();
	return 0;
}
void init()
{
	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			a[i][j] = 0;
	srand(time(NULL));
	i = rand() % 4;
	j = rand() % 4;
	a[i][j] = 2;
	empty = 15;
}
void Show()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
			printf("|     ");
		printf("|\n");
		for (j = 0; j < 4; j++)
			if (a[i][j] == 0)
				printf("|     ");
			else
				printf("|%5d", a[i][j]);
		printf("|\n");
		for (j = 0; j < 4; j++)
			printf("|_____");
		printf("|\n");
	}
}
void play()
{
	switch (getch()) {
	case 'W':
	case 'w':
		system("cls");      //cls���������Ļ
		to_up();
		add_num();
		Show();
		break;
	case 'A':
	case 'a':
		system("cls");
		to_left();
		add_num();
		Show();
		break;
	case 'S':
	case 's':
		system("cls");
		to_down();
		add_num();
		Show();
		break;
	case 'D':
	case 'd':
		system("cls");
		to_right();
		add_num();
		Show();
		break;
	case 'q':
	case 'Q':
		puts("quiting");
		exit(EXIT_FAILURE);

	default:
		printf("\nwrong type!!!\n\n");
		printf("please type :\n");
		printf("w/s/a/d or W/S/A/D\n");
		break;
	}
}


//to_up()����4x4�����������ƣ��������ڵĴ�С��ȵ�������Ӻϲ�
void to_up()
{
	int i, j, tmp; //iΪ������jΪ������tmpΪ�м����
	int lasti, lastj;
	//˼·��
	//�����ƶ�����ÿһ��Ϊһ����Ԫ��ÿ�β�����ֻ����һ��
	//����һ�У����ǵ�һ��Ԫ��Ϊ��ǰԪ�أ�
	//�����ǰԪ��Ϊ0��ֱ�Ӹ�ֵΪ��һ������Ԫ��ֵ������0������Ԫ��
	//�����һ��Ԫ�أ���ʱΪ�ڶ�����Ϊ0���򣬿�����һ��
	//�����һ��Ԫ�أ�������ȣ�����Ӻϲ�����һ��Ԫ��Ҫ��0����
	//�����һ��Ԫ�أ��������ȣ������Ƶ���ǰԪ�ص�����λ��
	for (j = 0; j < 4; j++)
	{
		lasti = 0;
		lastj = j;          //��ǰԪ������
		for (i = 1; i < 4; i++)
			if (a[i][j] == 0)                               //������һ��
				continue;
			else {
				if (a[lasti][lastj] == 0) {                 //��ǰԪ��Ϊ0
					a[lasti][lastj] = a[i][j];
					a[i][j] = 0;
				}
				else if (a[lasti][lastj] == a[i][j]) {      //��ǰԪ������һ�����
					a[lasti][lastj] *= 2;
					a[i][j] = 0;
					empty += 1;
				}
				else {                                      //��ǰԪ�����һ����0����Ԫ�ز���
					tmp = a[i][j];
					a[i][j] = 0;
					a[++lasti][lastj] = tmp;                //�õ�ǰԪ�ص�����λ����ʱ�ѱ���ֵ��Ϊ��ǰԪ��
				}
			}
	}
}
//void to_up(void) {                //���ϵ���һ�ַ���������ѭ����ɵ�ʱ����ۺܴ�
//  int x, y, i;
//
//  for (y = 0; y < 4; ++y) {     // �������ºϲ���ͬ�ķ���
//      for (x = 0; x < 4; ++x) {
//          if (a[x][y] == 0)
//              ;
//          else {
//              for (i = x + 1; i < 4; ++i) {
//                  if (a[i][y] == 0)
//                      ;
//                  else if (a[x][y] == a[i][y]) {
//                      a[x][y] += a[i][y];
//                      a[i][y] = 0;
//                      ++empty;
//                      x = i;
//                      break;
//                  }
//                  else {
//                      //x = i - 1;
//                      break;
//                  }
//              }
//          }
//      }
//  }
//
//  for (y = 0; y < 4; ++y)    // �����ƶ�����
//      for (x = 0; x < 4; ++x) {
//          if (a[x][y] == 0)
//              ;
//          else {
//              for (i = x; (i > 0) && (a[i - 1][y] == 0); --i) {
//                  a[i - 1][y] = a[i][y];
//                  a[i][y] = 0;
//              }
//          }
//      }
//}
void to_down()
{
	int i, j, tmp; //iΪ������jΪ������tmpΪ�м����
	int lasti, lastj;
	for (j = 0; j < 4; j++)
	{
		lasti = 3;
		lastj = j;          //��ǰԪ������
		for (i = 2; i >-1; i--)
			if (a[i][j] == 0)                               //������һ��
				continue;
			else {
				if (a[lasti][lastj] == 0) {                 //��ǰԪ��Ϊ0
					a[lasti][lastj] = a[i][j];
					a[i][j] = 0;
				}
				else if (a[lasti][lastj] == a[i][j]) {      //��ǰԪ������һ�����
					a[lasti][lastj] *= 2;
					a[i][j] = 0;
					empty += 1;
				}
				else {                                      //��ǰԪ�����һ����0����Ԫ�ز���
					tmp = a[i][j];
					a[i][j] = 0;
					a[--lasti][lastj] = tmp;                //�õ�ǰԪ�ص�����λ����ʱ�ѱ���ֵ��Ϊ��ǰԪ��
				}
			}
	}
}
void to_left()
{
	int i, j, tmp; //iΪ������jΪ������tmpΪ�м����
	int lasti, lastj;
	for (i = 0; i < 4; i++)
	{
		lasti = i;
		lastj = 0;          //��ǰԪ������
		for (j = 1; j < 4; j++)
			if (a[i][j] == 0)                               //������һ��
				continue;
			else {
				if (a[lasti][lastj] == 0) {                 //��ǰԪ��Ϊ0
					a[lasti][lastj] = a[i][j];
					a[i][j] = 0;
				}
				else if (a[lasti][lastj] == a[i][j]) {      //��ǰԪ������һ�����
					a[lasti][lastj] *= 2;
					a[i][j] = 0;
					empty += 1;
				}
				else {                                      //��ǰԪ�����һ����0����Ԫ�ز���
					tmp = a[i][j];
					a[i][j] = 0;
					a[lasti][++lastj] = tmp;                //�õ�ǰԪ�ص�����λ����ʱ�ѱ���ֵ��Ϊ��ǰԪ��
				}
			}
	}
}
void to_right()
{
	int i, j, tmp; //iΪ������jΪ������tmpΪ�м����
	int lasti, lastj;
	for (i = 0; i < 4; i++)
	{
		lasti = i;
		lastj = 3;          //��ǰԪ������
		for (j = 2; j>-1; j--)
			if (a[i][j] == 0)                               //������һ��
				continue;
			else {
				if (a[lasti][lastj] == 0) {                 //��ǰԪ��Ϊ0
					a[lasti][lastj] = a[i][j];
					a[i][j] = 0;
				}
				else if (a[lasti][lastj] == a[i][j]) {      //��ǰԪ������һ�����
					a[lasti][lastj] *= 2;
					a[i][j] = 0;
					empty += 1;
				}
				else {                                      //��ǰԪ�����һ����0����Ԫ�ز���
					tmp = a[i][j];
					a[i][j] = 0;
					a[lasti][--lastj] = tmp;                //�õ�ǰԪ�ص�����λ����ʱ�ѱ���ֵ��Ϊ��ǰԪ��
				}
			}
	}
}

void add_num()
{
	x_y i_j;
	i_j = get_xy();
	if (i_j.x == -1)
	{
		return 0;
	}
	srand(time(NULL));

	a[i_j.x][i_j.y] = (rand() % 2) ? 2 : 4;
	empty--;
}
static x_y get_xy()
{
	int count, newxy, i, j;
	x_y i_j;
	if (empty == 0)
	{
		i_j.x = -1;
		i_j.y = -1;
		return i_j;
	}

	srand(time(NULL));
	count = -1;
	newxy = rand() % empty;     //��ʾӦ�ڵڼ����������Ԫ��,newxy��0��ʼ
	for (i = 0; i < 4; (i)++) {
		for (j = 0; j < 4; (j)++) {
			if (a[i][j] == 0) {
				count++;
				if (count == newxy)
				{
					i_j.x = i;
					i_j.y = j;
					return i_j;
				}
			}
		}
	}
}

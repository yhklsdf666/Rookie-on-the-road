#include "Head.h"

void SetTitle(char *title) {
	SetConsoleTitle(title);            //���ó������
}

//0-��ɫ, 1-��ɫ,   2-��ɫ,      3-ǳ��ɫ,     4-��ɫ,   5-��ɫ,   6-��ɫ,   7-��ɫ,
//8-��ɫ, 9-����ɫ, 10-����ɫ,   11-��ǳ��ɫ   12-����ɫ 13-����ɫ 14-����ɫ 15-����ɫ
void SetColor(int foreColor, int backColor) {
	HANDLE winHandle;                  //���
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(winHandle, foreColor + backColor * 0x10);        //���ÿ���̨�ı�������
}


void SetPosition(int x, int y) {
	HANDLE winHandle;                  //���ù��λ��
	COORD pos = { x,y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(winHandle, pos);
}


void Clear(int x, int y, int rowCount) {
	int i, j;
	for (i = 0; i < rowCount; ++i) {
		SetPosition(x, y + i);
		for (j = 0; j < 70; ++j)
			printf(" ");
	}
}

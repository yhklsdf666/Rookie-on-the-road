#ifndef SWORDSMAN_H_INCLUDED
#define SWORDSMAN_H_INCLUDED

#define SEP "------------------------------------------------------------------------------------"
#define LSEP "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

#define MARGIN_X 17             //��߾�
#define MAP_START_Y 3           //��ͼ��ʼ��Y����
#define MAP_END_Y   11          //��ͼ������Y����
#define INFO_START_Y 12         //��Ϣ���濪ʼ��Y����
#define INFO_END_Y 21           //��Ϣ����Ľ���Y����
#define MAINMENU_START_Y 22     //���˵���ʼ��Y����

/***************************************************
 *
 * ��  ����һ��C����С��Ŀ
 * �����ˣ���
 * ��  �ڣ�2018-02-20
 * ��  ����1.1
 * ��  �ͣ�
 *
 **************************************************/

typedef enum _proptype
{
    Weapon,Armor,Consumables,Card,Fragment
}PropType;
/*���������ߣ�����Ʒ����Ƭ����Ƭ*/
typedef struct _prop
{
    int id;              //���߱��
    char name[50];       //��������
    int level;           //���߼���
    int stock;           //���ߵĿ��������ұ����еĵ�������
    int price;        //���߼۸�
    PropType type;       //��������
    union
    {
        int mindefence;
        int minattack;
    }Min;
    union
    {
        int maxdefence;
        int maxattack;
    }Max;
    char desc[200];
}Prop;


/*����*/
typedef struct _bag{
    int count;                  //��ǰ�����е��ߵ�����
    int max;                    //��ǰ�����Ĳ������
    Prop props[9];              //��ǰ�����еĵ�������
}Bag;


/*��ͼ*/
typedef struct _map
{
    int id;
    char name[50];
    int minLevel;       //��ҽ������͵ȼ�
    COORD coord;        //��ͼ����
    char desc[500];
}Map;


typedef struct _player
{
    int id;
    char name[51];
    char password[50];
    char role[50];
    int level;
    int exp;
    int gamecredit;//��Ϸ����
    int hp;
    int mp;
    int gold;
    int attack;
    int defence;
    Prop weapon;
    Prop armor;
    Bag bag;
    struct _player *next;
}Player;

typedef struct _list{
    struct _player * head;
    struct _player * tail;
}List;

List *Target,ShanXi,BeiJing,GuangDong,JiangSu,HeiLongJiang,HeiLongJiang;

/*����*/
typedef struct _monster
{
    int id;
    char name[50];
    int hp;
    int attack;
    int defence;
    int minMoney;
    int maxMoney;
    int exp;
    int state;
    COORD coord;
}Monster;

void GameStart();
void Register();
void Login();
void ShowHeart1();
void ShowGameInfo();
void ShowWelcome();
void ShowMap();
void ShowMapInfo();
void ShowInfomation();
void ShowMainMenu();
void ProcessMainMenu(char key);
void ShowPlayerInfo();
void ShowMonster();
void FightMonster(int,int*);
void AreaMovement();
void ShowStore();
void Transaction();
void ShowBag();
void UseProps();
void FunnyGames();

#endif // SWORDSMAN_H_INCLUDED

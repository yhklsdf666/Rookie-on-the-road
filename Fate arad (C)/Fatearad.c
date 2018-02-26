#include "Head.h"

/*********************************************************************************************************/

/*������Ϣ*/
Prop propArray[] =
{
{1,"����-��֧��",2,5,2000,Weapon,.Min.minattack=1,.Max.maxattack=4},
{2,"����N-����",3,5,5000,Weapon,.Min.minattack=1,.Max.maxattack=4},
{3,"��������",1,5,500,Weapon,.Min.minattack=1,.Max.maxattack=4},
{4,"�Ļ���Ӱ��װ",1,5,500,Armor,.Min.mindefence=100,.Max.maxdefence=500},
{5,"ħս��˫��װ",1,5,500,Armor,.Min.mindefence=100,.Max.maxdefence=500},
{6,"�����׷���װ",1,5,500,Armor,.Min.mindefence=100,.Max.maxdefence=500},
{7,"���õ�HPҩ��(100%)",1,5,500,Consumables,"�ָ�100%HP��"},
{8,"����������Ԯ��(30%)",1,5,500,Consumables,"�ָ�30%HP��MP��������еȼ����쳣״̬��"},
{9,"Ǭ����(+1)",1,5,500,Consumables,"�����������+1��"}
};

/*��ͼ��Ϣ*/
Map mapArray[8][8] =
{
    {
        {1, "�ն����",   1, {0, 0}, "�����Ǳ������ʱ��һ����������ҵ���У������밵����������ŵ������һ������Ϊһ�����ߣ�����Ϊһ�����ǡ��ݴ����߽���ɢ��һ�������ң��������б���һ���Ҵ档�����˲�����ǣ����߹������ﾹȻ�Ҳ�������ԭ�����ʬ�塣ŵ˹������껹�������������š�ռ�죬����ð�ռ��ǽ�������ţ���������������һֱ���á��������̩��ʯ��Դ�ḻ�����𽥸��ա�"},
        {2, "��ɫ��ׯ",   1, {1, 0}, "�����ʹ����֮ɭһ�������ƶ�֮�ء� ������������ŵ��ɭ�������ʥ����Χ������ǿ�����ʥ��Ϣ�����û���ܵ�����͵��˺����Ҵ�����ǣ����������ؾۼ���ʥ����Χ���ڲ���������γ���һ��С���䡰��ɫ��ׯ���� �����֮�����쳣�����ľ�����Ҳ��ʥ��ǿ�����Ϣ���������׷׾ۼ����������������ʥ����ʥ����Ϣ�»ָ��˲�����������������������ᾧ�壬�����ڻķϵĴ���ϣ���ͳ������ɫ��ׯ��������ͬ���Եľ���ᾧ�����ֳ���ͬ����ɫ���Դ˻��ֲ�ͬ�ľ�����ء� "},
        {3, "���պ���", 1, {2, 0}, "³�������պ���λ�ڸ������ߡ���˹�������϶˵ĸۿڣ��������ڰ�˹��������е���������һ���ڿ����صĽ�������Ϊ���档���ڣ��ʶ����ո����������һ���̶��Ͻ������ؽ������ǣ�һЩ�뿨����ǩ����Լ�ĺ�������ı��֣�ȴƵ��Ϯ�������г����ܶຣ���г����ò�ֹͣͨ�У�ͣ���ڸۿڡ�"},
        {4, "����˹", 1, {3, 0}, "����˹λ�������޷��ش�����ɭϿ���У���������ռ����Ϊ����Ҫս��Ҫ���������ĵ��ƺ�Ũ�ص�������ʹ����Ϊ���ؾ������ʵľ��ѵص㡣Ҳ��Ϊ��������ʹ�����Ѿ��ָ��������ʶ������޷��ո�������鱨�ƻ�Ů�����Ҳ�����͵��˺���˹����Ϊ��ȷ�������Ϣ���ʶ���������ʿ��ǰ������˹����������������"},
        {5, "���Ǹߵ�", 1, {4, 0}, "���Ǹߵ�������֮��--���桤����פ�ص�����ݡ�����԰��Ǹߵص����λ�ս�������ľ�ս֮������������Ϊ�����صľ���Ҫ����Ҳ������Ϊ���桤�����������Ȼ�����ز����ѱ�������������Ժ���Ͷ������˼������ʹս��Խ��Խ�ҡ���"},
        {6, "����֮��", 1, {5, 0}, "����ۼ��Ÿ��ָ������ˣ��в��ܻ�ӭ�ġ������������ģ����б����䡢�������������ѵ�.....���������ż�į�����ţ�һֱ�������ֻΪ��һ����ͬ�����ɡ���Ѱ���Ǹ�����׽������ô�˵����˵��������ϲ�����һλ��˵�е�ǿ�ߣ�ֻҪ˭�ܹ���������Ϳ���վ�ڼ��յĶ��塣"},
        {7, "���޼�̳", 1, {6, 0}, "���˽�����ļ�������ȷ��������������ڻ������Ÿ�ǿ���������ֻ�Ǻ���ȥ�ھ򡭡������������ս�����Ҷ�����ļ��޳�������Ļ����͵��������ɡ������������Ŀǰ��ʵ��������ļ��ޣ���ô���»���˸��������Ĵ��ۡ���"},
        {8, "˹��ѩ��", 1, {7, 0}, "��ͼ����׶���Ϊ�˶��ÿ30������һ�ε�ѩɽ����˹��������ͼ�岻�ò������Ե�Խ�������������������������ռ䡣����ʱ��Ǩ�Ƶİ�ͼ����ԣ��׶�����ʿ��ܲ�̫ǡ��������ͼ���ǽ��׶�������˹��ѩ��󣬲�û�м��������泷�ˡ� �������ѩɽ����Զ����������Ժ������Ŀ���ѩɽ��"}
    },
    {
        {9, "  ", 1, {0, 2}, " "},
        {10, " ", 1, {1, 2}, " "},
        {11, " ", 1, {2, 2}, " "},
        {12, " ", 1, {3, 2}, " "},
        {13, " ", 1, {4, 2}, " "},
        {14, " ", 1, {5, 2}, " "},
        {15, " ", 1, {6, 2}, " "},
        {16, " ", 1, {7, 2}, " "}
    },
    {
        {17, "����֮��", 1, {0, 2}, " �һ��׷�𸡻���������Ӱ�������������һ�̲�������һ�в��������ޣ�������������ÿ�����������������Щ�ڳ����ие������������˰������ѽ������������������ڴ˵����֣�������Ҳ�������������ļ尾��ֱ��������ɣ���ȡ����������������������ɣ� "},
        {18, "����֮��", 1, {1, 2}, " û���Ҿ������񣡲����㲻Ҫ���£������ǲ���������ɵİ���һ���˵�������������ǿ�߶Ծ����˰���Ϊ���������ǵ��������ҽ����˴�������ڤ���ǿ�߾���һ�á��Ǻǣ����ǵĶ�־�Ѿ�ȼ���˰ɣ�ֻ�������ܵ����������ұ�֤ȫ���綼��������ǵ�ǿ�󣡵�Ȼ����ʼ�ջ������ʧ�ܵ��ǿ̣�������~��������...... "},
        {19, "�޾���̳", 1, {2, 2}, "������������������һҹ�������ǾͿ�������ɣ�������רΪ����׼���ļ�̳���������̳�ֻҪ���в�η����������������ӵ������ĲƸ��������������������ú������壬�ȴ����ǵ�������ֹ����ս������ħ���ջ��������ٻ������ɱ���˫�۵�ð�ռ��ǰ���ԡѪ��ս�ɣ�"},
        {20, "������Ѩ", 1, {3, 2}, "������Ѩ����ֲ��ı��������������´�½��12��ǰ������ʹͽϣ���ռ�ݱ�����Ѩ��ɱ���˶��ڵ�¾�ƣ��ֲ��ı�����Ҳ�����ʧ�ˡ���������Ѩ����д����˿ֲ��ı���������Ԥ����ʲô���ѵ��ǳ���¾�Ƹ��Ϊ�˽⿪���ţ�����˿�ʼǰ��������Ѩ����"},
        {21, "ŵ������", 1, {4, 2}, "ͻȻ�����Ĵ�Ⱦ���ð����������������һϦ֮������һ���ճǣ���ס������ľ������˿ֲ��ĵ�ʬ�ߣ��ε���Ư����Ѩ����������Թ�޵ı����������Ƕ���Ѫ�����˿����������ޱȵĳ��������ŵ���������ڻ����ŵ��ˡ����õ���һ��Ϣ֮�󣬰�����������������ǰ�����顣���ڣ����м�ֵ�������������԰���˿��ռ��--�����������Ĵ�Ⱦ��������ĵ۹��йء���һ�������಻���İ����飬���������Ԥ��֮��Խ�ӵĲ��������࡭��"},
        {22, "�㾧ɭ��", 1, {5, 2}, "�����ǵİ���֮�������ڻ�������Ѿ����֧�����顣��Ȼ������ɫ��ׯ��������ɭ�ֵ���Դ����̬�õ��˻ָ�����������ʧȥ��԰�ľ����ǣ����ڶ����˵ľ����ı��Խ��Խǿ��ҲԽ��Խ���й����ԣ�ð�ռ��ǣ���һ��ҪС�ġ�����"},
        {23, "֩������", 1, {6, 2}, "֩���������֩���������ֳɻ���������������������������˹�͹�����������Ϊ��������λ���޴���ʹ�ý��ɵ�������������֩�����������˱��������������֮·�����ڣ�����Ϊ������ν����λ����Ȼ�ںڰ��Ķ�Ѩ������ֹ�������š���"},
        {24, "а����ӡ", 1, {7, 2}, "�ܾ�֮ǰ��Ϊ�˷�ӡа��˹Ƥ�ȣ�������Ͱ����鸶���˾޴�Ĵ��ۡ�������֮��а���ķ�ӡ�ƺ������ɶ����ס����ھ޴����в��ǰ�����˺Ͱ������������ʱ�����ޣ�����ս����ϣ�����ǲ���ò�����롭��"}
    },
    {
        {25, "  ", 1, {0, 3}," "},
        {26, "  ", 1, {1, 3}, " "},
        {27, "  ", 1, {2, 3}, " "},
        {28, "  ", 1, {3, 3}, " "},
        {29, "  ", 1, {4, 3}, " "},
        {30, "  ", 1, {5, 3}, " "},
        {31, "  ", 1, {6, 3}, " "},
        {32, "  ", 1, {7, 3}, " "}
    },
    {
        {33, "����ʥս", 1, {0, 4}, "һ�����ҵĽ�ս��ʥְ�������ڼ��ѵĻ����˻���֮������Ͱ�����ʿ�ǡ���Ϊ�����������սʤ�˺ڰ�����������ⳡս������ʷ�ϱ���Ϊ����ʥս����ʷ�鲻����ص��ǣ���һ��СŮ�����������˼���������ⳡս����ʧ�ٵ�ʥְ�߸�硭��"},
        {34, "ĺɫ֮��", 1, {1, 4}, "�ڰ����٣��������������������������������ǧ��Ҫͣ�½Ų���ֻ�����Ź���ǰ�������п���������������"},
        {35, "����ͥԺ", 1, {2, 4}, "Ϊʲô�������������֮·�����﾿����ʲô�������㣬�������㲻ϧ��������ҲҪһ̽�������������ֵ����������ס�������һ�����Σ��ֲ���ȫ���Σ������ľ�����ʱ�����㸶�������Ĵ��ۣ�"},
        {36, "����þ�", 1, {3, 4}, "�����´�½��������һ���������Ƶĳǣ�����������ۼ����������ð�ռ�ǰ������ϧ�����Ѿ��⵽���ƻ�����Ҳ�������յ��ٹ⡣����Ҫ��Ϊ�������ܹ���������ˣ�������ج����ʱ�����������վ�����"},
        {37, "��ɫѩɽ", 1, {4, 4}, "��ʹ���������ѩ���ǵ�ɽ�ϣ��ڰ�Ҳ����������һ�㽵�١�������ʹ�ཫ���������޾��ľ�����С�ģ���Ҫ���ڰ������ˡ���"},
        {38, "ج��֮Դ", 1, {5, 4}, "���ڵ�����ج�ε�������������������ج�εĸ�Դ��������ܽ���ն������ô��һ�п��ܾ�Ҫ�����ˡ���ǧ���ܵ������ģ�һ���ߴ��ͻ���������������Ԩ��"},
        {39, "���ط���", 1, {6, 4}, "�ʶ���ͻϮ�����ڼ䣬��ȡ����������׼�������ܹ����鱨��һ�������ط����ܹ���ð�ռ��ǽ�Ҫ�����Щ���ӿ��Ŀ����ر��ţ�ð�ռ���Ψ�мᶨ��������Ŭ���赲�����ر��ţ�����Ϊ�ʶ�����ȡ��һ���ʱ�䡣����ð�ռ����ܼ�ֵ������"},
        {40, "������ɽ", 1, {7, 4}, "�����ر�ð�ռҺ͸��ؾ��񲿶Ӵ�ܺ�ʣ�µĲб��ܽ������˸��ر����Ĺ�����ɽ�������ｨ�������ı��ݡ����ǵ������Թ�������Ѽ����������Ļ����˸���Ϊ�Լ�����������ʣ������ʽ�����һ���޴�ĵ�������׼���Ը��ؽ��з�����ð�ռң�Ǳ�������ɽ�ݻٵ������������Թ�����������Ĳ��ಿ�Ӱɣ�"}
    },
    {
       {41, "  ", 1, {0, 3}, " "},
       {42, "  ", 1, {1, 3}, " "},
       {43, "  ", 1, {2, 3}, " "},
       {44, "  ", 1, {3, 3}, " "},
       {45, "  ", 1, {4, 3}, " "},
       {46, "  ", 1, {5, 3}, " "},
       {47, "  ", 1, {6, 3}, " "},
       {48, "  ", 1, {7, 3}, " "}
    },
    {
        {49, "  DNF", 1, {0, 7}, " "},
        {50, "  DNF", 1, {1, 7}, " "},
        {51, "  DNF", 1, {2, 7}, " "},
        {52, "  DNF", 1, {3, 7}, " "},
        {53, "  DNF", 1, {4, 7}, " "},
        {54, "  DNF", 1, {5, 7}, " "},
        {55, "  DNF", 1, {6, 7}, " "},
        {56, "  DNF", 1, {7, 7}, " "}
    },
    {
        {57, "  DNF", 1, {0, 3}, " "},
        {58, "  DNF", 1, {1, 3}, " "},
        {59, "  DNF", 1, {2, 3}, " "},
        {60, "  DNF", 1, {3, 3}, " "},
        {61, "  DNF", 1, {4, 3}, " "},
        {62, "  DNF", 1, {5, 3}, " "},
        {63, "  DNF", 1, {6, 3}, " "},
        {64, "  DNF", 1, {7, 3}, " "}
    }

};

/*�����Ϣ*/
Player players[50] = {
    {777,"�������","tgtgtg","�ڰ�����",90,1000,0,99999,99999,70000,66600,20000,{0,"�Ĺ��ų�̫��"},{0,"���½����װ"},{0,9}}
};

/*������Ϣ*/
Monster monsterArray[] = {
    {1, "Ͷ��ʮ��", 1, 10000, 1000, 100, 5, 10, 5, 1, {0, 0}},
    {2, "����è��", 2, 200, 8, 2, 5, 10, 5, 1, {0, 0}},
    {3, "԰��³��", 8, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {4, "����ʯ����", 8, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {5, "��֮�����������", 7, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {6, "���֮��", 6, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {7, "����֮����ʿ", 5, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {8, "���֮��", 6, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {9, "���֮��", 6, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {10, "���֮��", 6, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {11, "���֮��", 6, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {12, "���֮��", 6, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {13, "���֮��", 6, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {14, "���֮��", 6, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {15, "���֮��", 6, 100, 5, 2, 5, 10, 5, 1, {0, 0}},
    {16, "����ɳ����", 9, 100, 5, 2, 5, 10, 5, 1, {0, 1}}
};

/*********************************************************************************************************/
int X = 0,Y = 0;
int propsCount = sizeof(propArray)/sizeof(Prop);

Player *currPlayer = NULL;
Prop *currProp = NULL;

int Fatearad()
{
    SetTitle("����������");
    GameStart();            //and Register() and Login()
    SetColor(12,0);
    ShowHeart1();           //and ShowGameInfo()
    ShowWelcome();
    ShowMap();
    ShowInfomation();
    ShowMainMenu();

    while(1)
    {
        fflush(stdin);
        char key = getch();
        fflush(stdin);

        if(key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == 32)
        {
            ProcessMainMenu(key);
            continue;
        }
        else if(key == 'H' || key == VK_UP)      //��
        {
            Y--;
            Y--;
        }
        else if(key == 'M' || key == VK_RIGHT)      //��
        {
            X++;
        }
        else if(key == 'P' || key == VK_DOWN)      //��
        {
            Y++;
            Y++;
        }
        else if(key == 'K' || key == VK_LEFT)      //��
        {
            X--;
        }
        if(X>7) X=0;
        if(X<0) X=7;
        if(Y>4) Y=0;
        if(Y<0) Y=4;
        ShowMap();
        SetPosition(MARGIN_X+11,MAINMENU_START_Y+4);
    }
    return 0;
}


void GameStart()
{
    SetColor(10,0);
    SetPosition(55,11);
    printf("1.ע��\n");
    SetPosition(55,12);
    printf("2.��¼");
    SetPosition(55,14);
    printf("��Esc�˳�ϵͳ��");

    char key;
    fflush(stdin);
    while((key= getch())!='1' && key!='2' && key!=27);
    fflush(stdin);

    if(key == '1')  Register();
    if(key == '2')  Login();
    if(key == 27)
    {
        system("cls");
        exit(0);
    }
}


void Register()
{
    system("cls");

    int i,c,id;
    char name[50];

    for(i=0;players[i].id !=0;i++);
        currPlayer = &players[i];
        currPlayer -> id = i;       //��Ϸ��ʼ��һ��vip��Һڰ�������id��1��ʼ

    SetPosition(55,11);
    printf("Tips:���س�����������");
    SetPosition(55,12);
    printf("��������ʿ����");

    /*��ʼ���������*/
        scanf("%s",&name);
        strcpy(currPlayer -> name,name);

    SetPosition(55,13);
    printf("���������룺");
    for(i=0;(c=getche())!=13;++i)
    {
        currPlayer -> password[i] = c;
    }
        currPlayer -> hp = 10000;
        currPlayer -> mp = 10000;
        currPlayer -> level = 1;
        currPlayer -> gold = 50000000;
        currPlayer -> attack = 2000;
        currPlayer -> defence = 200;
        currPlayer -> bag.max = 3;

    SetPosition(55,15);
    printf("��ѡ���ɫ��");
    SetPosition(65,17);
    printf("1. ��ʿ(��)    2. �񶷼�(Ů)");
    SetPosition(65,19);
    printf("3. ��ǹ��(��)    4. ʥְ��");
    SetPosition(65,21);
    printf("5. ��ǹ��(Ů)    6. ��ҹʹ��");
    SetPosition(65,23);
    printf("7. �񶷼�(��)    8. �ػ���");
    SetPosition(65,25);
    printf("9. ħ��ʦ(��)    a. ħǹʿ");
    SetPosition(65,27);
    printf("b. ��ʿ(Ů)    c. �ڰ���ʿ");
    SetPosition(65,29);
    printf("d. ������");

    switch(c = getch())
    {
            case '1':   strcpy(currPlayer -> role,"��ʿ(��)");
        break;
            case '2':   strcpy(currPlayer -> role,"�񶷼�(Ů)");
        break;
            case '3':   strcpy(currPlayer -> role,"��ǹ��(��))");
        break;
            case '4':   strcpy(currPlayer -> role,"ʥְ��");
        break;
            case '5':   strcpy(currPlayer -> role,"��ǹ��(Ů) ");
        break;
            case '6':   strcpy(currPlayer -> role,"��ҹʹ��");
        break;
            case '7':   strcpy(currPlayer -> role,"�񶷼�(��)");
        break;
            case '8':   strcpy(currPlayer -> role,"�ػ���");
        break;
            case '9':   strcpy(currPlayer -> role,"ħ��ʦ(��)");
        break;
            case 'A':
            case 'a':   strcpy(currPlayer -> role,"ħǹʿ");
        break;
            case 'B':
            case 'b':   strcpy(currPlayer -> role,"��ʿ(Ů)");
        break;
            case 'C':
            case 'c':   strcpy(currPlayer -> role,"�ڰ���ʿ");
        break;
            case 'D':
            case 'd':   strcpy(currPlayer -> role,"������");
        break;
    }

    system("cls");
}


void Login()
{
    system("cls");
    SetPosition(55,11);
    int i,id;
    char logpass[50];
    printf("������id��");
    scanf("%d",&id);
    for(i=0;i<50;i++)
    {
        if(players[i].id == id)
        {
            currPlayer = &players[i];
            break;
        }
    }
    do
    {
    SetPosition(55,12);
    printf("                                                          ");
    SetPosition(55,12);
    printf("���������룺");
    scanf("%s",&logpass);
    }while(strcmp(currPlayer -> password,logpass));
    system("cls");
}


void ShowGameInfo()
{
    SetColor(10,0);
    SetPosition(MARGIN_X+7,MAP_START_Y+4);
    printf("*            *");
    SetPosition(MARGIN_X+7,MAP_START_Y+5);
    printf("  ����������  ");
    SetPosition(MARGIN_X+7,MAP_START_Y+6);
    printf("*            *");
    SetPosition(MARGIN_X+45,MAP_START_Y+14);
    SetColor(11,0);

    int i;
    char desc[500] = {"�԰�������977�꣬�����´�½��ʼ�������صġ���䡱�������Ƭ��½��û��һ�̰����� �����ڸ���֮���У�����һ�����Լ��������޸���ħ���󣬻����˶��ݵĺ�ƽ�� ���ǣ��������ת�����󼰸��������������ٶ�������Σ������ Ȼ������һ�е�ج��Ҳֻ�Ǹ���ʼ�� �ǳ�ʷ��ǰ�������Ѳ��������ؽ���Ƭ��½�������޾��ĵ����� �Ҵ����ǶԴ�ֻ����������Ŀ־壬���ǽ�֮��Ϊ��������͡��� ���ǳ������У����������´�½�����˴�ը���ܶ�ط���˳�Ϊ�˷��棬ʱ��Ҳ��Ϊ��ը�Ĺ�ϵ���һƬ���ҡ���"};
    int descLen = strlen(desc);
    for(i=0;i<descLen;++i)
    {
        if(i != 0 && i % 41 == 0)
            SetPosition(MARGIN_X+45,MAP_START_Y+14+i/41);
        printf("%c",desc[i]);
    }
    SetColor(10,0);
}


void ShowWelcome()
{
    SetPosition(MARGIN_X,0);
    printf(SEP);
    SetPosition(MARGIN_X,1);
    printf("|");
    SetPosition(MARGIN_X+34,1);
    printf("��ӭ���������´�½");
    SetPosition(MARGIN_X+83,1);
    printf("|");
    SetPosition(MARGIN_X,2);
    printf(SEP);
}


void ShowMap()
{
    int i,j;
    for(i=0;i<8;++i)
    {
        SetPosition(MARGIN_X,MAP_START_Y+i);
        printf("*");
        for(j=0;j<8;++j)
        {
            if(i == Y && j == X)
                SetColor(13,0);                 //���Ĺ���������ֵ���ɫ�ͱ���ɫ
            printf("  %-8s",mapArray[i][j].name);
                SetColor(10,0);                 //�ָ�Ĭ��ǰ��ɫ�ͱ���ɫ
        }
        SetPosition(MARGIN_X+83,i+3);
        printf("*\n");
    }
    SetPosition(MARGIN_X,MAP_END_Y);
    printf(SEP);
    ShowMapInfo();
}


void ShowMapInfo()
{
    /*1.�����Ϣ������Ϣ*/
    Clear(MARGIN_X + 7,INFO_START_Y,9);
    SetPosition(MARGIN_X+36,INFO_START_Y);
    printf("��%s��",mapArray[Y][X].name);
    SetPosition(MARGIN_X+12,INFO_START_Y+1);
    char *desc=mapArray[Y][X].desc;
    int descLen = strlen(desc);
    int i,j;
    for(i=0;i<descLen;++i)
    {
            if(i != 0 && i%60 == 0)
               SetPosition(MARGIN_X+12,INFO_START_Y+i/60+1);
            printf("%c",desc[i]);
    }
}


void ShowInfomation()
{
    SetPosition(MARGIN_X,INFO_START_Y);
    int i;
    for(i=0;i<9;++i)
    {
            SetPosition(MARGIN_X + 6,INFO_START_Y+i);
            printf("|");
            SetPosition(MARGIN_X + 77,INFO_START_Y+i);
            printf("|");
    }
    SetPosition(0,INFO_END_Y);
    printf(LSEP);
}


void ShowMainMenu()
{
/*    SetPosition(MARGIN_X,MAINMENU_START_Y);
    printf("��Ϸ�˵���");*/
    SetPosition(MARGIN_X, MAINMENU_START_Y + 1);
    printf("1��������Ϣ");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 2);
    printf("2�������ͼ");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 3);
    printf("3�������ƶ�");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 4);
    printf("4���Ӱ����������̵�");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 5);
    printf("5������");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 6);
    printf("0���˳���Ϸ");
    SetPosition(MARGIN_X + 65, MAINMENU_START_Y + 7);
    printf("������(Space)");
}


void ProcessMainMenu(char key)
{
    switch(key)
    {
    case '1':   ShowPlayerInfo();
        break;
    case '2':   ShowMonster();
        break;
    case '3':   AreaMovement();
        break;
    case '4':   ShowStore();
        break;
    case '5':   ShowBag();
        break;
    case 32 :   FunnyGames();
        break;
    case '0':
        exit(0);
    default:
        return;
    }
}


void ShowPlayerInfo()
{
    Clear(MARGIN_X + 7,INFO_START_Y,9);
    SetPosition(MARGIN_X + 30, INFO_START_Y);
    printf("*%s*�ĸ����������£�",currPlayer -> name);
    SetColor(12,0);
    printf("\t   %s",currPlayer -> role);
    SetColor(10,0);

    SetPosition(MARGIN_X + 7, INFO_START_Y + 2);
    printf("ID��%-7d",currPlayer -> id);
    printf("�ȼ���%-7d",currPlayer -> level);
    printf("����ֵ��%-9d",currPlayer -> hp);
    printf("ħ��ֵ��%-9d",currPlayer -> mp);
    printf("����ֵ��%d",currPlayer -> exp);

    SetPosition(MARGIN_X + 9, INFO_START_Y + 4);
    printf("\t��������%-13d",currPlayer ->attack);
    printf("��������%-13d",currPlayer -> defence);
    printf("�Ƹ���%d��",currPlayer -> gold);

    SetPosition(MARGIN_X + 7, INFO_START_Y + 6);
    printf("��ǰ������%s(������%d-%d)    ",currPlayer -> weapon.name,currPlayer -> weapon.Min.minattack,currPlayer -> weapon.Max.maxattack);
    printf("��ǰ���ߣ�%s(������%d-%d)",currPlayer -> armor.name,currPlayer -> armor.Min.mindefence,currPlayer -> armor.Max.maxdefence);
}


void ShowMonster()
{
    if(currPlayer -> hp <= 0)
        return;

    Clear(MARGIN_X + 7,INFO_START_Y,9);
    SetPosition(MARGIN_X +29, INFO_START_Y);

    //��ǰ��ͼ�����±�����
    int monsterIndexs[15];
    //��ǰ��ͼ�Ĺ�������
    int currMapMonsterCount = 0;
    int monsterCount = sizeof(monsterArray) / sizeof(Monster);
    int i;
    for(i = 0;i < monsterCount; ++i)
    {
        if(monsterArray[i].coord.X == X && monsterArray[i].coord.Y == Y && monsterArray[i].state != 0)
        {
        monsterIndexs[currMapMonsterCount++] = i;
        if(currMapMonsterCount == 9)
            break;
        }
    }
    if(currMapMonsterCount == 0)
    {
        printf(" ");
        return;
    }
    printf("��ǰ��ͼ���������µĹ��");
    SetPosition(MARGIN_X + 7, INFO_START_Y+2);
    for(i=0;i<currMapMonsterCount;++i)
    {
        if(i!=0 && i%3 == 0)
        SetPosition(MARGIN_X + 7, INFO_START_Y+2+2*i/3);
        printf("%d.%-23s",i+1,monsterArray[monsterIndexs[i]].name);
    }
    FightMonster();             //����
}


void FightMonster()
{
    //��ǰ��ͼ�����±�����
    int monsterIndexs[9];
    //��ǰ��ͼ�Ĺ�������
    int currMapMonsterCount = 0;
    int monsterCount = sizeof(monsterArray) / sizeof(Monster);
    int i;
    for(i = 0;i < monsterCount; ++i)
    {
        if(monsterArray[i].coord.X == X && monsterArray[i].coord.Y == Y && monsterArray[i].state != 0)
        {
        monsterIndexs[currMapMonsterCount++] = i;
        if(currMapMonsterCount == 9)
            break;
        }
    }

    SetPosition(MARGIN_X + 7, INFO_END_Y - 1);
    printf("������Ҫ�����Ķ���");
    char key;
    fflush(stdin);
    key = getch();
    fflush(stdin);
    if(key >= '1' && key <='currMapMonsterCount')
    {
        for(i=0;;++i)
        {
            SetPosition(MARGIN_X + 7, INFO_END_Y - 1);
            if(currPlayer -> hp >= 0 && monsterArray[monsterIndexs[key - 49]].hp >= 0)
            {
                currPlayer -> hp -= monsterArray[monsterIndexs[key - 49]].attack + currPlayer -> defence;
                monsterArray[monsterIndexs[key - 49]].hp -= currPlayer -> attack + monsterArray[monsterIndexs[key - 49]].defence;
                printf("ս����%d��\t%sHP:%d\t%sHP:%d",i+1,currPlayer -> name,currPlayer -> hp,monsterArray[monsterIndexs[key - 49]].name,monsterArray[monsterIndexs[key - 49]].hp);
                Sleep(100);
                Clear(MARGIN_X + 7,INFO_END_Y - 1,1);
            }
            else
                break;
        }
        /*�����*/
        if((currPlayer -> hp) <= 0)
        {
            SetPosition(MARGIN_X + 7, INFO_END_Y - 1);
            printf("                                                                                    ");
            SetPosition(MARGIN_X + 7, INFO_END_Y - 1);
            printf("���ѱ��⺷�Ĺ���Ź���������Ƿ�ʹ�ø���ң�����1��Ϸ���֣�����Y/N��");
            key = getch();
            if(key == 'y' || key == 'Y')
            {
                if(currPlayer -> gamecredit <= 0)
                {
                SetPosition(MARGIN_X + 7, INFO_END_Y - 1);
                printf("������Ϸ���ֲ��㣡");
                currPlayer -> level --;
                currPlayer -> hp = 0;
                return;
                }
                currPlayer -> gamecredit --;
                currPlayer -> hp = 100;
            }
            if(key == 'n' || key == 'N')
            {
                currPlayer -> level --;
                currPlayer -> hp = 0;
            }
        }
        /*������*/
        else if(monsterArray[monsterIndexs[key - 49]].hp <= 0)
        {
        printf("%s�ѱ���ɱ�������%d���飬%d��ҡ�",monsterArray[monsterIndexs[key - 49]].name,monsterArray[monsterIndexs[key - 49]].exp,monsterArray[monsterIndexs[key - 49]].maxMoney);
        currPlayer -> exp += monsterArray[monsterIndexs[key - 49]].exp;
        currPlayer -> gold += monsterArray[monsterIndexs[key - 49]].maxMoney;
        monsterArray[monsterIndexs[key - 49]].state = 0;
        }
    }
    else
    {
        SetPosition(MARGIN_X + 7, INFO_END_Y - 1);
        printf("Ҫ�����Ĺ��ﲻ���ڣ��������������");
    }
}


void AreaMovement()
{
    int i,j;
    char mapname[50];
    SetPosition(MARGIN_X+2, MAINMENU_START_Y + 3);
    printf(" ������Ŀ����������(�Ҿ���˾�������ϳ���!): ");
    SetColor(13,0);
    scanf("%s",&mapname);
    SetColor(10,0);
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(!(strcmp(mapArray[i][j].name,mapname)))
            {
                X = mapArray[i][j].coord.X;
                Y = mapArray[i][j].coord.Y;
                break;
            }
        }
    }

    SetPosition(MARGIN_X, MAINMENU_START_Y + 3);
    printf("                                                               ");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 3);
    printf("3�������ƶ�");
    ShowMap();
}

/*
    int id;              //���߱��
    char name[50];       //��������
    int level;           //���߼���
    int stock;           //���ߵĿ��������ұ����еĵ�������
    double price;        //���߼۸�
    PropType type;       //��������
    union
    {
        int minattack;
        int mindefence;
        int minpower;       //����Ʒ
    };
    union
    {
        int maxattack;
        int maxdefence;
    };
*/

void ShowStore()
{
    int i = -1;
    do
    {
        if(i == '1')
            ShowBag();

        Clear(0,INFO_START_Y,21);
        Clear(60,INFO_START_Y,21);

        SetPosition(MARGIN_X, INFO_START_Y);
        printf("                                                                                                       ");
        SetPosition(MARGIN_X,32);
        printf("                                                                                                                ");
    for(i=0;i<propsCount;i++)
    {
        SetPosition(32, 14+i*2);
        if(propArray[i].type == Weapon)
            printf("%d.%-15s(������%d-%d)\t[���:%d]\t���ۣ�%d",i+1,propArray[i].name,propArray[i].Min.minattack,propArray[i].Max.maxattack,propArray[i].stock,propArray[i].price);
        else if(propArray[i].type == Armor)
            printf("%d.%-15s(������%d-%d)\t[���:%d]\t���ۣ�%d",i+1,propArray[i].name,propArray[i].Min.mindefence,propArray[i].Max.maxdefence,propArray[i].stock,propArray[i].price);
        else if(propArray[i].type == Consumables)
            printf("%d.%-23s\t[���:%d]\t���ۣ�%d",i+1,propArray[i].name,propArray[i].stock,propArray[i].price);
    }

    Transaction();
    SetPosition(MARGIN_X,32);
    printf("��ʿ-�밴0�˳�����,��1�鿴������");

    }while((i = getch())!='0');

    Clear(0,INFO_START_Y,21);
    Clear(60,INFO_START_Y,21);
    ShowInfomation();
    ShowMainMenu();
}


void Transaction()
{
        int i,id,propId,buyNum;
        SetPosition(MARGIN_X, INFO_START_Y);
        printf("��ӭ����~���˾�Ҫ��~�̵꣬������Ҫ�������ƷID������:");
        scanf("%d %d",&propId,&buyNum);
        for(i=0;i<propsCount;i++)
    {
        if(propId==propArray[i].id)
        {
            currProp=&propArray[i];    //tradeProp=props+i                         ??? &����
            break;
        }
    }
        if(currProp -> stock <= 0)
        {
            SetPosition(MARGIN_X, INFO_START_Y);
            printf("��Ʒ����������˵�����Щ�ö���������");
            return;
        }
        if(currPlayer -> gold < currProp -> price)
        {
            SetPosition(MARGIN_X, INFO_START_Y);
            printf("�������ڰ����´�½��Ҫ����ģ�");
            return;
        }
        if(currPlayer -> bag.count >= currPlayer -> bag.max /*&&player->bag.count!=0*/)
        {
            SetPosition(MARGIN_X, INFO_START_Y);
            printf("���ı�����������Ͽ���������!");
            return;
        }

        //���㽻��������ִ�н��׵Ĳ���
        //1.��Ʒ���-1
        currProp -> stock -= buyNum;
        //2.��ҽ��-��Ʒ����
        currPlayer -> gold -= (currProp -> price)*buyNum;
        //*3.��ұ�����������
        //�ж���ұ������Ƿ����и���Ʒ
        //���û�и���Ʒ������Ʒ��ӵ���������
        //������и���Ʒ�������еĸ���Ʒ������buyNum
        for(i=0;i<currPlayer->bag.count;i++)
        {
            //���Ҫ�������Ʒid�������е�ĳ����Ʒid��ͬ
            if(propId == currPlayer->bag.props[i].id)
            {
                currPlayer -> bag.props[i].stock += buyNum;
                break;
            }
        }
        if(i == currPlayer -> bag.count)                   //���û�и���Ʒ������Ʒ��ӵ�������
        {
            int newIndex = currPlayer-> bag.count;
            //�򱳰��д���һ����Ʒ��������һ��Ҫ���׵���Ʒ��Ϣ��������
            currPlayer->bag.props[newIndex].id = currProp->id;
            strcpy(currPlayer->bag.props[newIndex].name,currProp->name);
            currPlayer->bag.props[newIndex].level = currProp->level;
            currPlayer->bag.props[newIndex].type = currProp->type;
            currPlayer->bag.props[newIndex].Min = currProp->Min;
            currPlayer->bag.props[newIndex].Max = currProp->Max;
            strcpy(currPlayer->bag.props[newIndex].desc,currProp->desc);


            currPlayer->bag.props[newIndex].stock=buyNum;
            currPlayer->bag.count++;
        }
}



void ShowBag()
{
    int i;
    do
    {
        if(i == '1')        ShowStore();
            else if(i == '2')   UseProps();

    Clear(0,INFO_START_Y,21);
    Clear(60,INFO_START_Y,21);

    SetPosition(MARGIN_X, INFO_START_Y);
    printf("                                                                           ");
    SetPosition(MARGIN_X, INFO_START_Y);
    printf("����ǰ�ı������������%d",currPlayer -> bag.max);
    SetPosition(MARGIN_X,32);
    printf("                                                                           ");
    SetPosition(MARGIN_X,32);
    printf("��0������Ϸ����1����Ӱ����������̵꣬��2ʹ����Ʒ");

    for(i=0;i<currPlayer -> bag.count;i++)
    {
        SetPosition(32, 14+i*2);
        if(currPlayer -> bag.props[i].type == Weapon)
            printf("%d.%-15s(������%d-%d)\t[����:%d]",i+1,currPlayer -> bag.props[i].name,currPlayer -> bag.props[i].Min.minattack,currPlayer -> bag.props[i].Max.maxattack,currPlayer -> bag.props[i].stock);
        else if(currPlayer -> bag.props[i].type == Armor)
            printf("%d.%-15s(������%d-%d)\t[����:%d]",i+1,currPlayer -> bag.props[i].name,currPlayer -> bag.props[i].Min.mindefence,currPlayer -> bag.props[i].Max.maxdefence,currPlayer -> bag.props[i].stock);
        else if(currPlayer -> bag.props[i].type == Consumables)
            printf("%d.%-23s[����:%d]",i+1,currPlayer -> bag.props[i].name,currPlayer -> bag.props[i].stock);
    }
    }while((i = getch()) != '0');

    Clear(0,INFO_START_Y,21);
    Clear(60,INFO_START_Y,21);
    ShowInfomation();
    ShowMainMenu();
}


void UseProps()
{
    SetPosition(MARGIN_X,32);
    printf("                                                                           ");
    SetPosition(MARGIN_X,32);
    printf("������Ҫʹ�õĵ��߱��(δ�����...)��");
    fflush(stdin);
    int c = getche();
    fflush(stdin);


}


void FunnyGames()
{
    int num = -1;
    while(num != '0')
    {
    system("cls");
    SetPosition(40,4);
    SetColor(12,0);
    printf("Gamecredit: %d",currPlayer -> gamecredit);
    SetColor(10,0);
    SetPosition(40,7);
    printf("1.2048 (Unclock in source code!)");
    SetPosition(40,9);
    printf("2.Five in a row");
    SetPosition(40,11);
    printf("3.Gluttonous snake (Unclock in source code!)");
    SetPosition(40,13);
    printf("4.The tank war");
    SetPosition(40,15);
    printf("5.Mine clearance");
    SetPosition(40,17);
    printf("6.Labyrinth");
    SetPosition(40,19);
    printf("7.Flappy bird");
    SetPosition(40,21);
    printf("8.Tetris");
    SetPosition(40,23);
    printf("0.Exit");

    num = getch();
    system("cls");
        switch(num)
    {
//      case '1': Game2048();         break;
        case '2': GameGobang();       break;
//      case '3': GameSnake();        break;
        case '4': GameTank();         break;
        case '5': GameSweep();        break;
        case '6': GameLabyrinth();    break;
        case '7': GameFlappyBird();   break;
        case '8': GameTetris();       break;
        default:                      continue;
    }
        currPlayer -> gamecredit ++;        //��Ϸ���ּ�1
    }
    system("cls");
    ShowWelcome();
    ShowMap();
    ShowInfomation();
    ShowMainMenu();
}

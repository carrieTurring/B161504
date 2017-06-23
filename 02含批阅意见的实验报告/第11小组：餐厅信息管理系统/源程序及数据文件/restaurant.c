#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct Custome
{
	int num;
    char name[20];
	char sex[6];
	char tel[12];
	char id[5];
	int food[20];
	int service;
	int total;
}Custome;


typedef struct Food
{
	int num;
	char name[20];
	char taste[10];
	char category[10];
    int cost;
}Food;

typedef struct Database//���ݿ�ṹ�� ��Ų�Ʒ�͹˿�
{
	Food f[30];
	Custome c[20];
}Database;
Database database={0};

void gotoxy(int x ,int y)
{
	int xx=0x0b;
	HANDLE hOutput;
	COORD Ioc;
	Ioc.X = x;
	Ioc.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput,Ioc);
}

void saveFile(void)
{
	FILE *fp = fopen("database.txt", "w");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		return;
	}
	fwrite(&database, sizeof(database), 1, fp);//���ṹ��д���ļ�
	fclose(fp);
	return;
}

void startup(void)
{
	FILE *fp = fopen("database.txt", "r");
	if (fp == NULL)
	{
		fp = fopen("database.info", "wb+");
		if(fp != NULL)
			fclose(fp);
		return;
	}
	fread(&database, sizeof(database), 1, fp);//���ļ�����ṹ��
	fclose(fp);
	return;
}

void tableNum()//�����Ų���
{
	int num,i=0,j=0,k,sum=0,m=11;
	gotoxy(25,10);
	printf("����������:");
	scanf("%d",&num);
	fflush(stdin);
	while(database.c[i].num!=0)
	{
		if (database.c[i].num==num)
		{
           while(database.c[i].food[j]!=0)
		   {
			   for (k=0;k<=20;k++)
			   {
				   if (database.f[k].num==database.c[i].food[j])
				   {
					   gotoxy(15,m);
					   printf("%-10s  %-10s  %-10s  %dԪ\n",database.f[k].name,database.f[k].taste,database.f[k].category,database.f[k].cost);
					   sum+=database.f[k].cost;
					   m++;
					   break;
				   }
			   }
			   j++;
		   }
		   gotoxy(15,m++);
		   printf("�˿���Ϣ:  %-5s  %-5s ��Ա����:%-5s  �ֻ���:%-10s\n",database.c[i].name,database.c[i].sex,database.c[i].id,database.c[i].tel);
		   gotoxy(15,m);
		   printf("�ܼ�Ϊ:%dԪ\n",sum);
		   return;
		}
		i++;
	}
	gotoxy(15,10);
	printf("�����˿Ͳ����ڣ�����");
}

void telNum()//���ֻ��Ų���
{
	int i=0,j=0,k,sum=0,m=11;
	char tel[12];
	gotoxy(25,10);
	printf("�������ֻ���:");
	gets(tel);
	while(database.c[i].num!=0)
	{
		if (strcmp(tel,database.c[i].tel)==0)
		{
			while(database.c[i].food[j]!=0)
			{
				for (k=0;k<=20;k++)
				{
					if (database.f[k].num==database.c[i].food[j])
					{
						gotoxy(15,m);
						printf("%-10s  %-10s  %-10s  %dԪ\n",database.f[k].name,database.f[k].taste,database.f[k].category,database.f[k].cost);
						sum+=database.f[k].cost;
						m++;
						break;
					}
				}
				j++;
			}
			gotoxy(15,m++);
			printf("�˿���Ϣ:  %-5s  %-5s ��Ա����:%-5s  �ֻ���:%-10s\n",database.c[i].name,database.c[i].sex,database.c[i].id,database.c[i].tel);
			gotoxy(15,m);
			printf("�ܼ�Ϊ:%dԪ\n",sum);
			return;
		}
		i++;
	}
	gotoxy(15,10);
	printf("�˹˿Ͳ����ڣ�����");
}

void id()//��id����
{
	int i=0,j=0,k,sum=0,m=11;
	char id[5];
	gotoxy(25,10);
	printf("�����뿨��:");
	gets(id);
	while(database.c[i].num!=0)
	{
		if (strcmp(id,database.c[i].id)==0)
		{
			while(database.c[i].food[j]!=0)
			{
				for (k=0;k<=20;k++)
				{
					if (database.f[k].num==database.c[i].food[j])
					{
						gotoxy(15,m);
						printf("%-10s  %-10s  %-10s  %dԪ\n",database.f[k].name,database.f[k].taste,database.f[k].category,database.f[k].cost);
						sum+=database.f[k].cost;
						m++;
						break;
					}
				}
				j++;
			}
		    gotoxy(15,m++);
			printf("�˿���Ϣ:  %-5s  %-5s ��Ա����:%-5s  �ֻ���:%-10s\n",database.c[i].name,database.c[i].sex,database.c[i].id,database.c[i].tel);
			gotoxy(15,m);
			printf("�ܼ�Ϊ:%dԪ\n",sum);
			return;
		}
		i++;
	}
	gotoxy(15,10);
	printf("�˹˿Ͳ����ڣ�����");
}

void Jm()
{
	system("cls");
	printf("###########################################################################\n");//�����û�����
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("#                                                                         #\n");
	printf("###########################################################################\n");

}

void add()					//���Ӳ������Ա��Ϣ 
{
	FILE *fp; 
	char c[2]={' '},d[2]={'\n'},e[2]={'#'};
	Custome people;
	fp = fopen("member.txt","a+");
	gotoxy(25,10);
	printf("�������Ա����:");
	gets(people.name);

	gotoxy(25,11);
	printf("�������Ա�Ա�:");
	scanf("%s",people.sex);

	gotoxy(25,12);
	printf("�������Ա����:");
	scanf("%s",people.id);

	gotoxy(25,13);
	printf("�������Ա�ֻ�:");
	scanf("%s",people.tel);

	fputs(e,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
    fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(c,fp);
	fputs(people.name,fp);
	fputs(c,fp);
	fputs(people.sex,fp);
	fputs(c,fp);
	fputs(people.id,fp);
	fputs(c,fp);
	fputs(people.tel,fp);
	fputs(d,fp);
	fclose(fp);

	gotoxy(25,18);
	printf("��ӳɹ�!");
	Sleep(3000);
}

void draw()
{
    FILE *f1;
    char c;
    f1 = fopen("member.txt","r");
    gotoxy(25,10);
    printf("��Ա��Ϣ�� \n");
    while((c=getc(f1)) != EOF)
    printf("%c",c);
    fclose(f1);
}

void delet()
{
	FILE *f1;
    char c[2]={' '};
    f1 = fopen("database.txt","w+");
    while((getc(f1)) != EOF)
    fputs(c,f1);
    fclose(f1);
}

void main()
{
    /*Food p[30]={{1,"����˿","����","�Ȳ�",15},
	{2,"������","����","�Ȳ�",30},
	{3,"ʱ��ƴ��","��ζ","����",12},
	{4,"�Ǵ��Ｙ","����","�Ȳ�",28},
	{5,"��Ȼ����","����","�Ȳ�",24},
	{6,"��������","��ζ","�Ȳ�",15},
	{7,"����ţ��","����","����",18},
	{8,"������","��ζ","��",13},
	{9,"ˮ��ƴ��1","��ζ","��Ʒ",13},
	{10,"�ɱ���ϸ�","��ζ","��",25},
	{11,"�������","����","�Ȳ�",38},
	{12,"����С��Ϻ","��ζ","�Ȳ�",98},
	{13,"һͰ����","��ζ","�Ȳ�",83},
	{14,"�����ﵶ��","����","�Ȳ�",53},
	{15,"��ը��Ϻ","��ζ","�Ȳ�",45},
	{16,"����ţ���","��ζ","��",33},
	{17,"һƷ��ţ","��ζ","����",18},
	{18,"Դ�Ͽ���","��ζ","�Ȳ�",30},
	{19,"ˮ��ƴ��2","��ζ","��Ʒ",13},
	{20,"��֦��¶","��ζ","��Ʒ",28}};
	Custome q[20]={{1,"��־��","��","18750176089","28",{1,2,5,7,8,20,19,5},0,0},
	{2,"���","��","17766107049","5",{1,3,6,7,8,9},0,0},
	{3,"���","Ů","18851821076","18",{2,3,7,8},0,0},
	{4,"�żκ�","��","13681452850","21",{4,13,17,9,7,8},0,0},
	{5,"��ѩ��","Ů","13657421048","270",{4,5,6,7,8},0,0},
	{6,"������","��","13123161269","2701",{4,5,8,20},0,0},
	{7,"��һ��","��","13799434844","2991",{14,15,16,7,8},0,0},
	{8,"���ν�","Ů","13802501687","2837",{4,5,16,7,18},0,0},
	{9,"��÷��","Ů","13654807040","2741",{4,11,12,17,8},0,0},
	{10,"��һ��","��","13985252850","1264",{4,13,16,7,20},0,0},
	{11,"����","��","13210522450","689",{4,5,6,7,8,11,13,15,17,19},0,0},
	{12,"����","��","13628282584","656",{1,2,3,7,8,20},0,0},
	{13,"��˧","��","13513662584","2375",{4,5,6,17,18,20},0,0},
	{14,"���","��","13315345314","3678",{4,5,16,7,18,20},0,0},
	{15,"����","��","13628435143","227",{14,5,16,7,8,20},0,0},
	{16,"������","��","13668738566","70",{14,5,16,7,18,20},0,0},
	{17,"�Ϻ�Ȼ","��","138388282584","5027",{4,5,20},0,0},
	{18,"��Խ","��","13776842584","27",{4,5,8,20},0,0},
	{19,"�Ŷ�","��","13628282996","127",{1,7,8,20},0,0},
	{20,"�ƹ���","��","13625492584","527",{8,20},0,0}};
	FILE *fp = fopen("database.txt", "w");
	fwrite(p, sizeof(p), 1, fp);
	fwrite(q, sizeof(q), 1, fp);*/ 
  int flag,k=1;
  char a[12],adm[12]="18750176089";
  char b[7],key[7]="980829";
  Jm();
  gotoxy(25,2);
  printf("�������˺�:");
  scanf("%s",a);
  gotoxy(25,3);
  printf("����������:");
  scanf("%s",b);
  if(!strcmp(a,adm)&&!strcmp(b,key))
  {
	  gotoxy(25,4);
	  printf("������ȷ");
	  startup();
  while(k)
  {
  Jm();
  gotoxy(25,2);
  printf("Chaiman��������ϵͳ\n");
  gotoxy(25,3);
  printf("1.�������Ų�ѯ�㵥\n");
  gotoxy(25,4);
  printf("2.�����ֻ��Ų�ѯ�㵥\n");
  gotoxy(25,5);
  printf("3.�����Ա���Ų�ѯ�㵥\n");
  gotoxy(25,6);
  printf("4.��ӻ�Ա\n");
  gotoxy(25,7);
  printf("5.��ӡ��Ա��Ϣ��\n");
  gotoxy(25,8);
  printf("6.��յ������嵥\n");
  gotoxy(25,9);
  scanf("%d",&flag);
  fflush(stdin);
  switch(flag)
  {
  case 1:tableNum();system("pause");system("cls");break;
  case 2:telNum();system("pause");system("cls");break;
  case 3:id();system("pause");system("cls");break;
  case 4:add();system("pause");system("cls");break;
  case 5:draw();system("pause");system("cls");break;
  case 6:delet();system("pause");system("cls");break;
  case 7:k=0;break;
  }
  }
  }
  else
  {
	  gotoxy(25,4);
      printf("�������");
  }
}

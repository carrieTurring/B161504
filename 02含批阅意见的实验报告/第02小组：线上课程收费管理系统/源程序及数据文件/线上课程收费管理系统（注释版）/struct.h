#include<stdio.h>
#define NUM 100
typedef struct course{//�γ̽ṹ�� 
	char name[25];
	int time[4];//������ʼʱ���Сʱ�ͷ��ӣ�����ʱ���Сʱ�ͷ��� 
	int member[2];//�����γ���ѡ����������������� 
	float tuition;
	char category[20];
	int ID;
}course;
typedef struct student{//ѧ���ṹ�� 
	char ID[10];
	char name[10];
	char sex[7];
	course cor[2];//����ѡ��1��ѡ��2 
	float fee;
}student;

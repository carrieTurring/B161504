/* ��student.h�ļ����������� */
#ifndef _CAR            /*�������룬��ֹ�ظ������Ĵ���*/
#define _CAR
#include <string.h>
#define NUM 50                /*����ѧ�������������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct CAR                   /*ѧ����¼��������*/
{
		long num;
		char name[20];
	
		int p1;
		int p2;
		int p3;
};
typedef struct CAR CAR;
#define sizeC sizeof(CAR)      /*һ��ѧ����¼����Ҫ���ڴ�ռ��С*/
int readC(CAR c[],int n);       /*����ѧ����¼ֵ��ѧ��Ϊ0������涨������¼ʱֹͣ*/
void printC(CAR  *c , int n);   /*�������ѧ����¼��ֵ*/

int equal(CAR c1,CAR c2,int condition);  /*����condition�����ж�����Student����������ȷ�*/
int larger(CAR c1,CAR c2,int condition);  /*����condition�Ƚ�Student�������ݴ�С*/
void reverse(CAR c[],int n);             /*ѧ����¼����Ԫ������*/



void sortC(CAR c[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/

int searchC(CAR c[],int n,CAR ca,int condition,int f[]) ;  /*������������������s��ȵĸ�Ԫ��*/
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
int insertC(CAR c[],int n,CAR ca);                   /*�������в���һ��Ԫ�ذ�ѧ������*/
int deleteC(CAR c[],int n,CAR ca);                   /*��������ɾ��һ��ָ��ѧ�ŵ�Ԫ��*/
#endif

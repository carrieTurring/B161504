/*��student.c�ļ�����������*/
#include "student.h"
#include <stdio.h>

int readC(CAR  *c , int n)          /*����ѧ����¼ֵ��ѧ��Ϊ0������涨������¼ʱֹͣ*/
{
	int i;
	for (i=0;i<n;i++)
	{    
		printf("Input one car information\n");
		printf("num:  ");
	        scanf("%ld", &c[i].num);
	
		printf("name: ");
		scanf("%s",c[i].name);	
		printf("original price");
                scanf("%ld",&c[i].p1);
                printf("present price");
                scanf("%ld",&c[i].p2);
    	        c[i].p3=c[i].p1-c[i].p2;                
		
		
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printC ( CAR  *c , int n)       /*�������ѧ����¼��ֵ*/
{	
    int i;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", c[i].num);
		printf("%8s", c[i].name);
		printf("%7d", c[i].p1);
	        printf("%7d",c[i].p2);
	    printf("%7d",c[i].p3);
	    
	}
}

int equal(CAR c1,CAR c2,int condition)  /*����ж�����Student��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�ѧ��*/
		return c1.num==c2.num;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(c1.name,c2.name)==0) 	return 1;
		else return 0;
     }

 else if (condition==3)                /*�������condition��ֵΪ4����Ƚ��ܷ�*/
		return c1.p3==c2.p3;
	else return 1;                       /*�����������1*/
} 

int larger(CAR c1,CAR c2,int condition)  /*����condition�����Ƚ�����Student��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚ�ѧ��*/
		return c1.num>c2.num;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ��ܷ�*/
		return c1.p3>c2.p3;	
	else return 1; /*�����������1*/
}

void reverse(CAR c[],int n)             /*����Ԫ������*/
{
	int i;
	CAR temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=c[i];
		c[i]=c[n-1-i];
		c[n-1-i]=temp;
	}
}






void sortC(CAR c[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	CAR t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(c[minpos],c[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=c[i];
			c[i]=c[minpos];
			c[minpos]=t;
		}
	}
}

int searchC(CAR c[],int n,CAR ca,int condition,int f[ ])  /*��stu��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(c[i],ca,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}

int insertC(CAR c[],int n,CAR ca)              /*��stu��������ѧ�ŵ�������һ��Ԫ��s*/
{
	int i;
	sortC(c,n,1);                              /*�Ȱ�ѧ������*/
	for (i=0;i<n;i++)
	{
		if (equal(c[i],ca,1))                      /*ѧ����ͬ��������룬��֤ѧ�ŵ�Ψһ��*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*��ѧ�Ŵ�С��������*/
	{
		if (!larger(c[i],ca,1))                    /*���s���ڵ�ǰԪ��stu[i]�����˳�ѭ��*/
		break;
		c[i+1]=c[i];                         /*����Ԫ��stu[i]����һ��λ��*/
	}
	c[i+1]=ca;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deleteC(CAR c[],int n,CAR ca)            /*��������ɾ��ָ��ѧ�ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(c[i],ca,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(stu[i],s,1)����*/ 
		c[j]=c[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}
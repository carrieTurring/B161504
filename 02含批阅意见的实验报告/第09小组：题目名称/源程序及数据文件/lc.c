/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"student.h"

void printHead( )      /*��ӡѧ����Ϣ�ı�ͷ*/
{
printf("%8s%10s%8s%6s%6s\n","���","����","ԭ��","�ּ�","���");
}

void menu( )         /*����˵�����*/
{       printf("********  ������Ŷ�Ӧ ********\n");
        printf("********              0.���� ********\n");
        printf("********              1.����********\n");
		printf("********              2.�ݴ�********\n");
		printf("******** 0.�Ͼ�       3.�µ� ********\n");
		printf("******** 1.�Ϻ�       4.·��  ********\n");
		printf("******** 2.����       5.������********\n");
		printf("******** 3.����       6.�ݱ� ********\n");
		printf("******** 4.����       7.ɣ���� ********\n");
		printf("********              8.��Խ********\n");
		printf("********              9.���Դ�********\n");
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
        printf("******** 3. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ����������¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ��������¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸�������¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}


 

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. ����Ų�ѯ   ########\n");
		printf("######## 2. �����Ͳ�ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage(CAR c[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*��ѧ�Ž��в���ɾ���޸ģ�ѧ�Ų����ظ�*/
{  
		int choice,t,find[NUM];
     CAR ca;
do
	    {   
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readC(&ca,1);       /*����һ���������ѧ����¼*/
					 n=insertC(c,n,ca);   /*���ú�������ѧ����¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&ca.num);  /*����һ����ɾ����ѧ��ѧ��*/
					 n=deleteC(c,n,ca);   /*���ú���ɾ��ָ��ѧ�ŵ�ѧ����¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&ca.num);  /*����һ�����޸ĵ�ѧ��ѧ��*/
				      t=searchC(c,n,ca,1,find) ; /*���ú�������ָ��ѧ�ŵ�ѧ����¼*/
				      if (t)                 /*�����ѧ�ŵļ�¼����*/
					 {
						  readC(&ca,1);   /*����һ��������ѧ����¼��Ϣ*/
					      c[find[0]]=ca;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*�����ѧ�ŵļ�¼������*/ 
 printf("this car is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}



void searchManage(CAR c[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
CAR ca;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a CAR\'s num will be searched:\n");
				      scanf("%ld",&ca.num);         /*�������ѯѧ����ѧ��*/
					  break;
				case 2:   printf("Input a CAR\'s name will be searched:\n");
				      scanf("%s",ca.name);	          /*�������ѯѧ��������*/		  
				      break;   
				
				case 0:   break;
			}
		 	if (choice>=1&&choice<=2)
			{ 
				findnum=searchC(c,n,ca,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printC(&c[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(CAR c[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortC(c,n,1);         /*��ѧ����С�����˳�������¼*/ 
          	 printC(c,n);          /*��ѧ����С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(c,n);    /* 2. ������Ϣ����*/
			   	     break;
		
			case 3: searchManage(c,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		CAR c[NUM];                /*����ʵ��һά����洢ѧ����¼*/
      int choice,n;
	 n=readFile(c);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(c);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(c,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortC(c,n,1);                   /*�����ļ�ǰ��ѧ����С��������*/ 
	     saveFile(c,n);                   /*����������ļ�*/
      return 0;
}

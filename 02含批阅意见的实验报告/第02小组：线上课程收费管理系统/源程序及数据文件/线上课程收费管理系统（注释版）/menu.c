#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"
int mainMenu(){
	int n=-1;
	char a[25];
	printf("******** 1. ��ʾ������Ϣ ********\n");
	printf("******** 2. ��ѯ�����Ϣ ********\n");
	printf("******** 3. �γ���Ϣ���� ********\n");
	printf("******** 4. ѧ����Ϣ���� ********\n");
	printf("******** 5. ѧ��������� ********\n");
	printf("******** 0. �˳�         ********\n");
	printf("Please input your choice: ");
	scanf("%d",&n);
	if(n==-1){
		scanf("%s",a);//��ֹ�����ַ������ҳ���ִ�� 
		n=10;
	}
	return n;
}

int infMenu(){
	int n=-1;
	char a[25];
	printf("%%%%%%%%%%%%%%%% 1. ��ʾѧ����Ϣ %%%%%%%%%%%%%%%%\n");
	printf("%%%%%%%%%%%%%%%% 2. ��ʾ�γ���Ϣ %%%%%%%%%%%%%%%%\n");
	printf("%%%%%%%%%%%%%%%% 0. �����ϲ�˵� %%%%%%%%%%%%%%%%\n");
	printf("Please input your choice: ");
	scanf("%d",&n);
	if(n==-1){
		scanf("%s",a);//��ֹ�����ַ������ҳ���ִ�� 
		n=10;
	}
	return n;
}

int crsMngMenu(){
	int n=-1;
	char a[25];
	printf("@@@@@@@@ 1. ��ӿγ���Ϣ @@@@@@@@\n");
	printf("@@@@@@@@ 2. �޸Ŀγ���Ϣ @@@@@@@@\n");
	printf("@@@@@@@@ 3. ɾ���γ���Ϣ @@@@@@@@\n");
	printf("@@@@@@@@ 4. ���γ̺����� @@@@@@@@\n");
	printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
	printf("Please input your choice: ");
	scanf("%d",&n);
	if(n==-1){
		scanf("%s",a);//��ֹ�����ַ������ҳ���ִ�� 
		n=10;
	}
	return n;
}

int stdMngMenu(){
	int n=-1;
	char a[25];
	printf("$$$$$$$$ 1. ���ѧ����Ϣ $$$$$$$$\n");
	printf("$$$$$$$$ 2. �޸�ѧ����Ϣ $$$$$$$$\n");
	printf("$$$$$$$$ 3. ɾ��ѧ����Ϣ $$$$$$$$\n");
	printf("$$$$$$$$ 0. �����ϲ�˵� $$$$$$$$\n");
	printf("Please input your choice: ");
	scanf("%d",&n);
	if(n==-1){
		scanf("%s",a);//��ֹ�����ַ������ҳ���ִ�� 
		n=10;n=10;
	}
	return n;
}

int eryMenu(char ID[10]){
	int n=-1;
	char a[25];
	if(strcmp(ID,"")==0){//�ж���������ѧ����ѧ�������Ƿ���� 
		printf("Please input your student's ID:");
		scanf("%s",ID); 
		FILE *fp;
		student temp[NUM],*p=temp;
		int i=0;
		if((fp=fopen("statistic_s.dat","rb"))==NULL){
			printf("Can not open the file!Please check your disk!\n\a");
		}else{
			fread(temp,sizeof(temp[0]),1,fp);
			while(!feof(fp)){
				if(strcmp(ID,temp[i].ID)==0){
					printf("&&&&&&&& 1. �鿴��ѡ�γ� &&&&&&&&\n");
					printf("&&&&&&&& 2. ѡ�޿γ̹��� &&&&&&&&\n");
					printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
					printf("Please input your choice: ");
					scanf("%d",&n);
					if(n==-1){
						scanf("%s",a);//��ֹ�����ַ������ҳ���ִ�� 
						n=10;
					}
					return n;
				}
				i++;
				p++;
				fread(p,sizeof(temp[0]),1,fp);
			}
			fclose(fp);
		}
		printf("Student not found!\n");
		system("pause");
		return 0;
	}else{
		printf("&&&&&&&& 1. �鿴��ѡ�γ� &&&&&&&&\n");
		printf("&&&&&&&& 2. ѡ�޿γ̹��� &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
		printf("Please input your choice: ");
		scanf("%d",&n);
		if(n==-1){
			scanf("%s",a);//��ֹ�����ַ������ҳ���ִ�� 
			n=10;
		}
		return n;
	}
}

int srhMenu(){
	int n=-1;
	char a[25];
	printf("######## 1. ��ѯ�γ���Ϣ ########\n");
	printf("######## 2. ��ѯѧ����Ϣ ########\n");
	printf("######## 0. �����ϲ�˵� ########\n");
	printf("Please input your choice: ");
	scanf("%d",&n);
	if(n==-1){
		scanf("%s",a);//��ֹ�����ַ������ҳ���ִ�� 
		n=10;
	}
	return n;
}

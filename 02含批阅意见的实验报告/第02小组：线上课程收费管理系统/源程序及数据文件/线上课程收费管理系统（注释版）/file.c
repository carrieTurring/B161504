#include<stdio.h>
#include <stdlib.h>
#include<string.h>
void createFile(){
	FILE *fp;
	if((fp=fopen("statistic_s.dat","rb"))==NULL){//���ѧ�����ݿⲻ��������ѧ�����ݿ� 
		if((fp=fopen("statistic_s.dat","wb"))==NULL){
			printf("Can not open the file!Please check your disk!\n\a");
			exit(1);
		}
		fclose(fp);
	}
	if((fp=fopen("statistic_c.dat","rb"))==NULL){//����γ����ݿⲻ���������γ����ݿ� 
		if((fp=fopen("statistic_c.dat","wb"))==NULL){
			printf("Can not open the file!Please check your disk!\n\a");
			exit(1);
		}
		fclose(fp);
	}	
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"struct.h"
#include"menu.h"
#include"file.h"
#include"method.h"
int main(){
	createFile();//����ѧ���Ϳγ����ݿ� 
	printf("---------------------------------\n");
	printf("\n    ��ӭʹ�ÿγ��շѹ���ϵͳ\n");
	printf("           Welcome to\n");
	printf("the course fee management system!\n");
	printf("\n---------------------------------\n\n");
	printf("%35s","���ߣ���贡�̷���ġ�����\n\n");//��ӡ��ӭ�˵� 
	mainMenu: 
	switch(mainMenu()){//��ӡ���˵� 
		case 5: {
			char ID[10];
			strcpy(ID,""); 
			eryMenu:
			switch(eryMenu(ID)){//ѧ���������   ���뱨��ѧ��ID 
				case 1: {
					showCrsInf(ID);//��ѡ�γ̲�ѯ 
					system("pause");
					goto eryMenu;
					break;
				}
				case 2:{
					if(cngStdCrs(ID)){//�޸�ѡ�α��� 
						printf("Progress complete!\n");
					}else{
						printf("Progress failed!\n");
					}
					system("pause");
					goto eryMenu;
					break;
				}
				case 0: strcpy(ID,"");////�������˵������ѧ��ID 
						goto mainMenu;
						break;
				default: printf("Error of input!\n");
						 system("pause");
						 goto eryMenu;
			}
			break;
		}
		case 1:{
			infMenu: 
			switch(infMenu()){//��ӡ������Ϣ�˵�
				case 1: {
					showInf_s();//��ʾѧ����Ϣ 
					system("pause");
					goto infMenu;
				}
				case 2:{
					showInf_c();//��ʾ�γ���Ϣ 
					system("pause");
					goto infMenu;
				}
				case 0: goto mainMenu;//�������˵� 
						break;
				default: printf("Error of input!\n");
						 system("pause");
						 goto infMenu;
			}
			break;
		}	
		case 3:{
			crsMngMenu:
			switch(crsMngMenu()){//�γ̹���˵� 
				case 1:{
					if(addCrsInf()){//��ӿγ���Ϣ 
						printf("Progress complete!\n");
					}else{
						printf("Progress failed!\n");
					}
					system("pause");
					goto crsMngMenu;
				}
				case 2:{
					if(cngCrsInf()){//�޸Ŀγ���Ϣ 
						printf("Progress complete!\n");
					}else{
						printf("Progress failed!\n");
					} 
					system("pause");
					goto crsMngMenu;
				} 
				case 3:{
					if(delCrsInf()){//ɾ���γ���Ϣ 
						printf("Progress complete!\n");
					}else{
						printf("Progress failed!\n");
					}
					system("pause");
					goto crsMngMenu;
				}	
				case 4:{
					if(rnkCourse()){//���ݿγ̺����� 
						printf("Progress complete!\n");
					}else{
						printf("Progress failed!\n");
					}
					system("pause");
					goto crsMngMenu;
				}	
				case 0: goto mainMenu;//�������˵� 
						break;
				default: printf("Error of input!\n");
						 system("pause");
						 goto crsMngMenu;
			}
			break;
		} 
		case 4:{
			stdMngMenu:
			switch(stdMngMenu()){//ѧ����Ϣ���� 
				case 1: {
					if(addStdInf()){//���ѧ�� 
						printf("Progress complete!\n");
					}else{
						printf("Progress failed!\n");
					}
					system("pause");
					goto stdMngMenu;
				}
				case 2: {
					if(cngStdInf()){//�޸�ѧ����Ϣ 
						printf("Progress complete!\n");
					}else{
						printf("Progress failed!\n");
					} 
					system("pause");
					goto stdMngMenu;
				} 
				case 3: {
					if(delStdInf()){//ɾ��ѧ�� 
						printf("Progress complete!\n");
					}else{
						printf("Progress failed!\n");
					}
					system("pause");
					goto stdMngMenu;
				}		
				case 0: goto mainMenu;//�������˵� 
						break;
				default: printf("Error of input!\n");
						 system("pause");
						 goto stdMngMenu;
			}
			break;
		}	
		case 2:{
			srhMenu:
			switch(srhMenu()){//��ӡ��ѯ�˵� 
				case 1: srhCourse();//��ѯ�γ� 
						system("pause");
						goto srhMenu;
				case 2: srhStudent();//��ѯѧ�� 
						system("pause");
						goto srhMenu;
				case 0: goto mainMenu;//�������˵� 
						break;
				default: printf("Error of input!\n");
						 system("pause");
						 goto srhMenu;
			}
			break;
		}	
		case 0: printf("\n��л����ʹ�ã��ټ���\n\n");//�����Ϣ 
				system("pause");
				return 0;
		default:printf("Error of input!\n");
				system("pause");
				goto mainMenu;
	}
}

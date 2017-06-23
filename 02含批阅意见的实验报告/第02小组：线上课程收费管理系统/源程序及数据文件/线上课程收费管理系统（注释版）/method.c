#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"
void showInf_s(){//��ʾѧ����Ϣ 
	FILE *fp;
	student st;
	printf("%-12s%-11s%-11s%-25s%-25s%-9s\n","ѧ��","����","�Ա�","��ѡ�γ�1","��ѡ�γ�2","�ܷ���");
	printf("-------------------------------------------------------------------------------------------\n");
	if((fp=fopen("statistic_s.dat","rb"))==NULL){//��ȡ��������ʽ�ļ� ��ѧ���� 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(&st,sizeof(st),1,fp);
		while(!feof(fp)){
			printf("%-12s%-11s%-11s%-25s%-25s%-9.1f\n",st.ID,st.name,st.sex,st.cor[0].name,st.cor[1].name,st.fee);
			fread(&st,sizeof(st),1,fp);
		}
	}
	fclose(fp);
}

void showInf_c(){//��ʾ�γ���Ϣ 
	FILE *fp;
	course crs;
	printf("%-9s%-25s%-15s%-12s%-9s%-7s\n","�γ̺�","�γ�����","�Ͽ�ʱ��","��������","ѧ��","�γ̷���");
	printf("-------------------------------------------------------------------------------\n");
	if((fp=fopen("statistic_c.dat","rb"))==NULL){//��ȡ��������ʽ�ļ� ���γ̣� 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(&crs,sizeof(crs),1,fp);
		while(!feof(fp)){//���д���γ���Ϣ 
			printf("%-9d%-25s%",crs.ID,crs.name);
			if(crs.time[1]<10){//����ʱ�������ʽ 
				printf("%2d:0%d-",crs.time[0],crs.time[1]);
			}
			if(crs.time[1]>=10){
				printf("%2d:%d-",crs.time[0],crs.time[1]);
			}
			if(crs.time[3]<10){
				printf("%2d:0%-5d",crs.time[2],crs.time[3]);
			}
			if(crs.time[3]>=10){
				printf("%2d:%-6d",crs.time[2],crs.time[3]);
			}
			printf("%2d/%-9d%-9.1f%-7s\n",crs.member[0],crs.member[1],crs.tuition,crs.category);
			fread(&crs,sizeof(crs),1,fp);
		}
	}
	fclose(fp);
}

int judge(char ID[10],student temp[NUM]){//�ж�ѧ���Ƿ��ظ� ����ѧ����Ϣʱ���ã�addStdInf()�� 
	FILE *fp;
	int i=0;
	if((fp=fopen("statistic_s.dat","rb"))==NULL){//��ȡ��������ʽ�ļ���ѧ��0 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(temp,sizeof(temp[0]),1,fp);
		while(!feof(fp)){//�����Ա�ѧ���ж��Ƿ��ظ� 
			if(strcmp(ID,temp[i].ID)==0)
				return 0;
			fread(temp,sizeof(temp[0]),1,fp);
		}
		fclose(fp);
	}
	return 1;
}

int judge_2(int ID,course temp[NUM]){//�жϿγ̺��Ƿ��ظ� ���ӿγ���Ϣʱ���ã�addCrsInf()�� 
	FILE *fp;
	int i=0;
	if((fp=fopen("statistic_c.dat","rb"))==NULL){//��ȡ��������ʽ�ļ����γ̣� 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(temp,sizeof(temp[0]),1,fp);
		while(!feof(fp)){//���жԱȿγ̺��ж��Ƿ��ظ� 
			if(ID==temp[i].ID)
				return 0;
			fread(temp,sizeof(temp[0]),1,fp);
		}
		fclose(fp);
	}
	return 1;
}

int judge_3(char ID[10],student temp[NUM],char num[10]){//�ж�ѧ���Ƿ��ظ� �޸�ѧ����Ϣʱ���ã�cngStdInf()�� 
	FILE *fp;
	int i=0;
	if((fp=fopen("statistic_s.dat","rb"))==NULL){//��ȡ��������ʽ�ļ���ѧ���� 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(temp,sizeof(temp[0]),1,fp);
		while(!feof(fp)){//���жԱ�ѧ���ж��Ƿ��ظ� 
			if(strcmp(ID,temp[i].ID)==0&&strcmp(num,temp[i].ID)!=0)
				return 0;
			fread(temp,sizeof(temp[0]),1,fp);
		}
		fclose(fp);
	}
	return 1;
}

int judge_4(int ID,course temp[NUM],int num){//�жϿγ��Ƿ��ظ� �޸Ŀγ���Ϣʱ���ã�cngStdInf()��
	FILE *fp;
	int i=0;
	if((fp=fopen("statistic_c.dat","rb"))==NULL){//��ȡ��������ʽ�ļ����γ̣� 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(temp,sizeof(temp[0]),1,fp);
		while(!feof(fp)){//���жԱȿγ̺��ж��Ƿ��ظ� 
			if(ID==temp[i].ID&&num!=temp[i].ID)
				return 0;
			fread(temp,sizeof(temp[0]),1,fp);
		}
		fclose(fp);
	}
	return 1;
}

int addStdInf(){//���ѧ����Ϣ 
	FILE *fp;
	student st;
	student temp[NUM];
	if((fp=fopen("statistic_s.dat","ab"))==NULL){//��׷�ӵķ�ʽд���������ʽ�ļ���ѧ���� 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
			printf("Please input information of the student:\n");
			printf("ID: ");
			scanf("%s",&st.ID);
			if(judge(st.ID,temp)){//�ж�ѧ���Ƿ��ظ� 
				printf("Name: ");
				scanf("%s",&st.name);
				printf("Sex: ");
				scanf("%s",&st.sex);
				strcpy(st.cor[0].name,"");
				strcpy(st.cor[1].name,"");
				st.fee=0;
				fwrite(&st,sizeof(st),1,fp);
				fclose(fp);
			}else{
				fclose(fp);
				printf("This record exist, you can not insert again!\n");
				return 0;
			}	
	}
	return 1;
}

int addCrsInf(){//��ӿγ���Ϣ 
	FILE *fp;
	course crs;
	course temp[NUM];
    crs.ID=-100;
    crs.time[1]=-1;
    crs.time[3]=-1;
    crs.member[1]=-100;
    crs.tuition=-100;
	char b[25];
	if((fp=fopen("statistic_c.dat","ab"))==NULL){//��׷�ӵķ�ʽд���������ʽ�ļ����γ̣� 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
			printf("Please input information of the course:\n");
			do{
				printf("ID: ");
				scanf("%d",&crs.ID);
				if(crs.ID<=0){//��ֹ�����ַ������ҳ���ִ�� 
					if(crs.ID==-100){
						scanf("%s",b);
					}
					printf("Error of input!\n");
					system("pause");
				}
			}while(crs.ID<=0);
			if(judge_2(crs.ID,temp)){//�жϿγ̺��Ƿ��ظ� 
				printf("Name: ");
				scanf("%s",&crs.name);
				do{
					start:
					printf("Start time: ");
					scanf("%d:%d",&crs.time[0],&crs.time[1]);
					if(crs.time[1]==-1){//��ֹ�����ַ������ҳ���ִ�� 
						scanf("%s",b);
					    printf("Error of input!\n");
					    system("pause");
					    goto start;
					}
					if(crs.time[0]>24||crs.time[0]<0||crs.time[1]>60||crs.time[1]<0){//�ж�ʱ���ʽ 
						printf("Error format of time!\n");
						system("pause");
					}
				}while(crs.time[0]>24||crs.time[0]<0||crs.time[1]>60||crs.time[1]<0);
				do{
					action:
					printf("End time: ");
					scanf("%d:%d",&crs.time[2],&crs.time[3]);
					if(crs.time[3]==-1){//��ֹ�����ַ������ҳ���ִ�� 
						scanf("%s",b);
					    printf("Error of input!\n");
					    system("pause");
					    goto action;
					}
					if(crs.time[2]>24||crs.time[2]<0||crs.time[3]>60||crs.time[3]<0){//�ж�ʱ���ʽ 
						printf("Error format of time!\n");
						system("pause");
					}
					if(crs.time[2]<crs.time[0]||(crs.time[2]==crs.time[0]&&crs.time[3]<=crs.time[1])){//�жϿγ̽���ʱ���Ƿ���ڿ�ʼʱ�� 
						printf("Ending time must be larger than start time!\n");
						system("pause");
					}
				}while(crs.time[2]>24||crs.time[2]<0||crs.time[3]>60||crs.time[3]<0||(crs.time[2]<crs.time[0]||(crs.time[2]==crs.time[0]&&crs.time[3]<=crs.time[1])));
				begin:
				printf("Max member: ");
				scanf("%d",&crs.member[1]);
				if(crs.member[1]<=0){//��ֹ�����ַ������ҳ���ִ��  �ж����������Ƿ�С�ڵ���0 
					if(crs.member[1]==-100){
						scanf("%s",b);
					}
					crs.member[1]=-100;
					printf("Error of input!\n");
					system("pause");
					goto begin;
				}
				crs.member[0]=0;
				loop:
				printf("Tuition: ");
				scanf("%f",&crs.tuition);
				if(crs.tuition<=0){//��ֹ�����ַ������ҳ���ִ��  �ж�ѧ���Ƿ�С�ڵ���0 
					if(crs.tuition==-100){
						scanf("%s",b);
					}
					crs.tuition=-100;
					printf("Error of input!\n");
					system("pause");
					goto loop;
				}
				printf("Category: ");
				scanf("%s",&crs.category);
				fwrite(&crs,sizeof(crs),1,fp);
				fclose(fp);
			}else{
				fclose(fp);
				printf("This record exist, you can not insert again!\n");
				return 0;
			}	
	}
	return 1;
}

void srhStudent(){//��ѯѧ����Ϣ 
	FILE *fp;
	char inf[10];
	int i,rank,count=0;
	student temp[NUM];
	student *p=temp;
	if((fp=fopen("statistic_s.dat","rb"))==NULL){//��ȡ��������ʽ�ļ���ѧ���� 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(p,sizeof(temp[0]),1,fp);
		while(!feof(fp)){//�����ݿ��е�ѧ����Ϣ����temp 
			count++;
			p++;
			fread(p,sizeof(temp[0]),1,fp);
		}
		fclose(fp);
				printf("Input the information will be searched: ");
				scanf("%s",inf);
				printf("%-12s%-11s%-11s%-25s%-25s%-9s\n","ѧ��","����","�Ա�","��ѡ�γ�1","��ѡ�γ�2","�ܷ���");
				printf("-------------------------------------------------------------------------------------------\n");
				for(i=0;i<count;i++){//����ѧ��ѧ�š��������Ա���ѡ�γ̡���ѯ�������ʾ 
					if(strcmp(inf,temp[i].ID)==0||strcmp(inf,temp[i].name)==0||strcmp(inf,temp[i].sex)==0||strcmp(inf,temp[i].cor[0].name)==0||strcmp(inf,temp[i].cor[1].name)==0)
						printf("%-12s%-11s%-11s%-25s%-25s%-9.1f\n",temp[i].ID,temp[i].name,temp[i].sex,temp[i].cor[0].name,temp[i].cor[1].name,temp[i].fee);
				}
	}
}

void srhCourse(){//��ѯ�γ���Ϣ 
	FILE *fp;
	char inf[10];
	int i,rank,count=0;
	course temp[NUM];
	course *p=temp;
	if((fp=fopen("statistic_c.dat","rb"))==NULL){//��ȡ��������ʽ�ļ����γ̣� 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(p,sizeof(temp[0]),1,fp);
		while(!feof(fp)){//�����ݿ��еĿγ���Ϣ����temp 
			count++;
			p++;
			fread(p,sizeof(temp[0]),1,fp);
		}
		fclose(fp);
				printf("Input the information will be searched: ");
				scanf("%s",inf);
				printf("%-9s%-25s%-15s%-12s%-9s%-7s\n","�γ̺�","�γ�����","�Ͽ�ʱ��","��������","ѧ��","�γ̷���");
				printf("-------------------------------------------------------------------------------\n");
				for(i=0;i<count;i++){//���ݿγ̺š��γ����ơ��γ�����ѯ�������� 
					if(atoi(inf)==temp[i].ID||strcmp(inf,temp[i].name)==0||strcmp(inf,temp[i].category)==0){
							printf("%-9d%-25s%",temp[i].ID,temp[i].name);
							if(temp[i].time[1]<10){//���ʱ���ʽ 
								printf("%2d:0%d-",temp[i].time[0],temp[i].time[1]);
							}
							if(temp[i].time[1]>=10){
								printf("%2d:%d-",temp[i].time[0],temp[i].time[1]);
							}
							if(temp[i].time[3]<10){
								printf("%2d:0%-5d",temp[i].time[2],temp[i].time[3]);
							}
							if(temp[i].time[3]>=10){
								printf("%2d:%-6d",temp[i].time[2],temp[i].time[3]);
							}
							printf("%2d/%-9d%-9.1f%-7s\n",temp[i].member[0],temp[i].member[1],temp[i].tuition,temp[i].category);
					}
				}
	}
}

int cngStdInf(){//�޸�ѧ����Ϣ 
	FILE *fp;
	char num[10];
	int i,rank,count=0,j;
	student temp[NUM],reput,st[NUM];
	student *p=temp;
	if((fp=fopen("statistic_s.dat","rb+"))==NULL){//��ȡ��д���������ʽ�ļ���ѧ���� 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(p,sizeof(temp[0]),1,fp);
		while(!feof(fp)){//�����ݿ��е�ѧ����Ϣ����temp 
			count++;
			p++;
			fread(p,sizeof(temp[0]),1,fp);
		}
		printf("Input the student's ID: ");
		scanf("%s",num);
		for(i=0;i<count;i++){//���жԱ��ҵ�Ҫ�޸ĵ�ѧ�� 
			if(strcmp(num,temp[i].ID)==0){ 
				reput=temp[i];
				printf("ID: ");
				scanf("%s",&reput.ID);
				if(judge_3(reput.ID,st,num)){//�ж�ѧ���Ƿ��ظ� 
					printf("Name: ");
					scanf("%s",&reput.name);
					printf("Sex: ");
					scanf("%s",&reput.sex);
					fseek(fp,0L,0);
					for(j=0;j<i+1;j++){//������д�ļ� 
						if(j!=i){
							fwrite(&temp[j],sizeof(temp[0]),1,fp);
						}else{
							fwrite(&reput,sizeof(reput),1,fp);
						}
					}
					
					fclose(fp);
					return 1;
				}else{
					fclose(fp);
					printf("This ID is used by another student, you can not insert again!\n");
					return 0;
				}	
			}	
		}
		printf("Student not found!\n");
		return 0;
	}
}

int cngCrsInf(){//�޸Ŀγ���Ϣ 
	FILE *fp;
	FILE *dp;
	int num=-1;
	char a[25];
	char b[25];
	int i,rank,count=0,j,l,cnt=0;
	course temp[NUM],reput,crs[NUM];
	course *p=temp;
	student tmp[NUM],*q=tmp;
	if((fp=fopen("statistic_c.dat","rb+"))==NULL){//д�롢��ȡ��������ʽ�ļ����γ̣� 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(p,sizeof(temp[0]),1,fp);
		while(!feof(fp)){//�����ݿ��еĿγ���Ϣ����temp 
			count++;
			p++;
			fread(p,sizeof(temp[0]),1,fp);
		}
		begin:
		printf("Input the ID of the course: ");
		scanf("%d",&num);
		if(num==-1){//��ֹ�����ַ������ҳ���ִ�� 
			scanf("%s",a);
			printf("Error of input!\n");
			system("pause");
			goto begin;
		}
		for(i=0;i<count;i++){//���жԱ��ҵ��γ� 
			if(num==temp[i].ID){
				reput=temp[i];
				start:
				printf("New ID: ");
				scanf("%s",&b);
				if((reput.ID=atoi(b))<=0){//��ֹ�����ַ������ҳ���ִ�� 
					printf("Error of input!\n");
			        system("pause");
			        goto start;
				}
				if(judge_4(reput.ID,crs,num)){//�жϿγ̺��Ƿ��ظ� 
					printf("Name: ");
					scanf("%s",&reput.name);
					do{
						reput.time[1]=-1;
						action:
						printf("Start time: ");
						scanf("%d:%d",&reput.time[0],&reput.time[1]);
						if(reput.time[1]==-1){//��ֹ�����ַ������ҳ���ִ�� 
					        scanf("%s",a);
					        printf("Error of input!\n");
					        system("pause");
			                goto action;
				         }
						if(reput.time[0]>24||reput.time[0]<0||reput.time[1]>60||reput.time[1]<0){//�ж�ʱ���ʽ 
							printf("Error format of time!\n");
						}
					}while(reput.time[0]>24||reput.time[0]<0||reput.time[1]>60||reput.time[1]<0);
					do{
						reput.time[3]=-1;
						loop:
						printf("End time: ");
						scanf("%d:%d",&reput.time[2],&reput.time[3]);
						if(reput.time[3]==-1){//��ֹ�����ַ������ҳ���ִ�� 
					        scanf("%s",a);
					        printf("Error of input!\n");
					        system("pause");
			                goto loop;
				         }
						if(reput.time[2]>24||reput.time[2]<0||reput.time[3]>60||reput.time[3]<0){//�ж�ʱ���ʽ 
							printf("Error format of time!\n");
						}
						if(reput.time[2]<reput.time[0]||(reput.time[2]==reput.time[0]&&reput.time[3]<=reput.time[1])){//�жϽ���ʱ���Ƿ���ڳ�ʼʱ�� 
						    printf("Ending time must be larger than start time!\n");
						    system("pause");
					    }
					}while(reput.time[2]>24||reput.time[2]<0||reput.time[3]>60||reput.time[3]<0||(reput.time[2]<reput.time[0]||(reput.time[2]==reput.time[0]&&reput.time[3]<=reput.time[1])));
					start_2:
					printf("Max member: ");
					scanf("%s",&b);
				    if((reput.member[1]=atoi(b))<=0){//��ֹ�����ַ������ҳ���ִ�� �ж����������Ƿ�С�ڵ���0 
					    printf("Error of input!\n");
			            system("pause");
			            goto start_2;
			     	}
			     	reput.tuition=-100;
			     	start_3:
					printf("Tuition: ");
					scanf("%f",&reput.tuition);
					if(reput.tuition<=0){//��ֹ�����ַ������ҳ���ִ��  �ж�ѧ���Ƿ�С�ڵ���0 
					    if(reput.tuition==-100){
						    scanf("%s",a);
					    }
					    reput.tuition=-100;
					    printf("Error of input!\n");
					    system("pause");
					    goto start_3;
				    }
					printf("Category: ");
					scanf("%s",&reput.category);
					fseek(fp,0L,0);
					for(j=0;j<i+1;j++){//����д��γ���Ϣ 
						if(j!=i){
							fwrite(&temp[j],sizeof(temp[0]),1,fp);
						}else{
							fwrite(&reput,sizeof(reput),1,fp);
						}
					}
					fclose(fp);
					if((dp=fopen("statistic_s.dat","rb+"))==NULL){//�޸�ѡ��ÿγ̶�Ӧ��ѧ���Ŀγ���Ϣ�����ܷ��� 
						printf("Can not open the file!Please check your disk!\n\a");
				    }else{
					    fread(q,sizeof(tmp[0]),1,dp);
					    while(!feof(dp)){ //�����ݿ��е� ѧ����Ϣ����tmp 
					    	cnt++;
					    	q++;
					    	fread(q,sizeof(tmp[0]),1,dp);
				    	}
					    fseek(dp,0L,0);
					    for(l=0;l<cnt;l++){//������дѡ��ÿγ̶�Ӧ��ѧ���Ŀγ���Ϣ�����ܷ��� 
						    if(reput.ID==tmp[l].cor[0].ID){//���������ҵ���Ӱ���ѧ�� 
						    	tmp[l].cor[0]=reput;
						    	tmp[l].fee=tmp[l].cor[0].tuition+tmp[l].cor[1].tuition;
					    	}
					    	if(reput.ID==tmp[l].cor[1].ID){//���������ҵ���Ӱ���ѧ�� 
						    	tmp[l].cor[1]=reput;
								tmp[l].fee=tmp[l].cor[0].tuition+tmp[l].cor[1].tuition;	
					    	}
					    	fwrite(&tmp[l],sizeof(tmp[0]),1,dp);
				    	}
				        fclose(dp);
		   	        }
					return 1;
				}else{
					fclose(fp);
					printf("This ID is used by another course, you can not insert again!\n");
					return 0;
				}	
			}	
		}
		printf("Course not found!\n");
		return 0;
	}
}

int delStdInf(){//ɾ��ѧ����Ϣ 
	FILE *fp;
	FILE *dp; 
	int i,j,k,count=0,l;
	student st[NUM];
	student temp;
	course tmp[NUM],*p=tmp;
	char input[10],charge;
	loop:
	i=0;
	j=0;
	k=0;
	if((fp=fopen("statistic_s.dat","rb+"))==NULL){//д�롢��ȡ��������ʽ�ļ� ��ѧ���� 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
			printf("Please input the student's ID or name you want to delete: ");
			scanf("%s",input);
			scanf:
			printf("Are you sure to delete student %s ?(Y/N): ",input);//ȷ���Ƿ�ɾ�� 
				getchar();
				scanf("%c",&charge);
				switch(charge){
					case 'n':
					case 'N':return 0;
					case 'y':
					case 'Y':break;
					default: printf("Error of input!\n");
							 goto scanf;
				}
			fread(&temp,sizeof(temp),1,fp);
			while(!feof(fp)){ //�����ݿ��е�ѧ����Ϣ����st 
				if(strcmp(input,temp.ID)!=0&&strcmp(input,temp.name)!=0){//�ж�ѧ���Ƿ���� 
					st[i]=temp;
					i++;
				}else{
					k++;
					--temp.cor[0].member[0];
					--temp.cor[1].member[0];
					if((dp=fopen("statistic_c.dat","rb+"))==NULL){//�޸Ŀγ���ѡ������ 
						printf("Can not open the file!Please check your disk!\n\a");
					}else{
						fread(p,sizeof(tmp[0]),1,dp);
						while(!feof(dp)){ //�����ݿ��еĿγ���Ϣ����tmp 
							count++;
							p++;
							fread(p,sizeof(tmp[0]),1,dp);
						}
						fseek(dp,0L,0);
						for(l=0;l<count;l++){//����������Ӱ��Ŀγ̲������޸����е�ѡ������ 
							if(temp.cor[0].ID==tmp[l].ID){
								fwrite(&temp.cor[0],sizeof(tmp[0]),1,dp);
							}
							else if(temp.cor[1].ID==tmp[l].ID){
								fwrite(&temp.cor[1],sizeof(tmp[0]),1,dp);
							}else{
								fwrite(&tmp[l],sizeof(tmp[0]),1,dp);
							}
						}
						fclose(dp);
		   	    	}	
				}
				fread(&temp,sizeof(temp),1,fp);
			} 
			fclose(fp);
			if(k==0){
				printf("Student not found!\n");
				goto loop;
			}else{
				if((fp=fopen("statistic_s.dat","wb"))==NULL){
					printf("Can not open the file!Please check your disk!\n\a");
				}else{
					for(;j<i;j++){//����д��ɾ�����ѧ����Ϣ 
						fwrite(&st[j],sizeof(st[j]),1,fp);
					}
				fclose(fp);
		   	    }	
			}	
	}
	return 1;
}

int delCrsInf(){//ɾ���γ���Ϣ 
	FILE *fp;
	FILE *dp;
	int i,j,k,count=0,l;
	course crs[NUM];
	course temp,temp_2;
	student tmp[NUM],*p=tmp;
	char input[20],charge;
	loop:
	i=0;
	j=0;
	k=0;
	if((fp=fopen("statistic_c.dat","rb+"))==NULL){//��ȡ��д���������ʽ�ļ� ���γ̣� 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
			printf("Please input ID or name of the course you want to delete: ");
			scanf("%s",input);
			scanf:
			printf("Are you sure to delete course %s ?(Y/N): ",input);//ȷ��ɾ������ 
				getchar();
				scanf("%c",&charge);
				switch(charge){
					case 'n':
					case 'N':return 0;
					case 'y':
					case 'Y':break;
					default: printf("Error of input!\n");
							 goto scanf;
				}
			fread(&temp,sizeof(temp),1,fp);
			while(!feof(fp)){ //�����ݿ��еĿγ���Ϣ���� crs 
				if(atoi(input)!=temp.ID&&strcmp(input,temp.name)!=0){//����ɾ��ѧ����Ϣ���ж�Ҫɾ���Ŀγ��Ƿ���� 
					crs[i]=temp;     //�Ѳ���Ҫɾ���Ŀγ���Ϣ����crs[] 
					i++;
				}else{
					k++;  //����ҵ���Ҫɾ���Ŀγ��� k++   Ҫɾ���Ŀγ̾Ͳ���д��crs[]���� 
					temp_2=temp;  //temp_2��ΪҪɾ���Ŀγ� 
					
				}
				fread(&temp,sizeof(temp),1,fp);  //����һ���γ���Ϣ������ִ���ҵĹ��� 
			} 
			fclose(fp);
			if(k==0){
				printf("Course not found!\n");
				goto loop;
			}else{
				if((fp=fopen("statistic_c.dat","wb"))==NULL){//д���������ʽ�ļ� ���γ̣� 
					printf("Can not open the file!Please check your disk!\n\a");
				}else{
					for(;j<i;j++){ //��crs[]�γ���Ϣ����д���ļ� 
						fwrite(&crs[j],sizeof(crs[j]),1,fp);  //������Ҫɾ���γ̵�crs[]д���ļ����Ӷ�ɾ���˿γ� 
					}
				fclose(fp);
		   	    }	
		   	    if((dp=fopen("statistic_s.dat","rb+"))==NULL){//ɾ��ѧ����Ϣ�еĸÿγ� 
						printf("Can not open the file!Please check your disk!\n\a");
				}else{
					fread(p,sizeof(tmp[0]),1,dp);
					while(!feof(dp)){ 
						count++;
						p++;
						fread(p,sizeof(tmp[0]),1,dp);
					}
					fseek(dp,0L,0);
					for(l=0;l<count;l++){//���жԱ��ҵ���Ӱ���ѧ�����޸���ѡ����Ϣ 
						if(temp_2.ID==tmp[l].cor[0].ID){
							tmp[l].cor[0].ID=0;
							tmp[l].cor[0].tuition=0;
							tmp[l].fee-=temp_2.tuition;
							strcpy(tmp[l].cor[0].name,"");	
						}
						if(temp_2.ID==tmp[l].cor[1].ID){
							tmp[l].cor[1].ID=0;
							tmp[l].cor[0].tuition=0;
							tmp[l].fee-=temp_2.tuition;
							strcpy(tmp[l].cor[1].name,"");	
						}
						fwrite(&tmp[l],sizeof(tmp[0]),1,dp);
					}
				    fclose(dp);
		   	    }	
		    }	
	}
	return 1;
}

int rnkCourse(){//���ݿγ̺ſγ����� 
	FILE *fp;
	int i=0,j=0,k,l=0,count=1;
	course crs[NUM];
	course temp,tmp;
	int tmp_course[NUM];
	if((fp=fopen("statistic_c.dat","rb+"))==NULL){//��ȡ��д���������ʽ���ļ����γ̣� 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
			fread(&temp,sizeof(temp),1,fp);
			while(!feof(fp)){ //�����ݿ��еĿγ���Ϣ��ֵ��crs 
				crs[i]=temp;
				tmp_course[i]=temp.ID;
				i++;
				fread(&temp,sizeof(temp),1,fp);
			} 
			fseek(fp,0L,0);
			for(;j<i;j++){
				for(k=1;k<i;k++){
					if(crs[k].ID<crs[k-1].ID){
						tmp=crs[k-1];
						crs[k-1]=crs[k];
						crs[k]=tmp;
					}
				}
			}
			for(j=0;j<i;j++){
				fwrite(&crs[j],sizeof(crs[0]),1,fp);
			}
			fclose(fp);
	}
	return 1;
}

int cngStdCrs(char num[10]){//�޸�ѧ��ѡ����Ϣ 
	FILE *fp,*dp;
	int i,rank,count=0,j,cnt=0,k,l,m;
	char lesson[25];
	student temp[NUM],reput,st[NUM];
	student *p=temp;
	course tmp[NUM],*b=tmp;
	if((dp=fopen("statistic_c.dat","rb"))==NULL){//��ȡ��������ʽ���ļ� 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(b,sizeof(tmp[0]),1,dp);
		while(!feof(dp)){//�����ݿ��еĿγ���Ϣ����tmp 
			cnt++;
			b++;
			fread(b,sizeof(tmp[0]),1,dp);
		}
		fclose(dp);
		}
	
		if((fp=fopen("statistic_s.dat","rb+"))==NULL){//д�롢��ȡ��������ʽ���ļ���ѧ���� 
			printf("Can not open the file!Please check your disk!\n\a");
		}else{
			fread(p,sizeof(temp[0]),1,fp);
			while(!feof(fp)){//�����ݿ��е�ѧ����Ϣ����temp 
				count++;
				p++;
				fread(p,sizeof(temp[0]),1,fp);
			}
			for(i=0;i<count;i++){//���жԱ��ҵ��豨����ѧ�� 
				if(strcmp(num,temp[i].ID)==0){
					reput=temp[i];
					for(m=0;m<cnt;m++){//���жԱ��ҵ���Ӱ��Ŀγ̲�������ѡ������ 
						if(reput.cor[0].ID==tmp[m].ID){
							--tmp[m].member[0];
						}
						if(reput.cor[1].ID==tmp[m].ID){
							--tmp[m].member[0];
						}
					}
					first:
						printf("The first course you choose:");
						scanf("%s",lesson);
						for(k=0;k<cnt;k++){
							if(strcmp(lesson,tmp[k].category)==0){//�ж��Ƿ��ǿγ����ͣ��ǵĻ���ʾ�������¿�ѡ�γ� 
								printf("You can choose the following courses under this category:\n");
								for(l=0;l<cnt;l++){
									if(strcmp(tmp[l].category,lesson)==0){
										printf("%d   %s\n",tmp[l].ID,tmp[l].name);
									}
								}
								goto first;
							}
							if(atoi(lesson)==tmp[k].ID||strcmp(lesson,tmp[k].name)==0){  //���������ǿγ̺Ż����ǿγ��� 
								if(tmp[k].member[0]<tmp[k].member[1]){//�жϿγ��Ƿ���Ա 
									++tmp[k].member[0];
									reput.cor[0]=tmp[k];
									goto second;
								}else{
									printf("The course is full!\n");
									goto first;
								}
							}
						}
						printf("Course not found!\n");
						goto first;
					second:
						printf("The second course you choose:");
						scanf("%s",lesson);
						for(k=0;k<cnt;k++){
							if(strcmp(lesson,tmp[k].category)==0){//�ж��Ƿ��ǿγ����ͣ��ǵĻ���ʾ�������¿�ѡ�γ� 
								printf("You can choose the following courses under this category:\n");
								for(l=0;l<cnt;l++){
									if(strcmp(tmp[l].category,lesson)==0){
										printf("%d   %s\n",tmp[l].ID,tmp[l].name);
									}
								}
								goto second;
							}
							if(atoi(lesson)==tmp[k].ID||strcmp(lesson,tmp[k].name)==0){//��ֹ�����ַ������ҳ���ִ�� �жϿγ��Ƿ���� 
								if(tmp[k].ID==reput.cor[0].ID){//�жϿγ�2�Ϳγ�1�Ƿ��ظ� 
									printf("Please choose different courses!\n");
									goto second;
								}
								if(tmp[k].member[0]<tmp[k].member[1]){//�жϿγ�ʱ���Ƿ��ͻ 
									if(((tmp[k].time[0]>reput.cor[0].time[2])||((tmp[k].time[0]==reput.cor[0].time[2])&&(tmp[k].time[1]>=reput.cor[0].time[3])))||((tmp[k].time[2]<reput.cor[0].time[0])||((tmp[k].time[2]==reput.cor[0].time[0])&&(tmp[k].time[3]<=reput.cor[0].time[1])))){
										//�жϿγ̳�ͻ���ж���� 
										++tmp[k].member[0];
										reput.cor[1]=tmp[k];
										goto continious;
									}else{
										printf("Class time conflict!\n");
										goto second;
									}
								}else{
									printf("The course is full!\n");
									goto second;
								}
							}
						}
						printf("Course not found!\n");
						goto second;
					continious:
					reput.fee=reput.cor[0].tuition+reput.cor[1].tuition;
					fseek(fp,0L,0);
					for(j=0;j<i+1;j++){//����д��ѧ����Ϣ 
						if(j!=i){
							fwrite(&temp[j],sizeof(temp[0]),1,fp);
						}else{
							fwrite(&reput,sizeof(reput),1,fp);
						}
					}	
					fclose(fp);
					if((dp=fopen("statistic_c.dat","wb"))==NULL){//д���������ʽ���ļ����γ̣� 
						printf("Can not open the file!Please check your disk!\n\a");
					}else{
						for(j=0;j<cnt;j++){//����д��γ���Ϣ 
							fwrite(&tmp[j],sizeof(tmp[0]),1,dp);
						}
						fclose(dp);	
					}
					return 1;	
				}	
			}
			return 0;
		}
}

void showCrsInf(char num[10]){
	FILE *fp;
	int i;
	student st;
	printf("%-9s%-25s%-15s%-12s%-9s%-7s\n","�γ̺�","�γ�����","�Ͽ�ʱ��","��������","ѧ��","�γ̷���");
	printf("-------------------------------------------------------------------------------\n");
	if((fp=fopen("statistic_s.dat","rb"))==NULL){//��ȡ��������ʽ���ļ���ѧ���� 
		printf("Can not open the file!Please check your disk!\n\a");
	}else{
		fread(&st,sizeof(st),1,fp);
		while(!feof(fp)){//���жԱȲ�����Ӧ��ѧ�����������Ϣ 
			if(strcmp(st.ID,num)==0){
				for(i=0;i<2;i++){
					if(st.cor[i].ID!=0){
						printf("%-9d%-25s%",st.cor[i].ID,st.cor[i].name);
						if(st.cor[i].time[1]<10){//���ʱ���ʽ 
							printf("%2d:0%d-",st.cor[i].time[0],st.cor[i].time[1]);
						}
						if(st.cor[i].time[1]>=10){
							printf("%2d:%d-",st.cor[i].time[0],st.cor[i].time[1]);
						}
						if(st.cor[i].time[3]<10){
							printf("%2d:0%-5d",st.cor[i].time[2],st.cor[i].time[3]);
						}
						if(st.cor[i].time[3]>=10){
							printf("%2d:%-6d",st.cor[i].time[2],st.cor[i].time[3]);
						}
						printf("%2d/%-9d%-9.1f%-7s\n",st.cor[i].member[0],st.cor[i].member[1],st.cor[i].tuition,st.cor[i].category);
					}	
				}
				break;	
			}
			fread(&st,sizeof(st),1,fp);	
		}
	}
	fclose(fp);
}

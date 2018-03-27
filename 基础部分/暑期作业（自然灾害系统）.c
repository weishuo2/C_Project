#include"stdio.h"
#include"stdlib.h"
#include"string.h"
typedef struct kind_tab{
	char name[15];//灾害名称
	char kind;//类别编号
	struct kind_tab *next;
} kinds;
typedef struct donation_tab{//捐款信息
	char num[12];//事件编号
	char time[15];//时间
	char kind;//捐款类别
	char name[20];//捐款者名称
	float amount;//捐款数目
	struct donation_tab *next;
}  donas;
typedef struct basic_tab{  //基本信息
	char num[12];//编号
	char time[15];//时间
	char name[15]; //灾害名称
	char level;//级别
	char place[20];//地点
	int death;//死亡人数
	int building;//倒塌民房
	float money;//经济损失
	donas *head_amount;
	struct basic_tab  *next;
}  basics;
typedef struct sum_tab{ //各类之和
	char name[15];//灾害名称
	int cishu;//次数
	int death;//死亡数
	int building;//建筑物
	float money; //损失
}  sums;
typedef struct donation_sum{
	char name[15];
	float geren;
	float jigou;
}	donasum;

void creat_kindlist(kinds **head1); //创建灾害分类信息
void save_kindlist(kinds *head1);//保存分类信息到文件
void cordet_kindlist(kinds **head1);//修改和删除分类信息
void load_kindlist(kinds **head1);//将保存在文件中的分类信息读入链表
void print_kindlist(kinds *head1);//输出保存的全部分类数据
void find_kindlist(kinds *head1);//寻找有相同子串的灾害
void beifen_kindlist(kinds *head1);//将数据备份
void huifu_kindlist(kinds **head1);//将数据恢复
void add_kindlist(kinds **head1); //在尾部增加一个节点

void creat_basiclist(basics **head2);//创建灾害事件信息
void save_basiclist(basics *head2);//保存灾害信息到文件
void load_basiclist(basics **head2);//将保存在文件中的灾害信息读入链表
void print_basiclist(basics *head2);//输出所有的灾害信息
void cordet_basiclist(basics **head2);//修改删除灾害信息
void add_basiclist(basics **head2);//在尾部增加一个节点
void beifen_basiclist(basics *head2);//数据备份
void huifu_basiclist(basics **head2); //数据恢复
void find_basiclist(basics *head2);//在基本信息中寻找目标
void find_donationlist(basics *head2);//在捐款信息中寻找目标

void shuju1_basiclist(kinds *head1,basics *head2); //各类灾害的信息和
void shuju2_basiclist(kinds *head1,basics *head2); //各类较高级别的灾害的信息和
void shuju3_basiclist(basics *head2);//查询某一个灾害在某一年内各个数据的总和
void shuju4_basiclist(kinds *head1,basics *head2);//某一时间段个人和机构捐款总数
void shuju5_basiclist(basics *head2);//某人捐款总数

int main(void)
{
	char c[5];
	int l[5];
	kinds *head1=NULL;
	basics *head2=NULL;
	system("color 1F");//系统命令，调颜色
loop:
	printf("\t\t********************************************************************\n");
	printf("\t\t*==================================================================*\n");
	printf("\t\t*          ◆  ◆  ◆ 自 然 灾 害 管 理 系 统 ◆  ◆  ◆           *\n");
	printf("\t\t*==================================================================*\n");
	printf("\t\t*                                                                  *\n");
	printf("\t\t*                    1.自然灾害灾害类别的管理                      *\n");
	printf("\t\t*                    2.自然灾害信息及捐款信息管理                  *\n");
	printf("\t\t*                    3.数据整合整理及分析                          *\n");
	printf("\t\t*                    4.结束选项                                    *\n");
	printf("\t\t*                                                                  *\n");
	printf("\t\t********************************************************************\n\n");
	printf("\t\t                     请输入你的选择：");
	c[0]=getchar();getchar();
	system("cls");
	if(c[0] == '1')
	{
		l[1]=1;
		while(l[1]!=0)
		{
			l[1]=0;
			printf("\t\t********************************************************************\n");
			printf("\t\t*                                                                  *\n");
			printf("\t\t*                     ◆自然灾害灾害类别的管理 ◆                  *\n");
			printf("\t\t*                                                                  *\n");
			printf("\t\t*                      1.创建灾害类别信息（会删除已有）            *\n");
			printf("\t\t*                      2.输出灾害类别信息                          *\n");
			printf("\t\t*                      3.修改和删除灾害类别信息                    *\n");
			printf("\t\t*                      4.增加一个类别信息                          *\n");
			printf("\t\t*                      5.根据子串寻找信息                          *\n");
			printf("\t\t*                      6.数据备份                                  *\n");
			printf("\t\t*                      7.数据恢复                                  *\n");
			printf("\t\t*                      8.返回主系统                                *\n");
			printf("\t\t*                                                                  *\n");
			printf("\t\t********************************************************************\n\n");
			printf("\t\t                       请输入你的选择：");
			c[1]=getchar();getchar();
			switch(c[1])
			{
				case '1':
					creat_kindlist(&head1);
					save_kindlist(head1);
					break;
				case '2':
					load_kindlist(&head1);
					print_kindlist(head1);
					break;
				case '3':
					load_kindlist(&head1);
					cordet_kindlist(&head1);
					save_kindlist(head1);
					break;
				case '4':
					load_kindlist(&head1);
					add_kindlist(&head1);
					save_kindlist(head1);
					break;
				case '5':
					load_kindlist(&head1);
					find_kindlist(head1);
					break;
				case '6':
					load_kindlist(&head1);
					beifen_kindlist(head1);
					break;
				case '7':
					huifu_kindlist(&head1);
					save_kindlist(head1);
					break;
				case '8':
					system("cls");
					goto loop;
			}
			printf("\n\n\n\t\t\t\t按enter键继续。");
			if((c[1]=getchar()) !='\0' )
			{
				system("cls");
				l[1]=1;
			}
		}
	}
	else if(c[0] == '2')
	{
		l[2]=1;
		while(l[2]!=0)
		{
			l[2]=0;
			printf("\t\t********************************************************************\n");
			printf("\t\t*                                                                  *\n");
			printf("\t\t*                     ◆ 自然灾害信息及捐款信息管理 ◆             *\n");
			printf("\t\t*                                                                  *\n");
			printf("\t\t*                      1.创建灾害类别信息（会删除已有）            *\n");
			printf("\t\t*                      2.输出灾害事件信息                          *\n");
			printf("\t\t*                      3.修改和删除灾害事件信息                    *\n");
			printf("\t\t*                      4.增加一个灾害信息                          *\n");
			printf("\t\t*                      5.寻找灾害事件信息                          *\n");
			printf("\t\t*                      6.寻找捐款信息                              *\n");
			printf("\t\t*                      7.数据备份                                  *\n");
			printf("\t\t*                      8.数据恢复                                  *\n");
			printf("\t\t*                      9.返回主系统                                *\n");
			printf("\t\t*                                                                  *\n");
			printf("\t\t********************************************************************\n\n");
			printf("\t\t                       请输入你的选择：");
			c[2]=getchar();getchar();
			switch(c[2])
			{
				case '1':
					creat_basiclist(&head2);
					save_basiclist(head2);
					break;
				case '2':
					load_basiclist(&head2);
					print_basiclist(head2);
					break;
				case '3':
					load_basiclist(&head2);
					cordet_basiclist(&head2);
					save_basiclist(head2);
					break;
				case '4':
					load_basiclist(&head2);
					add_basiclist(&head2);
					save_basiclist(head2);
					break;
				case '5':
					load_basiclist(&head2);
					find_basiclist(head2);
					break;
				case '6':
					load_basiclist(&head2);
					find_donationlist(head2);
					break;
				case '7':
					load_basiclist(&head2);
					beifen_basiclist(head2);
					break;
				case '8':
					huifu_basiclist(&head2);
					save_basiclist(head2);
				case '9':
					system("cls");
					goto loop;
			}
			printf("\n\n\n\t\t\t\t按enter键继续。");
			if((c[2]=getchar()) !='\0' )
			{
				system("cls");
				l[2]=1;
			}
		}

	}
	else if(c[0] == '3')
	{
		l[3]=1;
		while(l[3]!=0)
		{
			l[3]=0;
			printf("\t\t********************************************************************\n");
			printf("\t\t*                                                                  *\n");
			printf("\t\t*                     ◆ 数据整合整理及分析 ◆                     *\n");
			printf("\t\t*                                                                  *\n");
			printf("\t\t*                    1.各类灾害各个信息之和                        *\n");
			printf("\t\t*                    2.各类1,2级别的灾害各个信息之和               *\n");
			printf("\t\t*                    3.查询某一种灾害在某一年各个数据之和          *\n");
			printf("\t\t*                    4.某一时间段个人和机构捐款数分别的和          *\n");
			printf("\t\t*                    5.查询某人捐款总数                            *\n");
			printf("\t\t*                    6.返回主系统                                  *\n");
			printf("\t\t*                                                                  *\n");
			printf("\t\t********************************************************************\n\n");
			printf("\t\t                      请输入你的选择：");
			c[3]=getchar();getchar();
			switch(c[3])
			{
				case '1':
					load_basiclist(&head2);
					load_kindlist(&head1);
					shuju1_basiclist(head1,head2);
					break;
				case '2':
					load_basiclist(&head2);
					load_kindlist(&head1);
					shuju2_basiclist(head1,head2);
					break;
				case '3':
					load_basiclist(&head2);
					load_kindlist(&head1);
					shuju3_basiclist(head2);
					break;
				case '4':
					load_basiclist(&head2);
					load_kindlist(&head1);
					shuju4_basiclist(head1,head2);
					break;
				case '5':
					load_basiclist(&head2);
					load_kindlist(&head1);
					shuju5_basiclist(head2);
					break;
				case '6':
					system("cls");
					goto loop;
			}
			printf("\n\n\n\t\t\t\t按enter键继续。");
			if((c[3]=getchar()) !='\0' )
			{
				system("cls");
				l[3]=1;
			}
		}
	}
	else if(c[0] == '4')
		return 0;
	printf("\t\t\t\t\tcoutinue chioce? y or n?\n");
	system("cls");
	goto loop;
	return 0;
}

void beifen_kindlist(kinds *head1)//将数据备份
{
	FILE *out1;
  	kinds *p=head1;
	if((out1 = fopen("C:\\informationsorting2.txt","wb")) == NULL)
		exit(-1);
	while(p != NULL)
	{
		fwrite(p,sizeof(kinds),1,out1);
		p=p->next;
	}
	fclose(out1);
}

void huifu_kindlist(kinds **head1) //数据恢复
{
	FILE *in1;
  	kinds *hp=NULL,*p;
  	char ch;
  	printf("\t\t\t\t会覆盖掉原有数据，是否继续？Y or N\n");
  	ch=getchar();
  	getchar();
  	if(ch=='N' || ch=='n')
  		return ;
  	if((in1 = fopen("C:\\informationsorting2.txt","rb")) == NULL)
  		exit(-1);
  	while(!feof(in1)){
  		p=(kinds *)malloc(sizeof(kinds));
  		fread(p,sizeof(kinds),1,in1);
  		if(!feof(in1)){
  			p->next=hp;
  			hp=p;
		  }
	  }
	  (*head1)=hp;
	  fclose(in1);
}

void creat_kindlist(kinds **head1)
{
	kinds *hp=NULL,*p;
	char ch;
 	loop:
 		p=(kinds *)malloc(sizeof(kinds));
 		printf("\t\t\t\tInput natural disasters' num and name\n");
 		printf("\t\t\t\t\tEnter the number:");
 		scanf("%c",&p->kind);getchar();
 		printf("\t\t\t\t\tEnter the name:");
 		scanf("%s",p->name);getchar();
 		p->next=hp;
 		hp=p;//后进来的放在前面
 		printf("\t\t\t\t   Continue input? y or n\n");
 		printf("\t\t\t\t\tPlease enter your choice:");
		ch=getchar();getchar();
		if(ch=='y' || ch=='Y')
			goto loop;//再来一次
		(*head1)=hp;
}

void save_kindlist(kinds *head1)
{
    FILE *out1;
  	kinds *p=head1;
	if((out1 = fopen("C:\\informationsorting.txt","wb")) == NULL)
		exit(-1);
	while(p != NULL)
	{
		fwrite(p,sizeof(kinds),1,out1);
		p=p->next;
	}
	fclose(out1);
}

void cordet_kindlist(kinds **head1)
{
    char ch;
    kinds *p;
    p=*head1;
    printf("\t\t\t\t1:look up by number\n");
    printf("\t\t\t\t2:look up by name\n");
    printf("\t\t\t\tPlease enter your choice:");
    ch=getchar();getchar();
    switch(ch)
    {
		case '1':
            printf("\t\t\t\tPlease input the number\n");
            printf("\t\t\t\t  Enter the number:");
            int num;
            scanf("%d",&num);
            num=num+'0';
            for(;p->next!=NULL&&num!=p->kind;p=p->next)
            ;
            if(num==p->kind)
              printf("\t\t\t\tfind %-7c %-7s\n",p->kind,p->name);
            else if(p->next==NULL)
            {
                printf("\t\t\t\t\tNOT FOUND\n");
                getchar();
                return ;
            }
            break;
        case '2':
            printf("\t\t\t\tPlease input the name\n");
            char t[10];
            printf("\t\t\t\tEnter the name:");
            scanf("%s",t);
            for(;p->next!=NULL&&strcmp(p->name,t);p=p->next)
              ;
            if(!strcmp(p->name,t))
              printf("\t\t\t\tfind %-7c %-7s\n",p->kind,p->name);
            else if(p->next==NULL)
            {
               printf("\t\t\t\t\tNOT FOUND\n");
               getchar();
               return ;
            }
            break;

    }
	getchar();
    printf("\t\t\t\t1.Change\n\t\t\t\t2.delete\n\t\t\t\t3.nothing\n");
    printf("\t\t\t\tPlease enter your choice:");
    ch=getchar();getchar();
    if(ch == '1')
	{
		printf("\t\t\t\tWhich one to change?\n");
    	printf("\t\t\t\t   1:number\n");
    	printf("\t\t\t\t   2:name\n");
    	printf("\t\t\t\t   3:I don't want to change anything\n");
    	printf("\t\t\t\t   Please enter your choice:");
    	ch=getchar();
    	getchar();
    	switch(ch)
    	{
        	case '1':
        		printf("\t\t\t\tPlease reinput number or name\n");
        		printf("\t\t\t\t    Enter the number:");
          	 	scanf("%d",&p->kind);
           		break;
        	case '2':
        		printf("\t\t\t\tPlease reinput number or name\n");
        		printf("\t\t\t\t    Enter the name:");
           		scanf("%s",p->name);
           		break;
        	default :
            	return ;
    	}
    	getchar();
	}
	else if(ch == '2')
	{
		printf("\t\t\t\tDestroy %-7c |%-7s?y or n.\n",p->kind,p->name);
		printf("\t\t\t\t   Please enter your choice:");
		ch=getchar();getchar();
		if(ch == 'y' || ch == 'Y')
		{
			if(p==*head1)
			*head1=p->next;
			else
			p=p->next;
			free(p);
		}
	}
	else
		return;
}

 void load_kindlist(kinds **head1)
  {
  	FILE *in1;
  	kinds *hp=NULL,*p;
  	if((in1 = fopen("C:\\informationsorting.txt","rb")) == NULL)
  	{
  		printf("\t\t\t\t\t打开文件失败！\n");
  		exit(-1);
	  }
  	while(!feof(in1)){
  		p=(kinds *)malloc(sizeof(kinds));
  		fread(p,sizeof(kinds),1,in1);
  		if(!feof(in1)){
  			p->next=hp;
  			hp=p;
		  }
	  }
	  (*head1)=hp;
	  fclose(in1);
  }

  void print_kindlist(kinds *head1)
  {
  	kinds *p=head1;
  	printf("\t\t\t\t\t_________________\n");
  	printf("\t\t\t\t\t编号    |名称\n");
  	while(p !=NULL)
	{
  		printf("\t\t\t\t\t%-7c |%-7s\n",p->kind,p->name);
		  p=p->next;
	}
  }

  void find_kindlist(kinds *head1)
  {
  	char a[80];
  	int j,k,n;
  	kinds *p;
  	p=head1;
  	printf("\t\tPlease enter a part of what you want to find.\n");
  	printf("\t\t\t\t    The part:");
	scanf("%s",a);getchar();
	while(p != NULL)
	{
		for(j=0,n=1;(p->name)[j]!='\0';j++)
		{
			if((p->name)[j] == a[0])
			{
				k=1;
				while((p->name)[j+k]==a[k] && a[k]!='\0')
					k++;
				if(a[k] == '\0' && n==1)
				{
					printf("\t\t\t\t\t%-7c |%-7s\n",p->kind,p->name);
					n++;
				}
			}

		}
		p=p->next;
	}
}

void add_kindlist(kinds **head1)
{
	kinds *p = *head1;
    while((p->next) != NULL)
        p = p->next;

    p->next = (kinds *)malloc(sizeof(kinds));
    p = p->next;
    printf("\t\tPlease enter the number and the name that you want to add.\n");
    printf("\t\t\t\t\tEnter the kind:");
    scanf("%c",&p->kind);getchar();
    printf("\t\t\t\t\tEnter the name:");
    scanf("%s",&p->name);getchar();
    p->next = NULL;
}


 void creat_basiclist(basics **head2)
 {
 	basics *hp=NULL,*p;
 	donas *pcrs;
 	char s[80]="",ch;
	loop:
 		p=(basics *)malloc(sizeof(basics));
 		printf("\t  Please input the accident's number,time,name,level,place,death,building,money.\n");
 		printf("\t\t\t\t\tEnter the number:");
 		scanf("%s",p->num);getchar();
 		printf("\t\t\t\t\tEnter the time:");
 		scanf("%s",p->time);getchar();
 		printf("\t\t\t\t\tEnter the name:");
 		scanf("%s",p->name);getchar();
 		printf("\t\t\t\t\tEnter the level:");
 		scanf("%c",&p->level);getchar();
 		printf("\t\t\t\t\tEnter the place:");
 		scanf("%s",p->place);getchar();
 		printf("\t\t\t\t\tEnter the death:");
 		scanf("%d",&p->death);getchar();
 		printf("\t\t\t\t\tEnter the building:");
 		scanf("%d",&p->building);getchar();
 		printf("\t\t\t\t\tEnter the money:");
 		scanf("%f",&p->money);getchar();
 		p->head_amount=NULL;
 		p->next=hp;
 		hp=p;//后进来的放在前面
 		printf("\t\t\t\t  continue input data of accident? y or n.\n");
 		printf("\t\t\t\t\tPlease enter your choice:");
		ch=getchar();getchar();
		if(ch=='y' || ch=='Y')
			goto loop;//再来一次
	(*head2)=hp;
	p=(*head2);
	while(p != NULL)
	{//创建捐款链
		printf("\t      Input the donation informations of accident %s?y or n.\n",p->num);
		printf("\t\t\t\t\tPlease enter your choice:");
		ch=getchar();getchar();
		while(ch == 'y' || ch == 'Y')
		{
			pcrs = (donas *)malloc(sizeof(donas));
			printf("\t\t\t\tPlease input time,kind,name,amount.\n");
			printf("\t\t\t\t\tEnter the time:");
 			scanf("%s",pcrs->time);getchar();
 			printf("\t\t\t\t\tEnter the kind:");
 			scanf("%c",&pcrs->kind);getchar();
 			printf("\t\t\t\t\tEnter the name:");
 			scanf("%s",pcrs->name);getchar();
 			printf("\t\t\t\t\tEnter the amount:");
 			scanf("%f",&pcrs->amount);getchar();
			strcpy(pcrs->num,p->num);
			pcrs->next=p->head_amount;
			p->head_amount=pcrs;
			printf("\t   Input the other donation informations of accident %s?y or n.\n",p->num);
			printf("\t\t\t\t\tPlease enter your choice:");
			ch=getchar();getchar();
		}
		p=p->next;
	}
	return ;
  }

void save_basiclist(basics *head2)
{
	FILE *basicFile, *donaFile;
	basics *basicNode = head2;
	donas *pcrs;
	//打开文件
	if((basicFile = fopen("C:\\basicinformation.txt", "w")) == NULL)
		exit(-1);
	if((donaFile = fopen("C:\\donationinformation.txt", "w")) == NULL)
		exit(-1);

	while(basicNode != NULL)
	{
		fprintf(basicFile, "%s ", basicNode->num);
		fprintf(basicFile, "%s ", basicNode->time);
		fprintf(basicFile, "%s ", basicNode->name);
		fprintf(basicFile, "%c ", basicNode->level);
		fprintf(basicFile, "%s ", basicNode->place);
		fprintf(basicFile, "%d ", basicNode->death);
		fprintf(basicFile, "%d ", basicNode->building);
		fprintf(basicFile, "%f\n", basicNode->money);
		pcrs = basicNode->head_amount;
		while(pcrs != NULL)
		{
			fprintf(donaFile, "%s ", pcrs->num);
			fprintf(donaFile, "%s ", pcrs->time);
			fprintf(donaFile, "%c ", pcrs->kind);
			fprintf(donaFile, "%s ", pcrs->name);
			fprintf(donaFile, "%f\n", pcrs->amount);
			pcrs = pcrs->next;
		}
		basicNode = basicNode->next;
	}

	fclose(basicFile);
	fclose(donaFile);
}

void load_basiclist(basics **head2)
{
	FILE *basicFile, *donaFile;
	basics *hp=NULL,*p;
  	donas *pcrs;

	if((basicFile = fopen("C:\\basicinformation.txt", "r")) == NULL)
		exit(-1);
	if((donaFile = fopen("C:\\donationinformation.txt", "r")) == NULL)
		exit(-1);

	while(! feof(basicFile) )
	{
		p=(basics *)malloc(sizeof(basics));
		fscanf(basicFile, "%s ", p->num);
		fscanf(basicFile, "%s ", p->time);
		fscanf(basicFile, "%s ", p->name);
		fscanf(basicFile, "%c ", &p->level);
		fscanf(basicFile, "%s ", p->place);
		fscanf(basicFile, "%d ", &p->death);
		fscanf(basicFile, "%d ", &p->building);
		fscanf(basicFile, "%f\n", &p->money);
		p->head_amount=NULL;
  		p->next=hp;
  		hp=p;
	}
	//头结点
	(*head2) = hp;
	while(! feof(donaFile))
	{
		pcrs = (donas *)malloc(sizeof(donas));
		fscanf(donaFile, "%s ", pcrs->num);
		fscanf(donaFile, "%s ", pcrs->time);
		fscanf(donaFile, "%c ", &pcrs->kind);
		fscanf(donaFile, "%s ", pcrs->name);
		fscanf(donaFile, "%f\n", &pcrs->amount);
		p = (*head2);
		while(p != NULL)
		{
			if(!strcmp(p->num, pcrs->num))
			{
				pcrs->next = p->head_amount;
				p->head_amount = pcrs;
				break;
			}
			else
				p = p->next;
		}
	}
	fclose(basicFile);
	fclose(donaFile);
}

void print_basiclist(basics *head2)
{
	basics *p=head2;
  	donas *pcrs;
  	printf("   编号          时间          名字       级数                地点              死亡数   建筑    损失（亿）\n");
  	while(p !=NULL)
	{
  		printf("%-13s%-16s%-15s%-3c              %-15s%8d%8d %8.2f\n",p->num,p->time,p->name,p->level,p->place,p->death,p->building,p->money);
  		pcrs = p->head_amount;
  		printf("                 时间          名字       类别              总数（万）\n");
  		while(pcrs != NULL)
		{
  			printf("%-13s%-16s%-15s%-3c              %-8.2f\n",pcrs->num,pcrs->time,pcrs->name,pcrs->kind,pcrs->amount);
  			pcrs=pcrs->next;
		}
		p=p->next;
		printf("\n");
		if(p!=NULL)
			printf("   编号          时间          名字       级数                地点              死亡数   建筑    损失（亿）\n");
	}
}

void cordet_basiclist(basics **head2)
{
	char ch,t[20];
    basics *p;
    donas *pcrs;
    p=*head2;
    pcrs=p->head_amount;
    printf("\t\t\t\tWhat do you want to change or detele?\n\t\t\t\t\t1.basicinformation\n\t\t\t\t\t2.donationinformation\n");
    printf("\t\t\t\t\tPlease enter your choice:");
    ch=getchar();getchar();
    if(ch == '1')
	{
		printf("\t\t\t\tPlease enter the number of the thing that you want to change or delete.\n");
		printf("\t\t\t\tPlease enter the number:");
    	scanf("%s",t);
    	getchar();
    	for(;p->next!=NULL&&strcmp(p->num,t);p=p->next)
        	;
    	if(!strcmp(p->num,t))
    		printf("\t\t\tfind %s %s %s %c %s %d %d %f\n",p->num,p->time,p->name,p->level,p->place,p->death,p->building,p->money);
    	else if(p->next==NULL)
		{
			printf("\t\t\t\tNOT FOUND.\n");
			return ;
		}
		printf("\t\t\t\tchange push 1\n\t\t\t\tdelete push 2.\n");
		printf("\t\t\t\tPlease enter your choice:");
    	ch=getchar();
    	getchar();
    	if(ch == '1')
		{
			printf("\t\t\t\twhich one to change?\n");
    		printf("\t\t\t\t1:number\n");
    		printf("\t\t\t\t2:time\n");
    		printf("\t\t\t\t3:name\n");
    		printf("\t\t\t\t4:level\n");
    		printf("\t\t\t\t5:place\n");
    		printf("\t\t\t\t6:death\n");
    		printf("\t\t\t\t7:building\n");
    		printf("\t\t\t\t8:money\n");
    		printf("\t\t\t\t9:I don't want to change anything.\n");
    		printf("\t\t\t\tPlease enter your choice:");
    		ch=getchar();getchar();
    		if(ch !='9')
    		{
    			printf("\t\t\t\tplease reinput\n");
    			printf("\t\t\t\tenter you want:");
			}
    		switch(ch)
   			{
        		case '1':
           			scanf("%s",p->num);
           			break;
        		case '2':
           			scanf("%s",p->time);
           			break;
        		case '3':
           			scanf("%s",p->name);
          	 		break;
        		case '4':
           			scanf("%c",&p->level);
          	 		break;
        		case '5':
           			scanf("%s",p->place);
           			break;
        		case '6':
           			scanf("%d",&p->death);
           			break;
       		 	case '7':
        			scanf("%d",&p->building);
        			break;
        		case '8':
        			scanf("%f",&p->money);
        			break;
        		default :
            		return ;
    		}
    		getchar();
		}
		else if(ch == '2')
		{
			printf("\t\t\tDetele %s %s %s %c %s %d %d %f? y or n.\n",p->num,p->time,p->name,p->level,p->place,p->death,p->building,p->money);
			printf("\t\t\t\tPlease enter your choice:");
			ch=getchar();getchar();
			if(ch == 'y' || ch == 'Y')
			{
				if(p==*head2)
					*head2=p->next;
				else
					p=p->next;
				free(p);
			}
		}
	}
   else if(ch == '2')
   {
   		printf("\t\t\t\tPlease enter the time of the thing that you want to change or delete.\n");
   		printf("\t\t\t\tPlease enter the time:");
    	scanf("%s",t);
    	getchar();
    	while(p != NULL)
		{
			pcrs=p->head_amount;
    		for(;pcrs->next!=NULL&&strcmp(pcrs->time,t);pcrs=pcrs->next)
        		;
    		if(!strcmp(pcrs->time,t))
    		{
				printf("\t\t\t\tfind %s %s %c %s %f\n",pcrs->num,pcrs->time,pcrs->kind,pcrs->name,pcrs->amount);
				break;
			}
    		else if(pcrs->next==NULL)
				p=p->next;
		}
		if(strcmp(pcrs->time,t))
		{
			printf("\t\t\t\tNOT FOUND!\n");
			return ;
		}
		printf("\t\t\t\tchange push 1\n\t\t\t\tdelete push 2.\n");
		printf("\t\t\t\tPlease enter your choice:");
    	ch=getchar();getchar();
    	if(ch == '1')
		{
			printf("\t\t\t\twhich one to change?\n");
    		printf("\t\t\t\t1:number\n");
    		printf("\t\t\t\t2:time\n");
    		printf("\t\t\t\t3:kind\n");
    		printf("\t\t\t\t4:name\n");
    		printf("\t\t\t\t5:amount\n");
    		printf("\t\t\t\t6:I don't want to change anything.\n");
    		printf("\t\t\t\tPlease enter your choice:");
    		ch=getchar();getchar();
    		if(ch!='6')
    		{
    			printf("\t\t\t\tplease reinput\n");
    			printf("\t\t\t\tenter you want:");
			}
    		switch(ch)
   			{
        		case '1':
           			scanf("%s",pcrs->num);
           			break;
        		case '2':
           			scanf("%s",pcrs->time);
           			break;
        		case '3':
           			scanf("%c",&pcrs->kind);
          	 		break;
        		case '4':
           			scanf("%s",pcrs->name);
          	 		break;
        		case '5':
           			scanf("%f",&pcrs->amount);
           			break;
        		default :
            		return ;
    		}
    		getchar();
		}
		else if(ch == '2')
		{
			printf("\t\t\t\tDetele %s %s %c %s %f ?",pcrs->num,pcrs->time,pcrs->kind,pcrs->name,pcrs->amount);
			printf("\t\t\t\tenter your choice:");
			ch=getchar();getchar();
			if(ch == 'y' || ch == 'Y')
			{
				if(pcrs==p->head_amount)
					p->head_amount=pcrs->next;
				else
					pcrs=pcrs->next;
				free(pcrs);
			}
		}
  	}
}

void add_basiclist(basics **head2)
{
	char ch,s[80];
	basics *p = *head2;
	donas *pcrs;
	printf("\t\t\t\t\tWhat do you want to add?\n\t\t\t\t\t1.basicinformation\n\t\t\t\t\t2.donationinformation\n");
	printf("\t\t\t\t\tPlease enter your choice:");
	ch=getchar();getchar();
	if(ch == '1')
	{
		while((p->next) != NULL)
        	p = p->next;
    	p->next = (basics *)malloc(sizeof(basics));
    	p = p->next;
   		printf("\t  Please input the accident's number,time,name,level,place,death,building,money.\n");
 		printf("\t\t\t\t\tEnter the number:");
 		scanf("%s",p->num);getchar();
 		printf("\t\t\t\t\tEnter the time:");
 		scanf("%s",p->time);getchar();
 		printf("\t\t\t\t\tEnter the name:");
 		scanf("%s",p->name);getchar();
 		printf("\t\t\t\t\tEnter the level:");
 		scanf("%c",&p->level);getchar();
 		printf("\t\t\t\t\tEnter the place:");
 		scanf("%s",p->place);getchar();
 		printf("\t\t\t\t\tEnter the death:");
 		scanf("%d",&p->death);getchar();
 		printf("\t\t\t\t\tEnter the building:");
 		scanf("%d",&p->building);getchar();
 		printf("\t\t\t\t\tEnter the money:");
 		scanf("%f",&p->money);getchar();
    	p->next = NULL;
    	p->head_amount=NULL;
    	printf("\t   Input the donation informations of accident %s?y or n.\n",p->num);
		printf("\t\t\t\t\tPlease enter your choice:");
		ch=getchar();getchar();
		while(ch == 'y' || ch == 'Y')
		{
			pcrs = (donas *)malloc(sizeof(donas));
			printf("\t\t\t\tPlease input time,kind,name,amount.\n");
			printf("\t\t\t\t\tEnter the time:");
 			scanf("%s",pcrs->time);getchar();
 			printf("\t\t\t\t\tEnter the kind:");
 			scanf("%c",&pcrs->kind);getchar();
 			printf("\t\t\t\t\tEnter the name:");
 			scanf("%s",pcrs->name);getchar();
 			printf("\t\t\t\t\tEnter the amount:");
 			scanf("%f",&pcrs->amount);getchar();
			strcpy(pcrs->num,p->num);
			pcrs->next=p->head_amount;
			p->head_amount=pcrs;
			printf("\t   Input the other donation informations of accident %s?y or n.\n",p->num);
			printf("\t\t\t\t\tPlease enter your choice:");
			ch=getchar();getchar();
		}
	}
	else if(ch == '2')
	{
		printf("\t\t\t\tPlease enter the accident's number.\n");
		printf("\t\t\t\t\tPlease enter the number:");
		scanf("%s",s);getchar();
		for(;p->next!=NULL&&strcmp(p->num,s);p=p->next)
        	;
    	if(!strcmp(p->num,s))
        	printf("\t\t\tfind %s %s %s %c %s %d %d %f\n",p->num,p->time,p->name,p->level,p->place,p->death,p->building,p->money);
    	else if(p->next==NULL)
		{
			printf("\t\t\t\tNOT FOUND.\n");
			return ;
		}
		pcrs=p->head_amount;
		while((pcrs->next) != NULL)
        	pcrs= pcrs->next;
    	pcrs->next = (donas *)malloc(sizeof(donas));
    	pcrs = pcrs->next;
   		printf("\t\t\t\tPlease input time,kind,name,amount.\n");
		printf("\t\t\t\t\tEnter the time:");
 		scanf("%s",pcrs->time);getchar();
 		printf("\t\t\t\t\tEnter the kind:");
 		scanf("%c",&pcrs->kind);getchar();
 		printf("\t\t\t\t\tEnter the name:");
 		scanf("%s",pcrs->name);getchar();
 		printf("\t\t\t\t\tEnter the amount:");
 		scanf("%f",&pcrs->amount);getchar();
		strcpy(pcrs->num,p->num);
    	pcrs->next = NULL;
	}
	return ;
}

void find_basiclist(basics *head2)
{
	char ch,t[20],start[20],end[20];
	basics *p=head2;
	printf("\t\t\t1.look for by number.\n\t\t\t2.look for by day and name.\n");
	printf("\t\t\tPlease enter your choice:");
	ch=getchar();getchar();
	if(ch == '1')
	{
		printf("\t\t\tPlease enter the number of the thing that you want to find.\n");
		printf("\t\t\tPlease enter the number:");
    	scanf("%s",t);getchar();
    	for(;p->next!=NULL&&strcmp(p->num,t);p=p->next)
       		;
   		if(!strcmp(p->num,t))
       		printf("\t\t\tfind %s %s %s %c %s %-5d %-5d %-7f亿\n",p->num,p->time,p->name,p->level,p->place,p->death,p->building,p->money);
    	else if(p->next==NULL)
		{
			printf("\t\t\t\tNOT FOUND.\n");
			return ;
		}
	}
	else if(ch == '2')
	{
		printf("\t\t\tPlease enter the start,the end day.\n");
		printf("\t\t\tPlease enter the start day:");
		scanf("%s",start);
		printf("注释：寻找不包括末尾日期（需要包括末尾日期应在其后加a）\n");
		printf("\t\t\tPlease enter the end day:");
		scanf("%s",end);
		printf("\t\t\tPlease enter the name that you want to find.\n");
		printf("\t\t\tPlease enter the name:");
		scanf("%s",t);
		getchar();
		while(p != NULL)
		{
			if((!strcmp(p->name,t)) && (strcmp(p->time,end)<0) && (strcmp(p->time,start)>0))
				printf("\t\t\tfind %s %s %s %c %s %-5d %-5d %-7f亿\n",p->num,p->time,p->name,p->level,p->place,p->death,p->building,p->money);
			p=p->next;
		}
		printf("\t\t\tThat is all.\n");
		return ;
	}
}

void beifen_basiclist(basics *head2)
{
	FILE *out1,*out2;
  	basics *p=head2;
	donas *pcrs;
	if((out1 = fopen("C:\\basicinformation2.txt","wb")) == NULL)//打开基本信息文件
		exit(-1);
	if((out2 = fopen("C:\\donationinformation2.txt","wb")) == NULL)//捐款信息
		exit(-1);
	while(p != NULL){
		fwrite(p,sizeof(basics),1,out1);//写基本信息记录
		pcrs=p->head_amount;
		while(pcrs != NULL){
			fwrite(pcrs,sizeof(donas),1,out2);
			pcrs =pcrs->next;
		}
		p=p->next;
	}
	fclose(out1);
	fclose(out2);
}

void huifu_basiclist(basics **head2)
{
	FILE *in1,*in2;
  	basics *hp=NULL,*p;
  	donas *pcrs;
  	char ch;
  	printf("会覆盖掉原有数据，是否继续？Y or N\n");
  	ch=getchar();
  	getchar();
  	if(ch=='N' || ch=='n')
  		return ;
  	if((in1 = fopen("C:\\basicinformation2.txt","rb")) == NULL)
  		exit(-1);
  	if((in2 = fopen("C:\\donationinformation2.txt","rb")) == NULL)
  		exit(-1);
  	while(!feof(in1)){
  		p=(basics *)malloc(sizeof(basics));
  		fread(p,sizeof(basics),1,in1);
  		if(!feof(in1)){
  			p->head_amount=NULL;
  			p->next=hp;
  			hp=p;
		  }
	  }
	  (*head2)=hp;
	  while(!feof(in2))
	  {
	  	pcrs=(donas *)malloc(sizeof(donas));
	  	fread(pcrs,sizeof(donas),1,in2);
	  	if(!feof(in2)){
	  		p=(*head2);
	  		while(p != NULL){
	  			if(!strcmp(p->num,pcrs->num)){
	  				pcrs->next=p->head_amount;
	  				p->head_amount=pcrs;
	  				break;
				  }
				else
					p=p->next;
			  }
		  }
	  }
	  fclose(in1);
	  fclose(in2);
}


void find_donationlist(basics *head2)
{
	char ch,t[20],na[20];
	int j,k,n;
	float start,end;
	basics *p=head2;
	donas *pcrs=NULL;
	printf("\t\t\t1.look for by number and a part of the name.\n\t\t\t2.look for by kind and amount.\n");
	printf("\t\t\tPlease enter your choice:");
	ch=getchar();getchar();
	if(ch == '1')
	{
		printf("\t\t\tPlease enter the number of the thing that you want to find.\n");
		printf("\t\t\tPlease enter the number:");
		scanf("%s",t);
		printf("\t\t\tPlease enter a part of the person's name that you want to find.\n");
   		printf("\t\t\tPlease enter the part:");
   		scanf("%s",na);
   		getchar();
    	for(;p->next!=NULL&&strcmp(p->num,t);p=p->next)
        	;
    	if(!strcmp(p->num,t))
   	 	{
    		pcrs=p->head_amount;
			while(pcrs != NULL)
			{
				for(j=0,n=1;(pcrs->name)[j]!='\0';j++)
				{
					if((pcrs->name)[j] == na[0])
					{
						k=1;
						while((pcrs->name)[j+k]==na[k] && na[k]!='\0')
							k++;
						if(na[k] == '\0' && n==1)
						{
							printf("\t\t\tfind %s %s %c %s %f万\n",pcrs->num,pcrs->time,pcrs->kind,pcrs->name,pcrs->amount);
							n++;
						}
					}
				}
				pcrs=pcrs->next;
			}
		}
    	else if(p->next==NULL)
		{
			printf("\t\t\t\tNOT FOUND.\n");
			return ;
		}
	}
	else if(ch == '2')
	{
		printf("\t\t\tPlease enter the kind that you want to find.\n");
		printf("\t\t\tPlease enter the kind:");
		ch=getchar();getchar();
		printf("\t\t\tPlease enter the start and the end amount.\n");
		printf("\t\t\tPlease enter the start day:");
		scanf("%f",&start);
		printf("\t\t\t\tPlease enter the end day:");
		scanf("%f",&end);
		getchar();
		while(p !=NULL)
		{
  			pcrs = p->head_amount;
  			while(pcrs != NULL)
  			{
  				if(((pcrs->kind) == ch) && (pcrs->amount > start) &&(pcrs->amount < end))
  					printf("\t\t\tfind %s %s %c %s %f万\n",pcrs->num,pcrs->time,pcrs->kind,pcrs->name,pcrs->amount);
  				pcrs=pcrs->next;
			}
			p=p->next;
		}
	}
}

void shuju1_basiclist(kinds *head1,basics *head2)
{
	sums *ws[7];
	sums *t;
	basics *p;
	kinds *pcrs=head1;
	int i,j;
	for(i=0;i<7;i++)
		ws[i]=(sums *)malloc(sizeof(sums));
	t=(sums *)malloc(sizeof(sums));
	for(i=0;i<7;i++)
	{
		ws[i]->cishu=0;
		ws[i]->death=0;
		ws[i]->building=0;
		ws[i]->money=0;
	}
	for(i=0;i<7;i++)
	{
		p=head2;
		strncpy(ws[i]->name,pcrs->name,sizeof(ws[i]->name)-1);
		(ws[i]->name)[sizeof(ws[i]->name)-1]='\0';
		while(p != NULL)
		{
			if(!strcmp(p->name,pcrs->name))
			{

				ws[i]->cishu+=1;
				ws[i]->death+=p->death;
				ws[i]->building+=p->building;
				ws[i]->money+=p->money;
			}
			p=p->next;
		}
		pcrs=pcrs->next;
	}
	for(i=0;i<7;i++)
		for(j=0;j<6-i;j++)
			if(ws[j]->cishu < ws[j+1]->cishu)
				*t=*ws[j],*ws[j]=*ws[j+1],*ws[j+1]=*t;
	for(i=0;i<7;i++)
		printf("%-15s\t%-3d(次数)\t%-7d(死亡)\t%-7d(建筑)\t%-9.2f(钱数)\n",ws[i]->name,ws[i]->cishu,ws[i]->death,ws[i]->building,ws[i]->money);
}

void shuju2_basiclist(kinds *head1,basics *head2)
{
 	sums *w[7];
	sums *t;
	basics *p;
	kinds *pcrs=head1;
	int i,j;
	for(i=0;i<7;i++)
		w[i]=(sums *)malloc(sizeof(sums));
	t=(sums *)malloc(sizeof(sums));
	for(i=0;i<7;i++)
	{
		w[i]->cishu=0;
		w[i]->death=0;
		w[i]->building=0;
		w[i]->money=0;
	}
	for(i=0;i<7;i++)
	{
		p=head2;
		strcpy(w[i]->name,pcrs->name);
		while(p != NULL)
		{
			if((!strcmp(p->name,pcrs->name)) && (((p->level)=='1') || (p->level=='2')))
			{

				w[i]->cishu+=1;
				w[i]->death+=p->death;
				w[i]->building+=p->building;
				w[i]->money+=p->money;
			}
			p=p->next;
		}
		pcrs=pcrs->next;
	}
	for(i=0;i<7;i++)
		for(j=0;j<6-i;j++)
			if(w[j]->cishu < w[j+1]->cishu)
				*t=*w[j],*w[j]=*w[j+1],*w[j+1]=*t;
	for(i=0;i<7;i++)
		printf("%-15s\t%-3d(次数)\t%-7d(死亡)\t%-7d(建筑)\t%-9.2f(钱数)\n",w[i]->name,w[i]->cishu,w[i]->death,w[i]->building,w[i]->money);
}

void shuju3_basiclist(basics *head2)
{
	char start[15],end[15];
	sums ba;
	int n;
	basics *p=head2;
	printf("\t\t\tPlease enter the name of the natural disasters.\n");
	printf("\t\t\tPlease enter the name:");
	scanf("%s",ba.name);
	printf("\t\t\tPlease enter the year that you want to find.\n");
	printf("\t\t\tPlease enter the year:");
	scanf("%d",&n);
	getchar();
	itoa(n,start,10);//转化成数
	itoa(n+1,end,10);
	ba.building=0;
	ba.cishu=0;
	ba.death=0;
	ba.money=0;
	while(p != NULL)
	{
		if(!strcmp(p->name,ba.name) && (strcmp(p->time,start)>0) && (strcmp(p->time,end)<0))
		{
			ba.building+=p->building;
			ba.cishu+=1;
			ba.death+=p->death;
			ba.money+=p->death;
		}
		p=p->next;
	}
	printf("\t\t\t%-15s\t%-3d(次数)\t%-7d(死亡)\t%-7d(建筑)\t%-9f(钱数)\n",ba.name,ba.cishu,ba.death,ba.building,ba.money);
}

void shuju4_basiclist(kinds *head1,basics *head2)
{
	donasum *ws[7];
	basics *p;
	kinds *pcrs=head1;
	donas *pcrs2;
	int i,j;
	float geren,jigou;
	char start[15],end[15];
	for(i=0;i<7;i++)
		ws[i]=(donasum *)malloc(sizeof(donasum));
	printf("\t\t\tPlease enter the start,the end day.\n");
	printf("\t\t\tPlease enter the start day:");
	scanf("%s",start);
	printf("\t\t\t注释：寻找不包括末尾日期（需要包括末尾日期应在其后加a）\n");
	printf("\t\t\tPlease enter the end day:");
	scanf("%s",end);
	getchar();
	for(i=0;i<7;i++)
	{
		ws[i]->geren=0;
		ws[i]->jigou=0;
	}
	for(i=0;i<7;i++)
	{
		p=head2;
		strcpy(ws[i]->name,pcrs->name);
		while(p != NULL)
		{
			if(!strcmp(p->name,pcrs->name) && (strcmp(p->time,end)<0) && (strcmp(p->time,start)>0))
			{
				pcrs2=p->head_amount;
				while(pcrs2 != NULL)
				{
					if(pcrs2->kind == '1')
						ws[i]->geren+=pcrs2->amount;
					if(pcrs2->kind == '2')
						ws[i]->jigou+=pcrs2->amount;
					pcrs2=pcrs2->next;
				}
			}
			p=p->next;
		}
		pcrs=pcrs->next;
	}
	for(i=0;i<7;i++)
		printf("\t\t\t%-15s\t%-8.2f(个人)\t%-8.2f(机构)\n",ws[i]->name,ws[i]->geren,ws[i]->jigou);
}

void shuju5_basiclist(basics *head2)
{
	char na[15];
	float s;
	basics *p=head2;
	donas *pcrs;
	printf("\t\t\tPlease enter the name.\n");
	printf("\t\t\tThe name:");
	scanf("%s",na);getchar();
	while(p != NULL)
	{
		pcrs=p->head_amount;
		while(pcrs != NULL)
		{
			if(!strcmp(pcrs->name,na))
				s+=pcrs->amount;
			pcrs=pcrs->next;
		}
		p=p->next;
	}
	printf("\t\t\t%s 共捐出了%f元。\n",na,s);
}


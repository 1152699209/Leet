#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int m,n=0;//宿舍总数,宿舍数
struct student
{
	char name[9];//学生姓名
	long int num;//学生学号 
	char college[9];//学生所属学院
};
struct dorm
{
	char hall_num[10];//宿舍楼号
	char name[10];//宿舍名称
	long int num;//宿舍编号
	char nam[10];//寝室长名字
	char sex[1];//寝室学生性别
	int score;
	int a;//宿舍床位
	struct student stu[8];//每个寝室八个人
	struct dorm *next;
};
struct dorm* add(void)
{
	int j=0,k;
	struct dorm*p1,*p2,*head;
	if(n<m || n==m)
	{
		p1=p2=(struct dorm*)malloc(sizeof(struct dorm));
		if(p1==NULL)printf("error");
		printf("楼号");
		scanf("%s",p1->hall_num);
		printf("名称");
		scanf("%s",p1->name);
		printf("编号");
		scanf("%ld",&p1->num);//输入第一个宿舍信息
		printf("寝室长名字");
		scanf("%s",p1->nam);
		printf("寝室学生性别");
		scanf("%s",p1->sex);
		printf("寝室得分");
		scanf("%d",&p1->score);
		printf("床位");
		scanf("%d",&p1->a);//输入第一个宿舍信息
		k=p1->a;
		for(j=0;j<k;j++)
				{
					printf("输入学生姓名");
					scanf("%s",p1->stu[j].name);
					printf("输入学生学号");
					scanf("%ld",&p1->stu[j].num);
					printf("输入学生所属学院");
					scanf("%s",p1->stu[j].college);
				}
		n++;
		while(k!=0)//循环 输入剩下n-1个宿舍的信息，链表
		{
			if(n==1)head=p1;
			else p2->next=p1;
				p2=p1;
				p1=(struct dorm*)malloc(sizeof(struct dorm));
				if(p1==NULL)printf("内存不足");
				printf("楼号");
		        scanf("%s",p1->hall_num);
		        printf("名称");
		        scanf("%s",p1->name);
		        printf("编号");
				scanf("%ld",&p1->num);
				printf("寝室长名字");
		        scanf("%s",p1->nam);
				printf("寝室学生性别");
		        scanf("%s",p1->sex);
				printf("寝室得分");
		        scanf("%d",&p1->score);
				printf("床位");
				scanf("%d",&p1->a);
				k=p1->a;
				printf("输入寝室学生信息\n");
				for(j=0;j<k;j++)
				{
					printf("输入学生姓名");
					scanf("%s",p1->stu[j].name);
					printf("输入学生学号");
					scanf("%ld",&p1->stu[j].num);
					printf("输入学生所属学院"); 
					scanf("%s",p1->stu[j].college);
				}
				n++;
		}
		p2->next=NULL;
		printf("%d",n);
	}
	return head;
}
void rank(struct dorm *head)
{
	struct dorm *p1=NULL,*p2=NULL;
	p1=head->next;
	while(p1!=p2)
	{
		while(p1->next!=p2)
		{
			if(p1->score<p1->next->score)
			{
				struct dorm temp=*p1;
				*p1=*p1->next;
				*p1->next=temp;
			}
			p1=p1->next;
		}
		p2=p1;
		p1=head->next;
	}
}

void lookthrough(struct dorm *p1)//查看全部住宿信息(完成)
{
	int j,k;
	do
	{ 
		printf("楼号:%5s\t名称:%5s\t编号:%5ld\t寝室长:%5s\t寝室学生性别:%5s\t寝室的得分:%d\t床位:%d\n",p1->hall_num,p1->name,p1->num,p1->nam ,p1->sex,p1->score,p1->a);
		k=p1->a;
		printf("姓名\t学号\t学院\n");
		for(j=0;j<k;j++)
			printf("%s\t%ld\t%s\t\n",p1->stu[j].name,p1->stu[j].num,p1->stu[j].college);
		p1=p1->next;
	}while(p1!=NULL);
}
void del(struct dorm*p1)//删除学生信息(完成)
{
	long int num;
	int a,i,word=0;
	printf("输入删除学生的学号");
	scanf("%ld",&num);
	for(;p1!=NULL;)
	{
		a=p1->a;
		for(i=0;i<a;i++)
		{
			if(num==p1->stu[i].num)
			{
				p1->stu[i].num=p1->stu[i+1].num;
				strcpy(p1->stu[i].name,p1->stu[i+1].name );
				word=1;
			}

		}
			if(word==1)
		{ 
			p1->a-=1;
			break;
		}
		p1=p1->next;
	}
}
void find(struct dorm *p1)//查找住宿信息！！！！
{
	long int num;
	int i,word=0,k,j;
    printf("请输入学生学号\n");
	scanf("%ld",&num);
	while(p1!=NULL)
	{
		j=p1->a;
		for(i=0;i<j;i++)
		{
			k=p1->stu[i].num;
			if(num==k)
			{
				printf("姓名:%s 学号:%ld 楼号:%5s 寝室学生性别:%s 寝室编号:%d\n",p1->stu[i].name,p1->stu[i].num,p1->hall_num,p1->sex,p1->num);
				word=1;
			}
		}
		if(word==1)break;
		p1=p1->next;
		
	}
	if(p1==NULL)printf("查无此人\n");
}
void insert(struct dorm *p1)//插入住宿学生信息(完成)
{
	struct dorm *p2;
	long int num,k;
	printf("输入你要插入学生的宿舍编号");
	scanf("%ld",&num);
		for(;p1!=NULL;)
		{
			k=p1->a;
			k+=1;
			if(k>8)//test
			{
				printf("宿舍已满\n");
				break;
			}//end
			else if(num==p1->num) 
			{
				p2=p1;
				break;
			}
			p1=p1->next;
		}
		k=p2->a;
		printf("输入学生姓名");
		scanf("%s",p2->stu[k].name);
		printf("输入学生学号");
		scanf("%ld",&p2->stu[k].num);
		printf("输入学生所属学院"); 
		scanf("%s",p2->stu[k].college);
		p2->a+=1;
}
void  change1(struct dorm*p1)//修改宿舍名称函数
{
	char c[10],t[10];
	long int num;
	int k;
	printf("输入所需修改寝室的楼号");
	scanf("%s",c);
	printf("输入所需修改寝室的编号");
	scanf("%ld",&num);
	while(p1!=NULL)
	{
		k=strcmp(p1->hall_num,c);
		if(k==0)
		{
			if(num==p1->num)
			{
				printf("输入新的宿舍名称");
				scanf("%s",t);
				strcpy(p1->name,t);
			}
		}
	}
}
void change2(struct dorm*p1)
{
	char c[10],t[10];
	long int num;
	int k;
	printf("输入所需修改寝室的楼号");
	scanf("%s",c);
	printf("输入所需修改寝室的编号");
	while(p1!=NULL)
	{
		k=strcmp(p1->hall_num,c);
		if(k==0)
		{
			if(num==p1->num)
			{
				printf("输入新的寝室长名称");
				scanf("%s",t);
				strcpy(p1->nam,t);
			}
		}
	}
}
void change(struct dorm*p1)
{
	int i;
	printf("输入所需要修改的信息");
	printf("1--寝室名称\n");
	printf("2--寝室长姓名\n");
	do
	{

		scanf("%d",&i);
		switch(i)
		{
		case 1:change1(p1);break;
		case 2:change2(p1);break;
		default:printf("输入数字无效");
		}
	}while(i!=0);
}
void main()
{
	int i;
	struct dorm*head;
	printf("欢迎使用高校宿舍管理系统\n");
	printf("**********************\n");
	do
	{
		printf("0--退出\n");
		printf("1--增加\n");
		printf("2--插入\n");
		printf("3--删除\n");
		printf("4--查找\n");
		printf("5--浏览住宿信息\n");
		printf("6--修改寝室信息\n");
		//printf("7--排序\n");
		scanf("%d",&i);
		switch(i)
		{
		case 0:break;
		case 1:head=add();break;
		case 2:;insert(head);break;
		case 3:del(head);break;
		case 4:find(head);break;
		case 5:lookthrough(head);break;
		//case 6:change(head);break;
		//case 7:rank(head);break;
		}
	}while(i!=0);
}


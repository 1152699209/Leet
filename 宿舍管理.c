#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int m,n=0;//��������,������
struct student
{
	char name[9];//ѧ������
	long int num;//ѧ��ѧ�� 
	char college[9];//ѧ������ѧԺ
};
struct dorm
{
	char hall_num[10];//����¥��
	char name[10];//��������
	long int num;//������
	char nam[10];//���ҳ�����
	char sex[1];//����ѧ���Ա�
	int score;
	int a;//���ᴲλ
	struct student stu[8];//ÿ�����Ұ˸���
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
		printf("¥��");
		scanf("%s",p1->hall_num);
		printf("����");
		scanf("%s",p1->name);
		printf("���");
		scanf("%ld",&p1->num);//�����һ��������Ϣ
		printf("���ҳ�����");
		scanf("%s",p1->nam);
		printf("����ѧ���Ա�");
		scanf("%s",p1->sex);
		printf("���ҵ÷�");
		scanf("%d",&p1->score);
		printf("��λ");
		scanf("%d",&p1->a);//�����һ��������Ϣ
		k=p1->a;
		for(j=0;j<k;j++)
				{
					printf("����ѧ������");
					scanf("%s",p1->stu[j].name);
					printf("����ѧ��ѧ��");
					scanf("%ld",&p1->stu[j].num);
					printf("����ѧ������ѧԺ");
					scanf("%s",p1->stu[j].college);
				}
		n++;
		while(k!=0)//ѭ�� ����ʣ��n-1���������Ϣ������
		{
			if(n==1)head=p1;
			else p2->next=p1;
				p2=p1;
				p1=(struct dorm*)malloc(sizeof(struct dorm));
				if(p1==NULL)printf("�ڴ治��");
				printf("¥��");
		        scanf("%s",p1->hall_num);
		        printf("����");
		        scanf("%s",p1->name);
		        printf("���");
				scanf("%ld",&p1->num);
				printf("���ҳ�����");
		        scanf("%s",p1->nam);
				printf("����ѧ���Ա�");
		        scanf("%s",p1->sex);
				printf("���ҵ÷�");
		        scanf("%d",&p1->score);
				printf("��λ");
				scanf("%d",&p1->a);
				k=p1->a;
				printf("��������ѧ����Ϣ\n");
				for(j=0;j<k;j++)
				{
					printf("����ѧ������");
					scanf("%s",p1->stu[j].name);
					printf("����ѧ��ѧ��");
					scanf("%ld",&p1->stu[j].num);
					printf("����ѧ������ѧԺ"); 
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

void lookthrough(struct dorm *p1)//�鿴ȫ��ס����Ϣ(���)
{
	int j,k;
	do
	{ 
		printf("¥��:%5s\t����:%5s\t���:%5ld\t���ҳ�:%5s\t����ѧ���Ա�:%5s\t���ҵĵ÷�:%d\t��λ:%d\n",p1->hall_num,p1->name,p1->num,p1->nam ,p1->sex,p1->score,p1->a);
		k=p1->a;
		printf("����\tѧ��\tѧԺ\n");
		for(j=0;j<k;j++)
			printf("%s\t%ld\t%s\t\n",p1->stu[j].name,p1->stu[j].num,p1->stu[j].college);
		p1=p1->next;
	}while(p1!=NULL);
}
void del(struct dorm*p1)//ɾ��ѧ����Ϣ(���)
{
	long int num;
	int a,i,word=0;
	printf("����ɾ��ѧ����ѧ��");
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
void find(struct dorm *p1)//����ס����Ϣ��������
{
	long int num;
	int i,word=0,k,j;
    printf("������ѧ��ѧ��\n");
	scanf("%ld",&num);
	while(p1!=NULL)
	{
		j=p1->a;
		for(i=0;i<j;i++)
		{
			k=p1->stu[i].num;
			if(num==k)
			{
				printf("����:%s ѧ��:%ld ¥��:%5s ����ѧ���Ա�:%s ���ұ��:%d\n",p1->stu[i].name,p1->stu[i].num,p1->hall_num,p1->sex,p1->num);
				word=1;
			}
		}
		if(word==1)break;
		p1=p1->next;
		
	}
	if(p1==NULL)printf("���޴���\n");
}
void insert(struct dorm *p1)//����ס��ѧ����Ϣ(���)
{
	struct dorm *p2;
	long int num,k;
	printf("������Ҫ����ѧ����������");
	scanf("%ld",&num);
		for(;p1!=NULL;)
		{
			k=p1->a;
			k+=1;
			if(k>8)//test
			{
				printf("��������\n");
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
		printf("����ѧ������");
		scanf("%s",p2->stu[k].name);
		printf("����ѧ��ѧ��");
		scanf("%ld",&p2->stu[k].num);
		printf("����ѧ������ѧԺ"); 
		scanf("%s",p2->stu[k].college);
		p2->a+=1;
}
void  change1(struct dorm*p1)//�޸��������ƺ���
{
	char c[10],t[10];
	long int num;
	int k;
	printf("���������޸����ҵ�¥��");
	scanf("%s",c);
	printf("���������޸����ҵı��");
	scanf("%ld",&num);
	while(p1!=NULL)
	{
		k=strcmp(p1->hall_num,c);
		if(k==0)
		{
			if(num==p1->num)
			{
				printf("�����µ���������");
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
	printf("���������޸����ҵ�¥��");
	scanf("%s",c);
	printf("���������޸����ҵı��");
	while(p1!=NULL)
	{
		k=strcmp(p1->hall_num,c);
		if(k==0)
		{
			if(num==p1->num)
			{
				printf("�����µ����ҳ�����");
				scanf("%s",t);
				strcpy(p1->nam,t);
			}
		}
	}
}
void change(struct dorm*p1)
{
	int i;
	printf("��������Ҫ�޸ĵ���Ϣ");
	printf("1--��������\n");
	printf("2--���ҳ�����\n");
	do
	{

		scanf("%d",&i);
		switch(i)
		{
		case 1:change1(p1);break;
		case 2:change2(p1);break;
		default:printf("����������Ч");
		}
	}while(i!=0);
}
void main()
{
	int i;
	struct dorm*head;
	printf("��ӭʹ�ø�У�������ϵͳ\n");
	printf("**********************\n");
	do
	{
		printf("0--�˳�\n");
		printf("1--����\n");
		printf("2--����\n");
		printf("3--ɾ��\n");
		printf("4--����\n");
		printf("5--���ס����Ϣ\n");
		printf("6--�޸�������Ϣ\n");
		//printf("7--����\n");
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


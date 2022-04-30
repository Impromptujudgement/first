/*1.&的使用
#include<stdio.h>
void test(int  &x)
{
	x=1024;
	printf("函数内部testx=%d\n",x );
}
int main()
{
	int x=1;
	printf("调用函数前x=%d\n",x );
	test(x);
	printf("调用函数后x=%d\n",x );
	return 0;
}
2.顺序表的动态分配
#include <stdio.h>
#include <stdlib.h>
#define InitSize 10
typedef struct 
{
	int *data;
	int MaxSize;
	int length;
} SeqList;
void InitList(SeqList &L)
{
	L.data=(int *)malloc(InitSize*sizeof(int));
	L.length=0;
	L.MaxSize=InitSize;
}
void IncreaseSize(SeqList &L,int len)
{
	int *p=L.data;
	L.data=(int *)malloc((L.MaxSize+len)*sizeof(int));
	for (int i = 0; i < L.length; ++i)
	{
		L.data[i]=p[i];
	}
	L.MaxSize=L.MaxSize+len;
	free(p);
}
int main()
{
	SeqList L;
	InitList(L);
	IncreaseSize(L,10);
	printf("%d\n", L.MaxSize);
	return 0;
}
3.顺序表的静态创建、插入、删除、查找
#include <stdio.h>
#define MaxSize 10
typedef struct 
{
	int data[MaxSize];
	int length;
}SqList;
bool ListDelete(SqList &L,int i,int &e)
{
    if (i<1 || i>L.length)
    {
	return false;
    } 
    e=L.data[i-1];
    for (int j = i; j < L.length; ++j)
    {
    	L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}
bool ListInsert(SqList &L,int i,int e)
{
	if (i<1 || i>L.length+1)
	{
		return false;
	}
	if (L.length>=MaxSize)
	{
		return false;
	}
	for (int j = L.length; j>=i; j--)
	{
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
	return true;
}
void InitList(SqList &L)
{
	for (int i = 0; i < MaxSize; ++i)
	{
		L.data[i]=0;
	}
	L.length=0;
}
int GetElem(SqList L,int i)
{

	return L.data[i-1];
}
int LocateElem(SqList L,int e)
{
	for (int i = 0; i < L.length; ++i)
	{
		if (L.data[i]==e)
		{
			return i+1;
		}
	}
	return 0;

}
int main()
{
	SqList L;
	InitList(L);
	int e=-1;
	ListInsert(L,1,1);
	ListInsert(L,2,2);
	ListInsert(L,3,3);
	ListInsert(L,4,4);
	ListInsert(L,5,8);
	if (ListDelete(L,2,e))
	{
		printf("已删除第3个元素，删除元素值为=%d\n",e );
	}
	else
		printf("位序i不合法，删除失败\n");
	int b=GetElem(L,1);
	printf("%d\n", b);
	int c=LocateElem(L,8);
	printf("%d\n", c);
	return 0;
}
4.不带头单链表的定义
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;
bool InitList(LinkList &L)
{
	L=NULL;
	return true;
}
bool Empty(LinkList L)
	{
		return(L==NULL);
	}
int main()
{
	LinkList L;
	InitList(L);
	printf("%d\n", Empty(L));
}
5.带头结点单链表的定义
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;
bool InitList(LinkList &L)
{
	L=(LNode *) malloc(sizeof(LNode));
	if (L==NULL)
	{
		return false;
	}
	L->next =NULL;
	return true;
}
bool Empty(LinkList L)
	{
		return(L->next ==NULL);
	}
int main()
{
	LinkList L;
	InitList(L);
	printf("%d\n", Empty(L));
	return 0;
}
6.单链表的插入、删除、查找、创建、逆置
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;
bool InitList(LinkList &L)
{
	L=(LNode *) malloc(sizeof(LNode));
	if (L==NULL)
	{
		return false;
	}
	L->next =NULL;
	return true;
}
bool InsertNextNode(LNode *p,int e)
{
	if (p==NULL)
	{
		return false;
	}
	LNode *s=(LNode *)malloc(sizeof(LNode));
	if (s==NULL)
	{
		return false;
	}
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}
bool ListInsert(LinkList &L,int i,int e)
{
	if (i<1)
	{
		return false;
	}
	LNode *p;
	int j=0;
	p=L;
	while(p!=NULL && j<i-1)
	{
		p=p->next;
		j++;
	}
	return InsertNextNode(p,e);
}
bool InsertPriorNode(LNode *p,LNode *s)
{
	if (p==NULL ||s==NULL)
	{
		return false;
	}
	s->next=p->next;
	p->next=s;
	int temp=p->data;
	p->data=s->data;
	s->data=temp;
	return true;
}
bool ListDelete(LinkList &L,int i,int &e)
{
	if (i<1)
	{
		return false;
	}
	LNode *p;
	int j=0;
	p=L;
	while(p!=NULL && j<i-1)
	{
		p=p->next;
		j++;
	}
	if (p==NULL || p->next==NULL)
	{
		return false;
	}
	LNode *q=p->next;
	free(q);
	return true;
}
bool DeleteNode(LNode *p)
{
	if (p==NULL)
	{
		return false;
	}
	LNode *q=p->next;
	p->data=p->next->data;
	p->next=q->next;
	free(q);
	return true;
}
LNode *GetElem(LinkList L,int i)
{
	if (i<0)
	{
		return NULL;
	}
	LNode *p;
	int j=0;
	p=L;
	while(p!=NULL && j<i)
	{
		p=p->next;
		j++;
	}
	return p;
}
LNode *LocateElem(LinkList L,int e)
{
	LNode *p=L->next;
	while(p!=NULL && p->data !=e)
	{
		p=p->next;
	}
	return p;
}
int Length(LinkList L)
{
	int len=0;
	LNode *p=L;
	while(p->next != NULL)
	{
		p=p->next;
		len++;
	}
	return len;
}
LinkList List_TailInsert(LinkList &L)
{
	int x;
	L=(LinkList)malloc(sizeof(LNode));
	LNode *s,*r=L;
	scanf("%d",&x);
	while(x!=9999)
	{
		s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
		r->data=s;
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;
	return L;
}
LinkList List_HeadInsert(LinkList &L)
{
	LNode *s;
	int x;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	scanf("%d",&x);
	while(x!=9999)
	{
		s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
		s->next=L->next;
		L->next=s;
		scanf("%d",&x);
	}
	return L;
}
int main()
{
	LinkList L;
	List_HeadInsert(L);
	return 0;
}
7.双链表
#include<stdio.h>
#include<stdlib.h>
typedef struct DNode
{
	int data;
	struct DNode *prior,*next;
}DNode,*DLinklist;
bool InitDLinklist(DLinklist &L)
{
	L=(DNode *)malloc(sizeof(DNode));
	if (L==NULL)
	{
		return false;
	}
	L->prior=NULL;
	L->next=NULL;
	return true;
}
bool Empty(DLinklist L)
{
	if (L->next==NULL)
	{
		return true;
	}
	else return false;
}
bool InsertNextDNode(DNode *p,DNode *s)
{
	if (p==NULL ||s==NULL)
	{
		return false;
	}
	s->next=p->next;
	if (p->next!=NULL)
	{
		p->next->prior=s;
	}
	s->prior=p;
	p->next=s;
	return true;
}

bool DeleteNextDNode(DNode *p)
{
	if (p==NULL)
	{
		return false;
	}
	DNode *q=p->next;
	if (q==NULL)
	{
		return false;
	}
	p->next=q->next;
	if (q->next==NULL)
	{
		q->next->prior=p;
	}
	free(q);
	return true;
}
void DestroyList(DLinklist &L)
{
	while(L->next!=NULL)
		DeleteNextDNode(L);
	free(L);
	L=NULL;
}
int main(int argc, char const *argv[])
{
	DLinklist L;
	InitDLinklist(L);
	int a=Empty(L);
	printf("%d\n",a );
	return 0;
}
8.顺序栈
#include<stdio.h>
#define MaxSize 10
typedef struct 
{
	int data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack &S)
{
	S.top=-1;
}
bool Push(SqStack &S,int x)
{
	if (S.top==MaxSize-1)
	{
		return false;
	}
	S.top++;
	S.data[S.top]=x;
	return true;
}
bool Pop(SqStack &S,int &x)
{
	if (S.top==-1)
	{
		return false;
	}
	x=S.data[S.top];
	S.top--;
	return true;
}
int main(int argc, char const *argv[])
{
	SqStack S;
	InitStack(S);
	int x;
	Push(S,scanf("%d",&x));
	Pop(S,x);
	printf("%d\n", x);
	return 0;
}
9.队列
#include<stdio.h>
#define MaxSize 10
typedef struct 
{
	int data[MaxSize];
	int front,rear;
}SqQueue;
void InitQueue(SqQueue &Q)
{
	Q.rear=Q.front=0;
}
bool QueueEmpty(SqQueue Q)
{
	if (Q.rear==Q.front)
	{
		return true;
	}
	else return false;
}
bool EnQueue(SqQueue &Q,int x)
{
	if ((Q.rear+1)%MaxSize==Q.front)
	{
		return false;
	}
	Q.data[Q.rear]=x;
	Q.rear=(Q.rear+1)%MaxSize;
	return true;
}
bool DeQueue(SqQueue &Q,int &x)
{
	if (Q.rear==Q.front)
	{
		return false;
	}
	x=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxSize;
	return true;
}
bool GetHead(SqQueue Q,int &x)
{
	if (Q.rear==Q.front)
	{
		return false;
	}
	x=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxSize;
	return true;
}
int main(int argc, char const *argv[])
{
	SqQueue Q;
	InitQueue(Q);
	EnQueue(Q,6);
	int x;
	GetHead(Q,x);
	printf("%d\n",x );
	return 0;
}
10.字符串
*/
#include<stdio.h>
#define MAXLEN 255
typedef struct 
{
	char ch[MAXLEN];
	int length;
}SString;
bool SubString(SString &Sub ,SString S,int pos,int len)
{
	if (pos+len-1>S.length)
	{
		return false;
	}
	for (int i = pos; i < pos+len; ++i)
	{
		Sub.ch[i-pos+1]=S.ch[i];
	}
	Sub.length=len;
	return true;
}
int StrCompare(SString S,SString T)
{
	for (int i = 1; i <=S.length && i<=T.length; ++i)
	{
		if (S.ch[i]!=T.ch[i])
		{
			return S.ch[i]=T.ch[i];
		}
	}
	return S.length-T.length;
}
int StrLength(SString S)
{   int i=1;
	while(S.ch[i]!='\0')
    i++;
    return i-1;
}
int Index(SString S,SString T)
{
	int i=1,n=StrLength(S),m=StrLength(T);
	SString sub;
	while(i<=n-m+1)
	{
		SubString(sub,S,i,m);
		if (StrCompare(sub,T)!=0)
		{
			++i;
		}
		else return i;
	}
	return 0;
}
int Index2(SString S,SString T)
{
	int i=1,j=1;
	while(i<=S.length && j<T.length)
	{
		if (S.ch[i]==T.ch[i])
		{
			++i;
			++j;
		}
		else
		{
			i=i-j+2;
			j=1;
		}
	}
	if (j>T.length)
	{
		return i-T.length;
	}
	else return 0;
}
int main(int argc, char const *argv[])
{
	SString S,T;
	S.ch[1]='a';
	T.ch[1]='a';
	S.ch[2]='c';
	S.ch[3]='b';
	int n=StrLength(S);
	int m;
	m=Index2(S,T);
	printf("%d\n%d\n",n,m);
	return 0;
}
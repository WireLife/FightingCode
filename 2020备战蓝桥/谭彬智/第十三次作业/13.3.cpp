//注：本程序只能处理一组数据，时间关系没找到goto后失败原因，且n不能过大，原因是n被设为整形数组，可以考虑用字符串读取后转为整形二维数组，也或许有更简单的方法
#include<iostream>
#include<sstream>
using namespace std;

struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
};
typedef struct Node Node;
Node *Get_node(int item,Node *prev0,Node *next0)
{
	Node *p=(Node*)malloc(sizeof(Node));
	p->data=item;
	p->prev=prev0;
	p->next=next0;
	return p;
}
typedef struct
{
	Node *head;
	Node *tail;
	int size;
	int tag;//标记重组
}List;
void Init(List *L)
{
	L->head=(Node*)malloc(sizeof(Node));
	L->tail=(Node*)malloc(sizeof(Node));
	L->head->next=L->tail;
	L->tail->prev=L->head;
	L->size=0;
	L->tag=0;
}
Node *Begin(List *L){return L->head->next;}
Node *End(List *L){return L->tail;}
void Insert(List *L,Node *current,int item)
{
	Node *p=current;
	L->size++;
	p->prev->next=Get_node(item,p->prev,p);
	p->prev=p->prev->next;
}
Node *Erase(List *L,Node *current)
{
	Node *p=current;
	Node *re=p->next;
	L->size--;
	p->prev->next=p->next;
	p->next->prev=p->prev;
	free(p);
	return re;
}
Node *find1(List *L,int item)
{
	Node *p=Begin(L);
	for(int i=0;i<L->size;i++)
	{
		if(p->data==item)
			return p;
		else p=p->next;
	}
}
void find(List *L,int item)
{
	Node *p=Begin(L);
	for(int i=0;i<L->size;i++)
	{
		if(p->data==item)
		{
			cout<<p->prev->data<<' '<<p->next->data<<"中间"<<endl;
			break;
		}
		else p=p->next;
	}
}
void inserttop(List *L,int item){if(L->tag==0)Insert(L,Begin(L),item);else if(L->tag==1)Insert(L,End(L),item);}
void insertend(List *L,int item){if(L->tag==0)Insert(L,End(L),item);else if(L->tag==1)Insert(L,Begin(L),item);}
void insertbefore(List *L,int n,int item){Node *p=find1(L,n);if(L->tag==0)Insert(L,p,item);else if(L->tag==1)Insert(L,p->next,item);}
void insertback(List *L,int n,int item){Node *p=find1(L,n);if(L->tag==0)Insert(L,p->next,item);else if(L->tag==1)Insert(L,p,item);}
Node *remove(List *L,int item){Node *p=find1(L,item);Node *p2=Erase(L,p);return p2;}
void ttraversal(List *L)
{
	if(L->tag==0)
	{
	Node *p=Begin(L);
	for(int i=0;i<L->size;i++)
	{
		cout<<p->data<<' ';
		p=p->next;
	}
	cout<<endl;
	}
	else if(L->tag==1)
	{
	Node *p=End(L);
	for(int i=0;i<L->size;i++)
	{
		p=p->prev;
		cout<<p->data<<' ';		
	}
	cout<<endl;
	}
}
void etraversal(List *L)
{
	if(L->tag==0)
	{
	Node *p=End(L);
	for(int i=0;i<L->size;i++)
	{
		p=p->prev;
		cout<<p->data<<' ';		
	}
	cout<<endl;
	}
	else if(L->tag==1)
	{
	Node *p=Begin(L);
	for(int i=0;i<L->size;i++)
	{
		cout<<p->data<<' ';
		p=p->next;
	}
	cout<<endl;
	}
}
void modify(List *L,int n,int item){Node *p=find1(L,n);p->data=item;}
int zize(List *L){return L->size;}
void reorg(List *L)
{
	if(L->tag==0)
    	L->tag=1;
	else if(L->tag==1)
		L->tag=0;
}



int main()
{
	List L;
	Init(&L);
	int n[11];//1-10,避免错误
	int m[11];
	int k[11];
	int x[11];
	int y[11];
	cout<<"输入几组数据?"<<endl;
	int count;
	cin>>count;
	for(int i=1;i<=count;i++)
	{
		cin>>n[i]>>m[i];
		for(int j=1;j<=m[i];j++)
		{
			cin>>k[j];
			if(k[j]!=4)
				cin>>x[j]>>y[j];
		}
	}
	int t=1;//第t组数据
loop:	for(int a=1;a<=n[t];a++)
		insertend(&L,a);
	for(int j=1;j<=m[t];j++)
	{
		switch(k[j])
		{
		case 1:
			remove(&L,x[j]);
			insertbefore(&L,y[j],x[j]);
			break;
		case 2:
			remove(&L,x[j]);
			insertback(&L,y[j],x[j]);
			break;
		case 3:
			{
				Node *px=remove(&L,x[j]);
				Node *py=remove(&L,y[j]);
				Insert(&L,px,y[j]);
				Insert(&L,py,x[j]);
				break;
			}
		case 4:
			reorg(&L);
			break;
		}
	}
	int s=0;
	Node *p=Begin(&L);
	cout<<"Case"<<t<<':';
	for(a=1;a<=n[t];a++,p=p->next)
	{
		for(int k=0;k<=n[t]/2;k++)
			if((L.tag==0&&a==k*2+1)||(L.tag==1&&a==k*2))
			{
				s+=p->data;
				break;
			}
	}
	cout<<s<<endl;
	if(t<count)
	{
		t++;		
		for(Node *w=Begin(&L);w!=End(&L);w=w->next)
			Erase(&L,w);
		if(L.tag==1)L.tag=0;
		goto loop;
	}
	return 0;
}

#include<iostream>
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
	int n[10+1];
	int m[10+1];
	int k[10+1];
	int x[10+1];
	int y[10+1];
	cout<<"输入数据后以#结束"<<endl;
	int bb=0;
	int i=1;
	while(cin>>n[i]&&n[i]!='#')
	{
		cin>>m[i];
		for(int j=1;j<=m[i];j++)
		{
			bb++;
			cin>>k[j];
			if(k[j]!=4)
				cin>>x[j]>>y[j];
		}
		i++;
	}
	int t=1;
loop:	for(i=1;i<=n[t];i++)
		insertend(&L,i);
	i=1;
	while(k[i]!=NULL)
	{
	switch(k[i])
	{
	case 1:
		remove(&L,x[i]);
		insertbefore(&L,y[i],x[i]);
		break;
	case 2:
		remove(&L,x[i]);
		insertback(&L,y[i],x[i]);
		break;
	case 3:
		{
		Node *px=remove(&L,x[i]);
		Node *py=remove(&L,y[i]);
		Insert(&L,px,y[i]);
		Insert(&L,py,x[i]);
		break;
		}
	case 4:
		reorg(&L);
		break;
	}
	i++;
	}
	int s=0;
	Node *p=Begin(&L);
		cout<<"Case"<<t<<':';
		for(int q=1;q<=n[t];q++,p=p->next)
		{
			for(int k=0;k<=n[t]/2;k++)
				if(q==k*2+1)
				{
					s+=p->data;
					break;
				}
		}
		cout<<s<<endl;
	if(t<bb)
	{
		Node *w=Begin(&L);
		for(int q=0;q<L.size;q++)
		{
			Erase(&L,w);
			w=w->next;
		}
		t++;
		goto loop;
	}
	return 0;
}

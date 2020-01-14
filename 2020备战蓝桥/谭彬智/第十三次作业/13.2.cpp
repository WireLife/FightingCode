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
	int order;
	while (order<100)
	{
		
		cout<<"请选择命令:1-头部插入,2-尾部插入,3-a前插入,4-a后插入,5-删除,6-查找,7-头起遍历,8-尾起遍历,9-修改,10-链表长度,11-链表重组,0-结束:\n";
        cin>>order;
        switch (order)
		{
			int x,x1;
		case 0:
			order=100;
			break;
		case 1: 
			cout<<"请输入需要插入的数:";
			cin>>x;   
			inserttop(&L,x);
			break;
		case 2:
			cout<<"请输入需要插入的数:";
	       	cin>>x;   
			insertend(&L,x);
			break;
		case 3:
			cout<<"在哪个数之前插入什么数？"; 
			cin>>x>>x1;
			insertbefore(&L,x,x1);
			break;
		case 4: 
			cout<<"在哪个数之后插入什么数？"; 
			cin>>x>>x1; 
			insertback(&L,x,x1); 
			break;
	    case 5: 
			cout<<"需要删除哪个数？";
			cin>>x;  
			remove(&L,x); 
			break;
		case 6: 
			cout<<"请输入需要查找的数:";
			cin>>x; 
			find(&L,x); 
			break;
		case 7:  
			ttraversal(&L);
			break;
		case 8:  
			etraversal(&L);
			break;
		case 9:
			cout<<"请输入需要将什么数修改成何数:";
			cin>>x>>x1;   
			modify(&L,x,x1); 
			break;
		case 10: 
			cout<<"链表长度为："<<zize(&L)<<endl;
			break;
		case 11:
			reorg(&L); 
			break;
		} 
    }
	cout<<endl;   
	return 0;
}

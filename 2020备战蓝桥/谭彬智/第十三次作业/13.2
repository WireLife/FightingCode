#include<iostream>
using namespace std;
struct link
{
	int num;
	struct link* front;
	struct link* next;
};
int size=0;
link* top=(struct link*)malloc(sizeof(struct link)); 
link* end=(struct link*)malloc(sizeof(struct link)); 

link* w1=(struct link*)malloc(sizeof(struct link)); 
link* w2=(struct link*)malloc(sizeof(struct link));
link* p=(struct link*)malloc(sizeof(struct link));
void inserttop(int x)
{	
	w1=top->next;	
	p->num=x;
	//链接
	top->next=p;
	p->next=w1;
	w1->front=p;
	p->front=top;

	size++;
}

void insertend(int x)
{
	w1=end->front;
	p->num=x;

	w1->next=p;
	p->next=end;
	end->front=p;
	p->front=w1;

	size++;
}

void insertbefore(int n,int x)
{
	p->num=x;
	w1=top->next;
	for(int i=0;i<size;i++)
	{
		if(w1->num==n)
		{
			w2=w1->front;
			w1->front=p;
			p->front=w2;
			w2->next=p;
			p->next=w1;

			size++;
		}
		else w1=w1->next;
	}
}

void insertback(int n,int x)
{
	p->num=x;
	w1=top->next;
	for(int i=0;i<size;i++)
	{
		if(w1->num==n)
		{
			w2=w1->next;
			w1->next=p;
			p->next=w2;
			w2->front=p;
			p->front=w1;

			size++;
		}
		else w1=w1->next;
	}
}

void remove(int n)
{
	p=top->next;
	for(int i=0;i<size;i++)
	{
		if(p->num==n)
		{
			w2=p->next;
			w1=p->front;
			w1->next=w2;
			w2->front=w1;

			size--;
		}
		else p=p->next;
	}
}

void find(int n)
{
	p=top->next;
	for(int i=0;i<size;i++)
	{
		if(p->num==n)
		{
			w2=p->next;
			w1=p->front;
			cout<<"前一个节点元素："<<w1->num<<"后一个节点元素："<<w2->num<<endl;
		}
		else p=p->next;
	}
}

void ttraversal()
{
	w1=top->next;
	for(int i=0;i<size;i++)
	{
		cout<<w1->num<<" ";
		w1=w1->next;
	}
	cout<<endl;
}

void etraversal()
{
	w1=end->front;
	for(int i=0;i<size;i++)
	{
		cout<<w1->num<<" ";
		w1=w1->front;
	}
	cout<<endl;
}

void modify(int n,int x)
{
	p=top->next;
	for(int i=0;i<size;i++)
	{
		if(p->num==n)
			p->num=x;
		else p=p->next;
	}
}

void zize()
{
	cout<<"链表长度为："<<size;
}

void reorg()
{
	p=top;
	end=p;
	top=end;
}

int main()
{
	top->num=0;
end->num=-1;
top->next=end;
end->front=top;
	int order;
	while (order<100)
	{
		
		cout<<"请选择命令:1-头部插入,2-尾部插入,3-a前插入,4-a后插入,5-删除,6-查找,7-头起遍历,8-尾起遍历,9-修改,10-链表长度,11-链表重组,0-结束:\n";
        cin>>order;
        switch (order)
		{
			int x,x1;
		case 0:order=100;break;
		case 1: cout<<"请输入需要插入的数:";
				 cin>>x;    inserttop(x);break;
		case 2: cout<<"请输入需要插入的数:";
				 cin>>x;    insertend(x);break;
		case 3:cout<<"在哪个数之前插入什么数？"; 
			cin>>x>>x1;	 insertbefore(x,x1); break;
		case 4: cout<<"在哪个数之后插入什么数？"; 
			 cin>>x>>x1;  insertback(x,x1); break;
	    case 5: cout<<"需要删除哪个数？";
			cin>>x;   remove(x);  break;
		case 6: cout<<"请输入需要查找的数:";
				 cin>>x;    find(x);  break;
		case 7:  ttraversal();break;
		case 8:  etraversal();break;
		case 9: cout<<"请输入需要将什么数修改成何数:";
			cin>>x>>x1;   modify(x,x1);  break;
		case 10: zize(); break;
		case 11: reorg(); break;
		} 
    }
	cout<<endl;   
	return 0;
}

#include<iostream>
using namespace std;
typedef struct node
{
	int num;
	node* prev;
	node* next;
}node;
typedef struct list
{
	int size;
	node* begin;
	node* end;
}list;
node* Init(node* p1, node* p2, int n)
{
	node* p3 = new node;
	p3->prev = p1;
	p3->next = p2;
	p3->num = n;
	return p3;
}
void inserttop(list* p,int n)			//ͷ������Ԫ��
{
	node* a = new node;
	a->next = p->begin;
	p->begin->prev = a;
	p->begin = a;
	a->prev = NULL;
	a->num = n;
	p->size++;
}
void insertbefore(list* p, int n)		//β������Ԫ��
{
	node* a = new node;
	p->end->next = a;
	a->prev = p->end;
	p->end = a;
	a->next = NULL;
	a->num = n;
	p->size++;
}
void insertback(list*p,node* n1,int n)//ĳ��Ԫ�ر������Ԫ��
{
	node* a = new node;
	n1->next->prev = a;
	a->next = n1->next;
	a->prev = n1;
	n1->next = a;
	a->num = n;
	p->size++;
}
void remove(list*p,node* n)//ɾ��
{
	n->prev->next = n->next;
	n->next->prev = n->prev;
	p->size--;
}
node* find(list* p, int n)			//����Ԫ�أ�����ҵ����ؽڵ�ָ��
{
	node* it = p->begin;
	while (it != NULL)
	{
		if (it->num == n)
			break;
		it = it->next;
	}
	return it;
}
void size(list* p)
{
	cout << p->size << endl;
}
void ttraversal(list* p)
{
	node* p1 = p->begin;
	if (p1 == NULL)
		cout << "�ձ�" << endl;
	while (p1 != NULL)
	{
		p1 = p1->next;
	}
}
void etravesal(list* p)
{
	node* p1 = p->end;
	while (p1 != NULL)
	{
		p1 = p1->prev;
	}
}
void modify(node* n, int a)
{
	n->num = a;
}
void raorg(list* p)
{
	node* t = p->begin;
	p->begin = p->end;
	p->end = t;
}
node* F(list*p,int m)
{
	node* p1 = p->begin;
	for (int i = 0; i < m; i++)
	{
		p1 = p1->next;
	}
	return p1;
}
void left(list* p, int a, int b)  //��b�Ƶ�a�����
{
	insertback(p,F(p, a)->prev, F(p, b)->num);
	remove(p, F(p, b));
}
void right(list* p, int a, int b)//��a�Ƶ�b���ұ�
{
	insertback(p, F(p, b), F(p, a)->num);
	remove(p, F(p, a));
}
int compare(list*p,int x, int y)//���x��ǰ����0
{
	node* p1 = find(p,x);
	while (p1 != NULL)
	{
		if (p1->num == y)
			return 0;
		p1 = p1->next;
	}
	return 1;
}
void change(list* p, int x, int y)
{
	find(p, x)->num = y;
	find(p, y)->num = x;
}
int main()
{
	int num1,num2;
	cin >> num1>>num2;
	int* a2 = new int[num2];
	for (int i = 0; i < num2; i++)
		cin >> a2[i];
	node* n1=new node;
	list* p = new list;
	node* p1;
	n1->next = NULL;
	n1->prev = NULL;
	n1->num = 1;
	p->begin = n1;
	p->end = n1;
	p->size = 1;
	for (int i = 1; i < num1; i++)
	{
		p1=Init(p->end, NULL, i+1);
		p->end->next = p1;
		p->end = p1;
		p->size++;
	}
	int m, x,y;
	for (int i = 0; i < num2; i++)
	{
		x = a2[i] / 10 % 10; y = a2[i] % 10;
		m = a2[i] / 100;
		switch (m)
		{
		case 1:if (compare(p, x,y ))
					left(p, y,x);
			break;
		case 2:if (compare(p, x, y) == 0)
					right(p, x, y);
			break;
		case 3:change(p, x, y); break;
		case 0:raorg(p); break;
		}
	}
	int s = 0;
	node* p3 = p->begin;
	while (p3 != NULL)
	{
		s += p3->num;
		p3 = p3->next;
		if (p3 == NULL)
			break;
		p3 = p3->next;
	}
	cout << s << endl;
}

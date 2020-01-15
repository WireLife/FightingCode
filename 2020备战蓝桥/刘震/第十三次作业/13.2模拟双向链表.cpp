/*����59ҳ˫����ʵ��������63ҳ��������ܣ�����˫��������ͷ��inserttop��β��insertend��ĳԪ��ǰinsertbefore��
ĳԪ�غ�insertback�������ݡ�ɾ��һ���ڵ�remove������ĳԪ��find��ͷ���������ttraversal��β���������etraversal��
�޸�ĳԪ�ص�ֵmodify����ʾ������zize����������reorg��
*/

//���������ʵ��
/*#include<iostream>
#include<malloc.h>
using namespace std;
struct Link {
	int data;
	Link *next;
};

int main()
{

	//������Ҫ�������в���һ������
	//����Ҫ���ڴ��п���һ�οռ䣬��malloc�����ܾ���ֱ�����ٴ�С
	Link *p = (struct Link*)malloc(sizeof(struct Link));
	Link *head = p;
	p->data = 10;
	Link *next = (struct Link*)malloc(sizeof(struct Link));
	p->next = next;
	p = next;
	p->data = 12;
	cout << head->data << " " << (head->next)->data << endl;
	
	
	
	
	cout << p->data << endl;

	


	free(p);
	system("pause");
	return 0;
}
*/

//����˫������
#include<iostream>
#include<cstdlib>
using namespace std;
struct Link{
	Link *front;  //ָ����һ���ڵ�ĵ�ַ
	int data = 0;    //���ݶΣ���ʼ��Ϊ0
	Link *next;  //ָ����һ���ڵ�ĵ�ַ
};
void inserttop(struct Link *l);//��ͷ������һ��Ԫ��
void insertend(struct Link *l);//��β������һ��Ԫ��
void insertbefore(struct Link *l);//��ĳԪ��ǰ����һ��Ԫ��
void insertback(struct Link *l);//��ĳԪ�غ����һ��Ԫ��
void remove(int val);//ɾ��ĳһ���ڵ�,�����ǰ�ֵɾ��
Link find(int val);//����Ԫ��
void ttraversal();//ͷ���������
void etraversal();//β���������
void modify(struct Link *l,int val);//�޸�ĳһ��Ԫ�ص�ֵ //�������õ���ָ��ڵ�ĵ�ַ��������Ҫ�ı��ֵ
unsigned int size();//���ؽڵ�ĳ���

int k = 0;
Link *fp[100];  //���涯̬���ٵ��ڴ��ָ��
Link *Head;  //�����׽ڵ�
Link *End;   //����β�ڵ�
int cnt = 2; //��ʼ�ڵ�Ϊ2

int main()
{
	//����˫������������յ�
	//Ϊ�׽ڵ㿪��һ���ڴ�ռ�
	Head = (struct Link*)malloc(sizeof(struct Link));
	fp[k++] = Head;
	//�׽ڵ����һ��Ԫ�ؿɶ�������
	Head->front = NULL;
	//Ϊβ�ڵ㿪��һ���ڴ�ռ�
	End = (struct Link*)malloc(sizeof(struct Link));
	fp[k++] = End;
	//β�ڵ�����һ��Ԫ�ؿӶ�Ҳ�����ڵ�
	End->next = NULL;
	//Ȼ��������ڵ���������
	Head->next = End;    //�׽ڵ����һ���ڵ���β�ڵ�
	End->front = Head;   //β�ڵ����һ���ڵ����׽ڵ�
	Head->data = 3;
	End->data = 1;
	
	//��ͷ������һ��Ԫ��
	Link *p = (struct Link*)malloc(sizeof(struct Link));
	fp[k++] = p;
	p->data = 100;
	inserttop(p);
	

	//������ĳһ���ڵ�ǰ��������
	Link *p1= (struct Link*)malloc(sizeof(struct Link));
	fp[k++] = p1;
	p1->data = 3;
	insertbefore(p1);

	ttraversal();
	cout << endl;
	//etraversal();
	//cout << endl;
	for (int i = 0; i < k; i++)
		free(fp[i]);
	system("pause");
	return 0;

}
//��ͷ������һ��Ԫ��
void inserttop(struct Link *l)
{
	Head->front = l;  //��ԭ��ͷ���ڵ��ָ��ǰһ��Ԫ�ص�ָ��ָ��Ҫ����Ľڵ�ĵ�ַ
	l->next = Head;   //����ͷ����ָ����һ���ڵ��ָ��ָ��ԭͷ���ĵ�ַ
	l->front = NULL;  //���µĽڵ��ָ�����¸�Ԫ�ؽڵ��ָ����ΪNULL
	Head = l;         //��ԭ����Ϊͷ���ı�ʶ��������ͷ��
	cnt++;
}

//��β������һ��Ԫ��
void insertend(struct Link *l) {
	End->next = l;
	l->front = End;
	l->next = NULL;
	End = l;
	cnt++;
}

//��ĳԪ��ǰ����һ��Ԫ��
void insertbefore(struct Link *l) {
	Link *p = Head;
	for (int i = 0; i < cnt; i++) {
		if (p->data == l->data) {
			if (p == Head)    //���Ҫ����Ԫ�����ݶ����õ�������ͷ�������ݶΣ���������ͷ������
				inserttop(l);
			else {
				//�Ȱ���һ��˳�����
				(p->front)->next = l;  //��Ԫ�ص�ǰ��һ���ڵ��ָ����һ���ڵ��ָ��ĳ�ָ��Ҫ����Ľڵ�ĵ�ַ   
				l->next = p;			//�Ѳ���Ľڵ��ָ����һ���ڵ��ָ��ָ��Ҫ����Ľڵ����һ��λ��
				//�ڰ���һ���ڵ����
				l->front = p->front;
				p->front = l;
				return;
			}
		}
		p = p->next;
	}
	//��ֹ�����û�бȽϳ�Ԫ��
	insertback(l);  //��Ԫ�ز��뵽���
	cnt++;
}

//��ĳԪ�غ����һ��Ԫ��
void insertback(struct Link *l) {
	Link *p = Head;
	for (int i = 0; i < cnt; i++) {
		if (p->data == l->data) {
			if (p == End)    //���Ҫ����Ԫ�����ݶ����õ�������β�������ݶΣ���������β������
				insertback(l);
			else {
				//��˳���ָ��ָ�����ε���
				l->next = p->next;   
				p->next = l;			
				//�������ָ��ָ�����ε���
				l->front = p;
				(l->next)->front = l;
				return;
			}
		}
		p = p->next;
	}
	//��ֹ�����û�бȽϳ�Ԫ��
	inserttop(l);  //��Ԫ�ز��뵽���
	cnt++;
}

//����Ԫ��
Link find(int val) {
	Link *p = Head;
	for (int i = 0; i < cnt; i++) {
		if (p->data == val)
			return *p;
	}
}

//ͷ���������
void ttraversal() {
	Link *p = Head;
	for (int i = 0; i <= cnt; i++) {
		cout << p->data << " ";
		p = p->next;
	}
}

//β���������
void etraversal() {
	Link *p = End;
	for (int i = 0; i < cnt; i++) {
		cout << p->data << " ";
		p = p->front;
	}
}

//�޸�ĳһ��Ԫ�ص�ֵ
void modify(struct Link *l, int val) {
	l->data = val;
}

//���ؽڵ������
unsigned int size() {
	return cnt;
}

//ɾ��ĳһ���ڵ�,�����ǰ�ֵɾ��
void remove(int val) {
	Link *pp = Head;
	for (int i = 0; i < cnt; i++) {
		if (pp->data == val) {
			if (pp == Head) {
				(pp->next)->front = NULL; //���Ҫɾ��������Ԫ�أ�ֻ��Ҫ����Ԫ�ص���һ���ڵ��ָ����һ���ڵ��ָ����ΪNULL
			}
			else if (pp == End) {
				(pp->front)->next = NULL; //���Ҫɾ������βԪ�أ�ֻ��Ҫ��βԪ�ص���һ���ڵ��ָ����һ���ڵ��ָ����ΪNULL
			}
			else {
				(pp->front)->next = pp->next;
				(pp->next)->front = pp->front;
			}
		}	
	}
	cnt--;
}
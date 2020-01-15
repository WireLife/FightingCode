
//����˫������
#include<iostream>
#include<cstdlib>
using namespace std;
struct Link {
	Link *front;  //ָ����һ���ڵ�ĵ�ַ
	int data = 0;    //���ݶΣ���ʼ��Ϊ0
	Link *next;  //ָ����һ���ڵ�ĵ�ַ
};
void linkTE(); //��ֻ��ͷ��β��ʱ
void inserttop(struct Link *l);//��ͷ������һ��Ԫ��
void insertend(struct Link *l);//��β������һ��Ԫ��
void insertbefore(struct Link *l);//��ĳԪ��ǰ����һ��Ԫ��
void insertback(struct Link *l);//��ĳԪ�غ����һ��Ԫ��
void remove(int val);//ɾ��ĳһ���ڵ�,�����ǰ�ֵɾ��
Link *find(int val);//����Ԫ��
void ttraversal();//ͷ���������
void etraversal();//β���������
void modify(struct Link *l, int val);//�޸�ĳһ��Ԫ�ص�ֵ //�������õ���ָ��ڵ�ĵ�ַ��������Ҫ�ı��ֵ
int size();//���ؽڵ�ĳ���
void freep();  //��ָ��ָ��Ŀռ䶼�ͷ���

int k = 0;
Link *fp[100];  //���涯̬���ٵ��ڴ��ָ��
Link *Head;  //�����׽ڵ�
Link *End;   //����β�ڵ�
int cnt = 0; //��ʼ�ڵ�Ϊ2�����ӵĻ���0
Link *temp;

int main()
{
	//����˫������������յ�
	//Ϊ�׽ڵ㿪��һ���ڴ�ռ�
	Head = (struct Link*)malloc(sizeof(struct Link));
	//Ϊβ�ڵ㿪��һ���ڴ�ռ�
	End = (struct Link*)malloc(sizeof(struct Link));

	/*************************************************************************************************/
	int box, n;
	int op, x, y;
	bool bol = true;
	while (scanf("%d%d", &box, &n) == 2) {
		//�տ�ʼ��ʼ������ǰ�����box����
		for (int i = box; i > 0; i--) {  
			Link*p = (struct Link*)malloc(sizeof(struct Link));
			fp[k++] = p;
			p->data = i;
			inserttop(p);			
		}
		ttraversal();
		freep();     //��һ�֣����нڵ㶼�ͷţ�������ԭʼ��ͷβ�����ڵ�
		linkTE();    //����ԭʼ������ͷβ�ڵ�������һ��
		k = 0;
		cnt = 0;
		cout << endl;

		//����������
		for (int i = 0; i < n; i++) {
			cin >> op >> x >> y;
			if (op == 4)
				bol = false;
			else if (op == 1) {	//���bol=true�ǾͰ�x�Ƶ�y����ߣ����߾Ͱ�x�Ƶ�y���ұ�
				//���ҵ���������λ��
				Link *xp = find(x);
				Link *yp = find(y);
				if (bol) {//Ҫ��x�Ƶ�y�����
					if (x + 1 != y) {     //��xp����yp��ǰ�棬Ȼ���ԭ����xpɾ��

					}
				}

			}
		}






	}
	//����һ�������Ƿ���ȷ
	




	




	cout << "�յ��ͻ���" << endl;




	/*******************************************************************************************************/
	system("pause");
	return 0;

}
void linkTE() {
	Head->front = NULL;	//�׽ڵ����һ��Ԫ�ؿɶ�������
	End->next = NULL;//β�ڵ�����һ��Ԫ�ؿӶ�Ҳ�����ڵ�
	//Ȼ��������ڵ���������
	Head->next = End;    //�׽ڵ����һ���ڵ���β�ڵ�
	End->front = Head;   //β�ڵ����һ���ڵ����׽ڵ�
	Head->data = -1;
	End->data = -1;
}


//��ͷ������һ��Ԫ��
void inserttop(struct Link *l){
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
	temp = Head;
	for (int i = 0; i < cnt; i++) {
		if (temp->data == l->data) {
			if (temp == Head)    //���Ҫ����Ԫ�����ݶ����õ�������ͷ�������ݶΣ���������ͷ������
				inserttop(l);
			else {
				//�Ȱ���һ��˳�����
				(temp->front)->next = l;  //��Ԫ�ص�ǰ��һ���ڵ��ָ����һ���ڵ��ָ��ĳ�ָ��Ҫ����Ľڵ�ĵ�ַ   
				l->next = temp;			//�Ѳ���Ľڵ��ָ����һ���ڵ��ָ��ָ��Ҫ����Ľڵ����һ��λ��
				//�ڰ���һ���ڵ����
				l->front = temp->front;
				temp->front = l;
				return;
			}
		}
		temp = temp->next;
	}
	//��ֹ�����û�бȽϳ�Ԫ��
	insertback(l);  //��Ԫ�ز��뵽���
	cnt++;
}

//��ĳԪ�غ����һ��Ԫ��
void insertback(struct Link *l) {
	temp = Head;
	for (int i = 0; i < cnt; i++) {
		if (temp->data == l->data) {
			if (temp == End)    //���Ҫ����Ԫ�����ݶ����õ�������β�������ݶΣ���������β������
				insertback(l);
			else {
				//��˳���ָ��ָ�����ε���
				l->next = temp->next;
				temp->next = l;
				//�������ָ��ָ�����ε���
				l->front = temp;
				(l->next)->front = l;
				return;
			}
		}
		temp = temp->next;
	}
	//��ֹ�����û�бȽϳ�Ԫ��
	inserttop(l);  //��Ԫ�ز��뵽���
	cnt++;
}

//����Ԫ��
Link *find(int val) {
	temp = Head;
	for (int i = 0; i < cnt; i++) {
		if (temp->data == val)
			return temp;
		temp = temp->next;
	}
}

//ͷ���������
void ttraversal() {
	temp = Head;
	for (int i = 0; i < cnt; i++) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

//β���������
void etraversal() {
	temp = End;
	for (int i = 0; i < cnt; i++) {
		cout << temp->data << " ";
		temp = temp->front;
	}
}

//�޸�ĳһ��Ԫ�ص�ֵ
void modify(struct Link *l, int val) {
	l->data = val;
}

//���ؽڵ������
int size() {
	return cnt;
}

//ɾ��ĳһ���ڵ�,�����ǰ�ֵɾ��
void remove(int val) {
	temp = Head;
	for (int i = 0; i < cnt; i++) {
		if (temp->data == val) {
			if (temp == Head) {
				(temp->next)->front = NULL; //���Ҫɾ��������Ԫ�أ�ֻ��Ҫ����Ԫ�ص���һ���ڵ��ָ����һ���ڵ��ָ����ΪNULL
			}
			else if (temp == End) {
				(temp->front)->next = NULL; //���Ҫɾ������βԪ�أ�ֻ��Ҫ��βԪ�ص���һ���ڵ��ָ����һ���ڵ��ָ����ΪNULL
			}
			else {
				(temp->front)->next = temp->next;
				(temp->next)->front = temp->front;
			}
		}
	}
	cnt--;
}
void freep() {//��ָ��ָ��Ŀռ䶼�ͷ���
	for (int i = 0; i < k; i++)
		free(fp[i]);
}
	

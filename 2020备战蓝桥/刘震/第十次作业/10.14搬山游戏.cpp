/*10.14��ɽ��Ϸ*/

//��Ŀ��˼���ǣ������������ɽ��ÿ������ܰ��������Ȼ�����������ɽ����Ŀ�������Ҫ�����Ŀ����ʱҪ��һ������������ɼ����Ҫ�������

#include<iostream>
#include<cstdlib>      //���������
#include<ctime>        //�������ʱ����Ϊ����
using namespace std;
int main()
{
	cout << "           ��ɽ��Ϸ������ɽ��������ÿ������ܰ����������ÿ�ֽ����������Ϸ������Y���˳�������N��" << endl;
	int n, k, i,        //�������n,k ɽ��������ÿ������ܰ����Ŀ
		cntSum = 0,     //��¼�ܾ���
		cntIWin = 0,    //��¼��Ӯ�Ĵ��� 
		cntPcWin = 0;   //��¼�����Ӯ�Ĵ���
	int I_mv = 0,       //��ÿ�ΰ����
		Pc_mv, mvM = 0; //�����ÿ�ΰ����
	char key = 'Y';     //��Ϊ�û��Ƿ��������Ϸ�ı��
	cin >> n >> k;

	srand((unsigned)time(NULL));    

	while (!(key == 'N' || key == 'n'))
	{
		cntSum++;
		mvM = 0;
		for (i = 0; ; i++)
		{
			while (1)
			{
				cin >> I_mv;
				if (I_mv > k)
					cout << "�㲻�ܰ���ô�࣬ÿ������Ϊ" << k << "��ɽ�������°�" << endl;
				else if (n - mvM - I_mv > 0) break;
				     else cout << "���ɽ���������ܳ���" << k << "���������°�" << endl;
			}
				
			mvM += I_mv;
			if (n - mvM == 1)
			{
				cout << "��Ӯ�ˣ�" << endl;
				cntIWin++;
				break;
			}
			
			do							//��ֹ�������ɽ������һ���ӳ�����ʣ����
			{
				Pc_mv = rand() % k;
			} while (n - mvM - Pc_mv <= 0);
			
			//�жϼ����������Ƿ��ʣ��һ��
			mvM += Pc_mv;
			cout << "���������" << Pc_mv << "��ɽ��Ŀǰ��ʣ��" << n - mvM << "����" << endl;
			if (n - mvM == 1)
			{
				cout << "�����Ӯ�ˣ�" << endl;
				cntPcWin++;
				break;
			}
		}

		cout << "�Ƿ������Ϸ��";
		cin >> key;
	}

	cout << "һ������" << cntSum << "�֣���Ӯ��" << cntIWin << "��" << endl;
	getchar();
	getchar();
	return 0;
}
/*7���ж�Ԫ���Ƿ���ڣ���Ϣѧ����һ��ͨ-T1211��*/

//˼·������k��M�е�Ԫ�أ���ô2k+1��2k+3Ҳ��M�е�Ԫ�أ���ô2(2k+1)+1��2(3k+1)+1Ҳ��M�е�Ԫ��....����ֻ���ж�x�ܷ��ú�k����������Ǳ�� 
//�����һԪ��K��k��������Ԫ��Ϊ2K+1��3k+1,k��������Ԫ��Ϊ(k-1)/2��(k-1)/3 
/*
#include<iostream>
using namespace std;
int x;
int f(int k);
int main()
{
	int k,x;
	cin>>k>>x;
	if(f(k)) cout<<f(k)<<"Yes"<<endl;
	else cout<<"No"<<endl; 
	return 0;
 } 

//x>k
int f(int k){
	//cout<<k<<endl; 
	if(k==x&&k>0) return 1;
	if(k<x&&x<100000)
	{
		f(2*k+1);
		f(3*k+1);
	}
	if(k>x&&k>0)
	{
		return f((k-1)/2)||f((k-1)/3);
	}	
	return 0;
		
}*/

//����K��Ԫ�ؼ��ϱ߽粻���ң���x�ĽǶ�����
#include<iostream>
using namespace std;
int x,k;
int f(int k);
int main()
{
	cin>>k>>x;
	if(f(x)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl; 
	return 0;
 } 


int f(int x){
	//cout<<x<<endl;
	int sum=0; 
	if(x==k) return 1;
	if(x>k&&x>0)
	{
		if((x-1)%2==0)
		{
			sum+= f((x-1)/2); //���ܷ�����ô�磬Ҫ�����еĶ�������ſ��Եģ���Ȼһֱ��������ֱ��������������ʱ��ͷ���0�� 
			if(sum!=0) return 1;
		}
		 
		if((x-1)%3==0)
		{
			sum+=f((x-1)/3);
			if(sum!=0)return 1; 
		}
	}
	if(x<k)
	{
		if(x<=(k-1)/2)
		{
			sum+=f(2*x+1);
			if(sum!=0) return 1;
		}
		if(x<=(k-1)/3)
		{
			sum+=f(3*x+1);
			if(sum!=0) return 1;
		}	
	}	
	return 0;
}

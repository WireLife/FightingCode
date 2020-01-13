#include<iostream>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int *a=new int[k+1];
	int *b=new int[k+1];
	for(int i=1;i<=k;i++)
		cin>>a[i]>>b[i];
	int home=n-k;//n-k*2+k计算得知家庭数在n，k确定后为常数
	int people=2;//people_max>=2
	for(i=1;i<k;i++)
		for(int j=i+1;j<=k;j++)
			if(a[i]==a[j]||b[i]==b[j])
				people++;
	cout<<home<<' '<<people<<endl;
	delete []a;
	delete []b;
	return 0;
}

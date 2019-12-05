/*6、分数求和（信息学奥赛一本通-T1209） */
//思路：定义一个二位数组分别存放分子和分母，然后先算前两个分数的和,用枪两个分数的和和后面的分数相加。
//两个分数相加，看分母，首先求出两个分母的公倍数，然后都化为同分母的分数，两分数相加后在化简。因为这题最多只有10个分数相加，公倍数就直接两个分母相乘  
//会溢出， 
 
#include<iostream>
#include<cmath> 
using namespace std;
const int maxn = 10;
int fenzi=0,fenmu=1,n,a[maxn][2];
//把所有的分数相加，不化简 
void d(int i);
//求两个数的最大公因数 
int max_ele(int a,int b);
int main(){
	char c;  //c是把中间的除号吞掉 
	int i;
	cin>>n;
	
	for(i=0;i<n;i++)
		cin>>a[i][0]>>c>>a[i][1];
	//cout<<a[0][0]<<c<<a[0][1]<<endl;
	d(0);

	int t;  	//分子分母的最大公因数 
	if(fenzi==0) cout<<0<<endl;  
	else{
		t=abs((abs(fenzi)>=fenmu)?max_ele(abs(fenzi),fenmu):max_ele(abs(fenmu),fenzi)); //求两个数的最大公因数并确保两个数都大于0
		//把分子分母化为最简
		if(fenmu/t==1) cout<<fenzi/t<<endl; //如果分母为1的话就直接输出分子 
		else cout<<fenzi/t<<'/'<<fenmu/t<<endl; 
	} 	
	return 0;	 
}
void d(int i){
	if(i<n){
		int comber = fenmu*a[i][1];
		fenzi=fenzi*(comber/fenmu)+a[i][0]*(comber/a[i][1]);  //当两分数分分母相同时分子相加。 
		fenmu=comber;
		d(i+1);
	}	
}
 
int max_ele(int a,int b){
	int t1;
	while(1&&b!=0){
	  t1=a%b;
	  if(t1==0) return b; 
		else{
		  a=b;
		  b=t1;
		}
	}
}


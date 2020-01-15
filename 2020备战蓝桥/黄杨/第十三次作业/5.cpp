//5.奇怪的电梯
//借鉴加以修改完成
#include<iostream>
#include<queue>
using namespace std;
typedef struct
{
	int step;
	int floor;
}dt;
queue<dt> lift;//定义队列 
bool flag[2000],f;
int main()
{
	int n,a,b,k[2000];//k【i】表示第i层可以上升/下降多少楼 
	dt s,e;//定义了dt类型的s,e两个数，表示起点层，终点层 
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
	}
	//初始化，来到第a楼 
	s.step =0;
	s.floor =a;
	lift.push(s);//这楼入队 
	//当可行的方案没实行完，也就是队列不为空时，广搜 
	while(!lift.empty())
	{
		s=lift.front();//每次来到新楼层了把起点更新 
		lift.pop() ;//走过的楼层（处理过的可能性）可以出队了 
		if(s.floor ==b)//走到了规定楼层 
		{
			cout<<s.step<<endl;
			f=1;
			break;
		}
		//上升的情况 
		if(s.floor +k[s.floor]<=n && !flag[s.floor+k[s.floor]])//如果楼层在范围内且没被走过 
		{
			e.floor =s.floor+k[s.floor];
			e.step =s.step +1;
			flag[e.floor]=1;
			lift.push(e); 
		}
		//下降的情况 
		if(s.floor -k[s.floor]>=1 && !flag[s.floor-k[s.floor]])
		{
			e.floor =s.floor-k[s.floor];
			e.step =s.step +1;
			flag[e.floor]=1;
			lift.push(e); 
		}
	}
	if(f==0)	
		cout<<"-1"<<endl; 
	return 0;
} 

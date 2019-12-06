
#include<stdio.h>
int ping(int m,int n){
    if(m==0||n==1) return 1;
    if(m<n) return ping(m,m);
    else 
		return ping(m,n-1)+ping(m-n,n);
}

int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        printf("%d\n",ping
			(m,n));
    }
    return 0;
}

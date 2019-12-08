#include<stdio.h>
#include<string.h>
int main(){
	int N,n,k,t,i,j,m;
	char a[10005];
	int b[10005]={0};
	scanf("%d",&N);
	while(N--){
		scanf("%s",&a);
		n=strlen(a);
		for(i=0;i<n;i++)
			b[i]=0;
		k=0;
		t=1;
		m=0;
		for(i=n-1;i>=0;i--){
	    	b[k]+=(a[i]-'0')*t;
			t*=2;
			m++;
			if(m%4==0){
				k++;
				t=1;
			}
		}
		for(i=0;i<n;i++){
			if(b[i]>=10){
				switch(b[i]){
				case 10 : b[i]='A'; break;
				case 11 : b[i]='B'; break;
				case 12 : b[i]='C'; break;
				case 13 : b[i]='D'; break;
				case 14 : b[i]='E'; break;
				case 15 : b[i]='F'; break;
				}
			}
		}
		for(i=k;i>=0;i--){
			if(b[i]!=0){
				for(j=i;j>=0;j--){
			if(b[j]>=65 && b[j]<=70 )
				printf("%c",b[j]);
			else printf("%d",b[j]);
				}
				break;
			}
		}
			if(i==-1) printf("0");
		printf("\n");
	}
}

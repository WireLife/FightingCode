#include<stdio.h>      

int a[100]={0},b[10]={0};
int n;   

void select(int weight,int size) 
{      
    if(size != n )
	{      
        if(weight == 0)						
		{				      						    
            for(int i = 0; i < n; i++) 
				printf("%d ",b[i]);      
            printf("\n");      
        }      
        else 
		{     
           	select(weight,size + 1);		     
            if(weight - a[size] >= 0)		
			{				      
                b[size]++;					 
                select(weight - a[size],size);     
                b[size]--;					      
            }             
		}    
	}        
}      
int main() 
{ 
	int i,j,T;  
	scanf("%d%d",&n,&T);      
    for(i = 0; i < n; i++)   
		scanf("%d",&a[i]);         
    select(T,0);           
	return 0;    
} 

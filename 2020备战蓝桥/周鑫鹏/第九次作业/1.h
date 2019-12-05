int Pell(int n)
{
	int a;
	if(n==1)
		a=1;
	else
		if(n==2)
			a=2;
		else
			a=2*Pell(n-1)+Pell(n-2);
		return a;
}



#include <stdio.h>
int main ()
{
	int n, i, flag=0;
	printf("Enter Your Number:\n");
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		if(n%i==0)
		{
			flag++; 
		}
	} 
	if (flag>=2)
		printf("%d,the number is not prime.\n",n);
	else 
	    printf("%d,the number is prime.\n",n);
	return 0;
}
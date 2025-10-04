#include<stdio.h>
int main()
{
	int numb;
	printf("Enter your number:\n");
	scanf("%d",&numb);
	if (numb>0)
	{
		printf("%d the given number is positive.\n",numb);
    }
    else if (numb==0)
    {
    	printf("%d the given number is zero.\n",numb);
    }
    else
    	printf("%d the given number is negative.\n",numb);
    return 0;

}
/*
Program to find n^p with out using pow function.
written by Raja Das ( Roll 52 )
*/

#include<stdio.h>

int calculate(int n,int pow){
	if(pow == 0)
		return 1;
	else if(pow == 1)
		return n;

	int x = calculate(n,pow/2);
	if(pow % 2 == 0)
		return x * x;

	return x * x * n;
}

int main(){
	int n,pow;
	printf("Enter number and power: ");
	scanf("%d %d",&n,&pow);
	if(pow < 0){
		printf("Power has to be >= 0\n");
		return 0;
	}
	int ans = calculate(n,pow);
	printf("%d^%d = %d\n",n,pow,ans);
	return 0;
}
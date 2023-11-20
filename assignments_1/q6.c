/*
Program to GCD of two number using factorization and euclid method.
written by Raja Das ( Roll 52 )
*/

#include<stdio.h>

int gcd_fact(int a,int b){
	int min = a < b ? a : b;
	int i;
	for(i=min;i>=1;i--){
		if(a % i == 0 && b % i == 0)
			return i;
	}
	return 1;
}

int gcd_euclid(int a,int b){
	if(b == 0)
		return a;
	return gcd_euclid(b,a%b);
}

int main(){
	int a,b;
	printf("Enter two number: ");
	scanf("%d %d",&a,&b);
	printf("GCD of %d and %d (Factorization method): %d\n",a,b,gcd_fact(a,b));
	printf("GCD of %d and %d (Euclid method): %d\n",a,b,gcd_euclid(a,b));
	return 0;
}
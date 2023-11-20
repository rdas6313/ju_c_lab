/*
Program to Generate prime till n. (use -lm option with gcc to link math library.)
written by Raja Das ( Roll 52 )
It can generate prime till 10^6.
*/
#include<stdio.h>
#include<math.h>
#define MAX 1000000
int prime[MAX];
void generate_prime(){
	int i,j;
	for(i = 0; i < MAX; i++)
		prime[i] = 1;
	int n = sqrt(MAX);
	for(i = 2;i < n; i++){
		if(prime[i]){
			for(j = i*i; j< MAX ;j += i)
				prime[j] = 0;
		}
	}
}
int main(){
	generate_prime();
	printf("How many prime number you want to generate: ");
	int n;
	scanf("%d",&n);
	int i;
	printf("Prime numbers till %d are: ",n);
	for(i=1;i<=n;i++)
		if(prime[i])
			printf("%d ",i);
	printf("\n");
	return 0;
}
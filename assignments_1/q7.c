/*
Program to LCM of n numbers
written by Raja Das ( Roll 52 )
*/

#include<stdio.h>
#include<math.h>
#define MAX 100000

int prime[MAX];
int fact[MAX];

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

void prime_factorization(int n){
	int i;
	int sqr = sqrt(n);
	//printf("For %d: .....",n);
	
	for(i=2;i<=sqr;i++){
		if(prime[i] && (n % i) == 0){
			int p = 0;
			while(n % i == 0){
				p++;
				n = (n/i);
			}
			fact[i] = fact[i] < p ? p : fact[i];
			//printf("%d pow-> %d\n",i,p);
		}
	}
	if(n > 1){
		fact[n] = fact[n] < 1 ? 1 : fact[n];
	}
}


int main(){

	int a,b,n,i;
	
	for(i=0;i<MAX;i++)
		fact[i] = 0;
	generate_prime();

	printf("How many numbers lcm you want to compute: ");
	scanf("%d",&n);
	printf("Enter your numbers: ");
	int x;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		prime_factorization(x);
	}
	
	int ans = 1;
	for(i=2;i<MAX;i++)
		ans *= (pow(i,fact[i]));
	printf("LCM of %d numbers: %d\n",n,ans);
	
	return 0;
}
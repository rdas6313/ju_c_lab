/*
Program to compute nth fibonacci number with formula and without formula.
written by Raja Das ( Roll 52 )
*/
#include<stdio.h>
#include<math.h>
int main(){
	printf("Enter value of n (for nth fibonacci number): ");
	int n;
	scanf("%d",&n);
	int i;
	double ans = 0;
	if(n == 0)
		ans = 0;
	else if(n == 1)
		ans = 1;
	else if(n > 1){
		double prev = 0,new_ans;
		ans = 1;
		for(i=2;i<=n;i++){
			new_ans = ans + prev;
			prev = ans;
			ans = new_ans;
		}

	}
	printf("%d th fibonacci number (without formula): %.0lf\n",n,ans);
	double sqr = sqrt(5);
	double f1 = (1+sqr)/2;
	double f2 = (1-sqr)/2;
	ans = (1/sqr)*(pow(f1,n)-pow(f2,n));
	printf("%d th fibonacci number (with formula): %.0lf\n",n,ans);
	return 0;
}

// 0 1 1 2 3 5 8 13 21....
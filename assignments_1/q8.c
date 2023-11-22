/*
Program to calculate sinx,cosx,log(1+x) expansion and series sum calculation
written by Raja Das ( Roll 52 )
*/
#include<stdio.h>

int main(){
	// program A.
	int i;
	double fact = 1;
	double ans = 0;
	for(i=1;i<=10;i++){
		fact *= i;
		ans += ((double)i/fact);
	}
	printf("A.> 1/1! + 2/2! + 3/3! + ... upto 10 terms: %.4lf\n",ans);
	printf("\n");
	// program B.
	double x;
	int n;
	printf("B.> Value of x in sine(x) series(in degree): ");
	scanf("%lf",&x);
	printf("B.> No of step want to expand the series: ");
	scanf("%d",&n);
	double deg = x;
	x = x * (3.14159/180);
	double rad = x;
	double pow = x;
	ans = x;
	fact = 1;
	int sign = 1;
	int term;
	for(i = 3,term = 2;term <= n;i += 2,term++){
		fact *= i*(i-1);
		pow *= (x*x);
		sign *= (-1);
		ans += ((pow/fact)*sign);

	}
	//printf("B.> %.2lf degree in radian: %lf\n",deg,rad);
	printf("B.> Sine(%.2lf): %.2lf\n",deg,ans);

	printf("\n");

	//Program c.
	printf("C.> Value of x in cos(x) series(in degree): ");
	scanf("%lf",&x);
	printf("C.> No of step want to expand the series: ");
	scanf("%d",&n);
	deg = x;
	ans = 1;
	sign = 1;
	pow = 1;
	fact = 1;
	x = x * (3.14159/180);
	for(i=2,term=2;term <= n;i+=2,term++){
		pow *= (x * x);
		fact *= (i * (i - 1));
		sign *= (-1);
		ans += (pow/fact) * sign;
	}

	printf("C.> Cos(%.2lf): %.2lf\n",deg,ans);

	printf("\n");

	//Program d.
	printf("D.> Value of x in log(1+x) series(|x| < 1): ");
	scanf("%lf",&x);
	printf("D.> No of step want to expand the series: ");
	scanf("%d",&n);

	ans = 0;
	sign = -1;
	pow = 1;
	for(i=1;i<=n;i++){
		pow *= x;
		sign *= (-1);
		ans += (pow/i) * sign;
	}
	printf("D.> log(1+%.2lf): %.2lf\n",x,ans);
	return 0;
}
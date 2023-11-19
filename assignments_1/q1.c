/*
Program to convert any centigrade temperature value to Fahrenheit and vice-versa.
written by Raja Das ( Roll 52 )
*/
#include<stdio.h>

void cen_to_fah(){
	printf("\n....Centigrade to fahrenheit converter....\n");
	printf("Temparature in Celsius: ");
	double deg;
	scanf("%lf",&deg);
	double ans = deg * ((double)9/5) + 32;
	printf("\nTemparature in Fahrenheit: %.1lf\n",ans);

}

void fah_to_cen(){
	printf("\n....Fahrenheit to centigrade converter....\n");
	printf("Temparature in Fahrenheit: ");
	double deg;
	scanf("%lf",&deg);
	double ans = (deg-32) * ((double)5/9);
	printf("\nTemparature in Centigrade: %.1lf\n",ans);

}

int main(){
	printf("............Temprature converter..........\n");
	printf("1. Centigrade to fahrenheit\n");
	printf("2. Fahrenheit to centigrade\n");
	printf("Choose: ");
	int option;
	scanf("%d",&option);
	switch(option){
	case 1:
		cen_to_fah();
		break;
	case 2:
		fah_to_cen();
		break;
	default:
		printf("\nInvalid option\n");
	}
	return 0;
}
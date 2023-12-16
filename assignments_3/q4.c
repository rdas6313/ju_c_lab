#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int day,month,year;
} Date;

int isEqual(Date *d1,Date *d2){
	if(d1->day == d2->day && d1->month == d2->month && d1->year == d2->year)
		return 1;
	return 0;
}

void error_checker(Date *d){
	if(d->day < 1 || d->day > 31){
		printf("Error: dd part is invalid.\n");
		exit(0);
	}else if(d->month < 1 || d->month > 12){
		printf("Error: mm part is invalid.\n");
		exit(0);
	}else if(d->year < 1){
		printf("Error: yyyy part is invalid.\n");
		exit(0);
	}
}

int main(){
	Date d1,d2;
	printf("Date 1 (dd/mm/yyyy): ");
	scanf("%d/%d/%d",&d1.day,&d1.month,&d1.year);
	error_checker(&d1);
	printf("Date 2 (dd/mm/yyyy): ");
	scanf("%d/%d/%d",&d2.day,&d2.month,&d2.year);
	error_checker(&d2);
	if(isEqual(&d1,&d2))
		printf("Equal\n");
	else
		printf("Unequal\n");
	
	return 0;
}
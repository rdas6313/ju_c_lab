#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int hour,min,sec,day;
} time;

time time_add(time *t1,time *t2){
	time res;
	res.sec = (t1->sec + t2->sec) % 60;
	int carry = (t1->sec + t2->sec) / 60;
	res.min = (t1->min + t2->min + carry) % 60;
	carry = (t1->min + t2->min + carry) / 60;
	res.hour = (t1->hour + t2->hour + carry) % 24;
	res.day =  (t1->hour + t2->hour + carry) / 24;
	return res;
}

void error_checker(time *t){
	if(t->hour < 0 || t->hour > 23){
		printf("Error: Hour part is invalid.\n");
		exit(0);
	}else if(t->min < 0 || t->min > 59){
		printf("Error: min part is invalid.\n");
		exit(0);
	}else if(t->sec < 0 || t->sec > 59){
		printf("Error: sec part is invalid.\n");
		exit(0);
	}
}

int main(){
	time t1,t2;
	printf("Time 1 (hh:mm:ss) : ");
	scanf("%d:%d:%d",&t1.hour,&t1.min,&t1.sec);
	error_checker(&t1);
	printf("Time 2 (hh:mm:ss) : ");
	scanf("%d:%d:%d",&t2.hour,&t2.min,&t2.sec);
	error_checker(&t2);
	time res = time_add(&t1,&t2);
	printf("Result of addition: %d day %d:%d:%d\n",res.day,res.hour,res.min,res.sec);
	return 0;
}
#include<stdio.h>
int main(){
	printf("How many number you want to enter: ");
	int n;
	scanf("%d",&n);
	printf("Enter elements of array: ");
	int i,x,j,max = -1000000000, min = 1000000000;	
	for(i=0;i<n;i++){
		scanf("%d",&x);
		max = max < x ? x : max;
		min = min > x ? x : min;
	}
	
	printf("Maximum number: %d\n",max);
	printf("Minimum number: %d\n",min);
	
	return 0;
}

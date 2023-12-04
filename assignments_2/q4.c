#include<stdio.h>
int main(){
	printf("How many number you want to enter: ");
	int n;
	scanf("%d",&n);
	printf("Enter elements of array: ");
	int i,a[n],j;	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int tmp = a[n-1];
	for(i=n-1;i>0;i--){
		a[i] = a[i-1];
	}
	a[0] = tmp;
	printf("Array: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}

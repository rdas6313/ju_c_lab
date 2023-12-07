#include<stdio.h>
#include<string.h>
#define MAX 1000000
int main(){
	int a[MAX];
	printf("Number of elements: ");
	int n,i;
	scanf("%d",&n);
	printf("Enter sorted array: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Element you want to insert: ");
	int ele;
	scanf("%d",&ele);
	int mark = n;
	for(i=0;i<n;i++){
		if(a[i] > ele){
			mark = i;
			break;
		}
	}

	for(i=n;i>mark;i--){
		a[i] = a[i-1];
	}
	a[mark] = ele;
	printf("Sorted array: ");
	for(i=0;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
	
	return 0;
}
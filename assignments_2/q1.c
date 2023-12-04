#include<stdio.h>
int main(){
	printf("How many number you want to enter: ");
	int n;
	scanf("%d",&n);
	printf("Enter elements of array: ");
	int i,a[n],j;	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++){
		
		for(j=i+1;j<n;j++){
			if(a[i] < a[j]){
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;			
			}
		}
		
	}
	printf("Decending sorted array: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}

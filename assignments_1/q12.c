#include<stdio.h>
int main(){
	int n1,n2,i,j,k;
	printf("Number of Item in sorted list 1: ");
	scanf("%d",&n1);
	int a[n1];
	printf("Enter sorted list 1: ");
	for(i=0;i<n1;i++)
		scanf("%d",&a[i]);

	printf("Number of Item in sorted list 2: ");
	scanf("%d",&n2);
	int b[n2];
	printf("Enter sorted list 1: ");
	for(i=0;i<n2;i++)
		scanf("%d",&b[i]);
	
	int c[n1+n2];
	i = 0,j = 0,k = 0;
	while(i<n1 && j<n2){
		if(a[i] == b[j]){
			c[k++] = a[i];
			i++;
			j++;
		}else if(a[i] < b[j]){
			c[k++] = a[i];
			i++;
		}else{
			c[k++] = b[j];
			j++;
		}
	}
	while(j < n2)
		c[k++] = b[j++];
	while(i < n1)
		c[k++] = a[i++];
	printf("Union of two sorted list: ");
	for(i=0;i<k;i++)
		printf("%d ",c[i]);
	printf("\n");
	return 0;
}
#include<stdio.h>
int main(){
	printf("How many number: ");
	int n;
	scanf("%d",&n);
	printf("Enter elements: ");
	int i,x,a[n];	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter search element: ");
	scanf("%d",&x);
	int index = -1;
	for(i=0;i<n;i++)
		if(a[i] == x){
			index = i;
			break;
		}
	if(index != -1)
		printf("Found! Index: %d\n",index);
	else
		printf("Not Found");
	return 0;
}

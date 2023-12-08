#include<stdio.h>
void sort(int a[],int n){
	int i,j,min;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i] > a[j]){
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

int main(){
	printf("No of row and colums: ");
	int i,j,r,c;
	scanf("%d %d",&r,&c);
	int a[r*c],b[r*c],x,k;
	printf("Enter matrix 1: \n");
	for(i=0,k=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&x);
			a[k++] = x;
		}
	}

	printf("Enter matrix 2: \n");
	for(i=0,k=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&x);
			b[k++] = x;
		}
	}

	sort(a,r*c);
	sort(b,r*c);

	printf("Sum of two sorted matrix: \n");
	for(i=0,k=0;i<r;i++){
		for(j=0;j<c;j++,k++){
			printf("%d ",a[k]+b[k]);		
		}
		printf("\n");
	}
	printf("\n");
	

	return 0;
}
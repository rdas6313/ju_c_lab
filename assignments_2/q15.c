#include<stdio.h>
int main(){
	int i,n=10,j;
	int a[2][n];
	printf("Pascal's triangle (upto 10 lines): \n");
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			
			if(j == 0 || j == i)
				a[1][j] = 1;
			else{
				a[1][j] = a[0][j] + a[0][j-1];

			}
		}
		for(j=0;j<=i;j++){
			printf("%d ",a[1][j]);
			a[0][j] = a[1][j];
		}
		printf("\n");
	}

	return 0;
}
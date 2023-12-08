#include<stdio.h>
int main(){
	printf("No of row and colums of matrix 1: ");
	int i,j,r1,c1,r2,c2;
	scanf("%d %d",&r1,&c1);
	int a[r1][c1];
	printf("Enter matrix: \n");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("No of row and colums of matrix 2: ");
	scanf("%d %d",&r2,&c2);
	int b[r2][c2];
	printf("Enter matrix: \n");
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			scanf("%d",&b[i][j]);
		}
	}

	int k,res[r1][c2];
	for(i=0;i<r1;i++){
		for(k=0;k<c2;k++){
			res[i][k] = 0;
			for(j=0;j<c1;j++){
				res[i][k] += a[i][j] * b[j][k];
			}
		}
	}

	printf("Resultant matrix: \n");
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			printf("%d ",res[i][j]);		
		}
		printf("\n");
	}
	printf("\n");

	
	return 0;
}
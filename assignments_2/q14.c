#include<stdio.h>
int main(){
	printf("No of row and colums: ");
	int i,j,r,c;
	scanf("%d %d",&r,&c);
	int a[r][c],b[c][r];
	printf("Enter matrix: \n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&a[i][j]);
			b[j][i] = a[i][j];
		}
	}
	printf("Tranpose of matrix: \n");
	for(i=0;i<c;i++){
		for(j=0;j<r;j++){
			printf("%d ",b[i][j]);		
		}
		printf("\n");
	}
	printf("\n");

	int k,res[r][r];
	for(i=0;i<r;i++){
		for(k=0;k<r;k++){
			res[i][k] = 0;
			for(j=0;j<c;j++){
				res[i][k] += a[i][j] * b[j][k];
			}
		}
	}

	printf("Resultant matrix(Original matrix * Tranpose matrix): \n");
	for(i=0;i<r;i++){
		for(j=0;j<r;j++){
			printf("%d ",res[i][j]);		
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
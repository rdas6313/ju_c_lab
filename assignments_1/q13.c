/*
Program to find (M^P)R.
written by Raja Das ( Roll 52 )
*/
#include<stdio.h>
int main(){
	printf("Enter square matrix (nxn) size: ");
	int n;
	scanf("%d",&n);
	int i,j;
	double a[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j] = (double)1/n;

	// for(i=0;i<n;i++){
	// 	for(j=0;j<n;j++)
	// 		printf("%lf ",a[i][j]);
	// 	printf("\n");
	// }

	double b[n][1];
	for(i=0;i<n;i++)
		b[i][0] = (double)1/n;

	printf("Enter matrix power p: ");
	int p;
	scanf("%d",&p);
	double res[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i == j)
				res[i][j] = 1;
			else
				res[i][j] = 0;

	int k;
	double tmp[n][n];
	while(p > 0){
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				tmp[i][j] = 0;
				for(k=0;k<n;k++)
					tmp[i][j] += (res[i][k] * a[k][j]);
			}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				res[i][j] = tmp[i][j];
		p--;
	}

	for(i=0;i<n;i++)
		for(j=0;j<1;j++){
			tmp[i][j] = 0;
			for(k=0;k<n;k++)
				tmp[i][j] += (res[i][k] * b[k][j]);
		}

	printf("Matrix R: \n");
	for(i=0;i<n;i++){
		for(j=0;j<1;j++)
			printf("%lf ",b[i][j]);
		printf("\n");
	}
	printf("\nMatrix (M^p)R: \n");
	for(i=0;i<n;i++){
		for(j=0;j<1;j++)
			printf("%lf ",tmp[i][j]);
		printf("\n");
	}
	return 0;
}
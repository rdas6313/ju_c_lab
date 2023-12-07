#include<stdio.h>
#include<math.h>
int main(){
	printf("Number of rows and colums of matrix: ");
	int r,c;
	scanf("%d %d",&r,&c);
	printf("Enter your matrix: \n");
	int i,j,x,sum = 0;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++){
			scanf("%d",&x);
			sum += (x * x);
		}
	printf("Norm of matrix: %.2lf\n",sqrt(sum));
	return 0;
}
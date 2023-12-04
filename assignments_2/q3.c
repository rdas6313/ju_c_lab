#include<stdio.h>
#include<math.h>
#define MAX 1000000
int main(){
	printf("How many number you want to enter: ");
	int n;
	scanf("%d",&n);
	printf("Enter elements of array: ");
	int i,a[n],j,freq[MAX];	
	int sum = 0;
	for(i=0;i<MAX;i++)
		freq[i] = 0;	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum += a[i];
		freq[a[i]]++;	
	}
	double mean = (double)sum/n;
	int max = 0,mode;	
	for(i=0;i<MAX;i++)
		if(max < freq[i]){
			max = freq[i];
			mode = i;		
		}

	printf("Mean: %lf\n",mean);
	printf("Mode: %d\n",mode);
	double s = 0;	
	for(i=0;i<n;i++){
		double tmp = a[i]-mean;
		s += (tmp * tmp);	
	}
	
	
	s = s/(n-1);
	s = sqrt(s);
	
	printf("Standard deviation: %lf\n",s);
	return 0;
}
//mean,mode,standard deviation

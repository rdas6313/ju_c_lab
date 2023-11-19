/*
Program to find X where the sum of the room numbers left to X is equal to the sum of the room
numbers to the right of X. Total Room number is given as input.
written by Raja Das ( Roll 52 )
*/
#include<stdio.h>
int main(){
	printf("Total rooms: ");
	int total_rooms;
	scanf("%d",&total_rooms);
	int start = 1;
	int end = total_rooms;
	long long int sum = (total_rooms * ((long long)total_rooms + 1))/2;
	while(start <= end){
		int x =	(start+end)/2;
		long long int sumx = (x * ((long long)x+1))/2;
		
		if(2 * sumx == sum){
			printf("Room no X is: %d\n",x);
			return 0;	
		}else if(sumx < (sum-sumx)){
			start = x + 1;
		}else
			end = x - 1;
		
	}
	printf("No Room x found for given total room %d\n",total_rooms);
	return 0;
}
/*
Program to find X where the sum of the room numbers left to X is equal to the sum of the room
numbers to the right of X. Total Room number is given as input. (use -lm option with gcc to link math library.)
written by Raja Das ( Roll 52 )
*/
#include<stdio.h>
#include<math.h>
int main(){
	printf("Total rooms: ");
	int total_rooms;
	scanf("%d",&total_rooms);
	int tmp = (total_rooms*(total_rooms+1))/2;
	int ans = sqrt(tmp);
	if(ans * ans == tmp){
		printf("Room x is: %d\n",ans);
		return 0;
	}
	printf("No Room x found for given total room %d\n",total_rooms);
	return 0;
}
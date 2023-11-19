/*
Program to find minimum no of notes required to pay the amount.
written by Raja Das ( Roll 52 )
*/
#include<stdio.h>
int main(){
	int notes[] = {100,50,20,10};
	int amount;
	printf("Enter amount: ");
	scanf("%d",&amount);
	int i, ans = 0;
	for(i=0;i<4;i++){
		if(amount/notes[i] == 0)
			continue;
		int no_of_notes = amount / notes[i];
		amount = amount % notes[i];
		printf("%d notes of Rs %d\n",no_of_notes,notes[i]);
		ans += no_of_notes;
	}
	printf("Minimum no of notes required: %d\n",ans);
	return 0;
}
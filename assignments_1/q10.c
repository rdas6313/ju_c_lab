/*
Program to check if a number is palidrome or not and reverse that number.
written by Raja Das ( Roll 52 )
It can take input 10^5 digit number.
*/
#include<stdio.h>
#include<string.h>
#define MAX 100000
int main(){
	char number[MAX];
	printf("Enter number: ");
	scanf("%s",number);
	int i,j;
	int len = strlen(number);
	int is_palindrome = 1;
	for(i=0,j=len-1;i<=j;i++,j--){
		if(number[i] != number[j]){
			is_palindrome = 0;
			break;
		}
	}
	printf("Reverse of the given number: ");
	for(j=len-1;j>=0;j--)
		printf("%c",number[j]);
	printf("\n");
	printf("Is it a palindrome number: %s\n",(is_palindrome ? "YES": "NO"));
	return 0;
}
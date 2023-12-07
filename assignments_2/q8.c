#include<stdio.h>
#include<string.h>
#define MAX 1000000
int main(){
	char s[MAX];
	printf("Enter input string: ");
	scanf("%s",s);
	int i,v = 0,c = 0,j;
	int len = strlen(s);
	int is_palindrome = 1;
	for(i=0,j=len-1;i<j;i++,j--){
		if(s[i] != s[j])
			is_palindrome = 0;
		char tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
	printf("Reverse string: %s\n",s);
	printf("Is it palindrome: ");
	if(is_palindrome)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
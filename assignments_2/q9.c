#include<stdio.h>
#include<string.h>
#define MAX 1000000
int main(){
	char s[MAX];
	printf("Enter line of text: ");
	scanf("%[^\n]",s);
	int i,v = 0,c = 0;
	int len = strlen(s);
	for(i=0;i<len;i++){
		if(s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
	}
	printf("Converted line of text: %s\n",s);
	
	return 0;
}
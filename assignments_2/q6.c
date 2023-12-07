#include<stdio.h>
#include<string.h>
#define MAX 1000000
int main(){
	char s[MAX];
	printf("Enter input string: ");
	scanf("%s",s);
	int i,v = 0,c = 0;
	int len = strlen(s);
	for(i=0;i<len;i++){
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;
		if(s[i] >= '0' && s[i] <= '9')
			continue;
		else if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			v++;
		else
			c++;
	}
	printf("No of vowel: %d\n",v);
	printf("No of consonants: %d\n",c);
	return 0;
}
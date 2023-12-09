#include<stdio.h>
#include<string.h>
#define MAX 1000000
int main(){
	char line[MAX];
	int i;
	printf("Enter string: ");
	scanf("%[^\n]",line);
	int len = strlen(line);
	int tmp;
	for(i=0;i<len;i++){
		if(line[i] >= 'a' && line[i] <='z'){
			line[i] -= 32;
		}
		else if(line[i] >= 'A' && line[i] <='Z'){
			line[i] += 32;
		}

	}
	printf("Changed string: %s\n",line);
	return 0;
}
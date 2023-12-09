#include<stdio.h>
#include<string.h>
#define MAX 1000000
int main(){
	char line[MAX];
	int i;
	printf("Enter line: ");
	scanf("%[^\n]",line);
	int len = strlen(line);
	int tmp;
	for(i=0;i<len;i++){
		if(line[i] >= 'a' && line[i] <='z'){
			tmp = line[i] - 'a';
			tmp = (tmp + 1) % 26;
			line[i] = 'a' + tmp;
		}
		else if(line[i] >= 'A' && line[i] <='Z'){
			tmp = line[i] - 'A';
			tmp = (tmp + 1) % 26;
			line[i] = 'A' + tmp;

		}
		else if(line[i] >= '0' && line[i] <= '9'){
			tmp = line[i] - '0';
			tmp = (tmp + 1) % 10;
			line[i] = '0' + tmp;
		}

	}
	printf("Encoded line: %s\n",line);
	return 0;
}
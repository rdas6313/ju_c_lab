#include<stdio.h>
#define MAX 1000000

int Strlen(const char *s){
	int i = 0;
	while(s[i] != '\0')
		i++;
	return i;
}

char* Strcat(char* dest,const char* src){
	int i = 0;
	while(dest[i] != '\0')
		i++;
	int j = 0;
	while((dest[i++] = src[j++]) != '\0');

	return dest;

}

char* Strcpy(char* dest,const char* src){
	int i = 0, j = 0;
	while((dest[i++] = src[j++]) != '\0');
	return dest;
}

char* Strrev(char* src){
	int i = 0;
	while(src[i] != '\0')
		i++;
	int j = i-1;
	i = 0;
	while(i < j){
		int tmp = src[i];
		src[i] = src[j];
		src[j] = tmp;
		i++;
		j--;
	}
	return src;
}

int Strcmp(const char* s1, const char* s2){
	int i = 0;
	while(s1[i] != '\0' && s2[i] != '\0'){
		if(s1[i] < s2[i])
			return -1;
		else if(s1[i] > s2[i])
			return 1;
		i++;
	}
	if(s1[i] == s2[i] && s1[i] == '\0')
		return 0;
	else if(s2[i] != '\0')
		return -1;
	return 1;
}

int main(){
	char line[MAX];
	char src[2*MAX] = "";
	int i;
	
	
	printf("\n1. Strlen\n");
	printf("2. Strcpy\n");
	printf("3. Strcat\n");
	printf("4. Strrev\n");
	printf("5. Strcmp\n");

	printf("Choose: ");
	int n;
	scanf("%d",&n);
	switch(n){
		case 1:
			printf("Enter string: ");
			scanf("\n%[^\n]",line);
			printf("Length of string: %d\n",Strlen(line));
			break;
		case 2:
			printf("Enter string: ");
			scanf("\n%[^\n]",line);
			printf("Destination array before copy: %s\n",src);
			Strcpy(src,line);
			printf("Destination array after copy: %s\n",src);
			break;
		case 3:
			printf("Enter source string: ");
			scanf("\n%[^\n]",src);
			printf("Enter destination string: ");
			scanf("\n%[^\n]",line);
			Strcat(src,line);
			printf("Concated new string into source array: %s\n",src);
			break;
		case 4:
			printf("Enter string: ");
			scanf("\n%[^\n]",line);
			printf("Reversed string: %s\n",Strrev(line));
			break;
		case 5:
			printf("Enter first string: ");
			scanf("\n%[^\n]",src);
			printf("Enter second string: ");
			scanf("\n%[^\n]",line);
			printf("Compared Result: %d\n",Strcmp(src,line));

			break;
		default:
			printf("Invalid option!\n");
			break;

	}
	return 0;
}
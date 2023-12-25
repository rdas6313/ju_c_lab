#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
	if(argc != 3){
		printf("Invalid argument!");
		exit(0);
	}

	FILE *fp = fopen(argv[1],"r");
	FILE *output = fopen(argv[2],"w");
	if(fp == NULL){
		printf("unable to open file %s\n",argv[1]);
		exit(0);
	}
	if(output == NULL){
		printf("unable to open file %s\n",argv[2]);
		exit(0);
	}
	int line = 0, character = 0;
	while(!feof(fp)){
		char c = fgetc(fp);
		if(c == '\n' || c == EOF)
			line++;
		else
			character++;

	}
	char a[line][character/line];
	int i = 0,j=0,sum = 0;
	rewind(fp);
	char c;
	do{
		c = fgetc(fp);
		if(c == '\n' || c == EOF){
			fprintf(output,"Row %d Sum %d\n",i,sum);
			sum = 0;
			i++;
			j=0;
		}else{
			a[i][j++] = c;
			sum += c - '0';
			//printf("%d %d = %d\n",i,j-1,c-'0');
		}
	}while(c != EOF);

	printf("Binary matrix size: %d x %d\n",line,(character/line));
	fclose(output);
	fclose(fp);
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
	if(argc != 3){
		printf("Invalid argument!");
		exit(0);
	}

	FILE *fp = fopen(argv[1],"r");
	FILE *output = fopen(argv[2],"a");
	if(fp == NULL){
		printf("unable to open file %s\n",argv[1]);
		exit(0);
	}
	if(output == NULL){
		printf("unable to open file %s\n",argv[2]);
		exit(0);
	}

	fseek(output,0,SEEK_END);
	while(!feof(fp)){
		char c = fgetc(fp);
		if(c != EOF)
			fputc(c,output);
	}
	fclose(fp);
	fclose(output);
}
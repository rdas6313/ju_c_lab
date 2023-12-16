#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define THRESHOLD 1000
typedef struct 
{
	char number[10];
	char name[100];
	double balance;
	long long int pos;
} Account;


void print(char filename[],Account customers[],int len){
	FILE * output = fopen(filename,"w");
	if(output == NULL){
		printf("Unable to open %s file\n",filename);
		return;
	}
	int i;
	for(i=0;i<len;i++)
		if(customers[i].balance < 1000){
			fprintf(output,"%s %s %.2lf\n",customers[i].number,customers[i].name,customers[i].balance); 
		}
	fclose(output);
	return;
}

void deposit_withdraw(Account customers[],int len,FILE * input){
	int n,amount,i;
	char num[10];

	printf("\n1. Withdraw\n");
	printf("2. Deposit\n");
	printf("Choose: ");
	scanf("%d",&n);
	
	printf("Account no: ");
	scanf("%s",num);
	printf("Amount: ");
	scanf("%d",&amount);
	for(i=0;i<len;i++){
		if(strcmp(customers[i].number,num) == 0){
			if(n == 1){
				if(customers[i].balance < THRESHOLD){
					printf("Insufficent balance for withdrawal!\n");
					return;
				}
				customers[i].balance -= amount;
			}else{
				customers[i].balance += amount;
			}
		}
	}

	rewind(input);
	for(i=0;i<len;i++)
		fprintf(input,"%s %s %.2lf\n",customers[i].number,customers[i].name,customers[i].balance); 
	
}

int main(int argc,char* argv[]){
	if(argc != 3){
		printf("Invalid input arguments.\n");
		exit(0);
	}
	FILE *input;
	input = fopen(argv[1],"r+");
	if(input == NULL){
		printf("Unable to open %s file\n",argv[1]);
		exit(0);
	}
	

	Account customers[1000];
	int len = 0;
	while(!feof(input)){
		customers[len].pos = ftell(input);
		fscanf(input,"%s %s %lf\n",customers[len].number,customers[len].name,&customers[len].balance);
		len++;
	}

	printf("1. Print account number less than 1000\n");
	printf("2. Withdraw or deposit\n");
	printf("Choose: ");
	int n;
	scanf("%d",&n);
	switch(n){
		case 1:
			print(argv[2],customers,len);
			break;
		case 2:
			deposit_withdraw(customers,len,input);
			break;
		default:
			printf("Invalid choice.");

	}


	
	fclose(input);
	return 0;
}
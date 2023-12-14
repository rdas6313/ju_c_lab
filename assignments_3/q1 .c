#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
typedef struct {
	char name[100];
	int roll;
	int marks[5];
} student;

typedef struct{
	student stu;
	int total;
	double avg;
} student_data;

int get_total(int a[]){
	int i,total = 0;
	for(i=0;i<5;i++)
		total += a[i];
	return total;
}
int main(int argc,char* argv[]){
	if(argc != 3){
		printf("Invalid argument\n");
		exit(0);	
	}


	FILE *inputFile = fopen(argv[1],"r");
	if(inputFile == NULL){
		printf("Unable to open %s file\n",argv[1]);
		exit(0);
	}
	
	FILE *outputFile = fopen(argv[2],"w");
	if(outputFile == NULL){
		printf("Unable to open %s file\n",argv[2]);
		exit(0);
	}

	
	int i,j;
	student data[MAX],tmp;	
	int len = 0;	
	while(!feof(inputFile)){
		fscanf(inputFile,"%s %d %d %d %d %d %d\n",tmp.name,&tmp.roll,&tmp.marks[0],&tmp.marks[1],&tmp.marks[2],&tmp.marks[3],&tmp.marks[4]);
		data[len] = tmp;
		len++;			
	}
	
	fclose(inputFile);
	
	
		
	
	for(i = 0;i < len-1; i++){
		for(j = i+1; j < len; j++){
			int total_i = get_total(data[i].marks);
			int total_j = get_total(data[j].marks);
			//printf("Total i and j: %d %d\n",total_i,total_j);
			if(total_i < total_j){
				student tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;			
			}		
		}	
	}
	
	student_data tmp2;
	
	for(i=0;i<len;i++){
		tmp2.stu = data[i];
		tmp2.total = get_total(data[i].marks);
		tmp2.avg = (double)tmp2.total / 5;
		
		
	
		fprintf(outputFile,"%s %d ",tmp2.stu.name,tmp2.stu.roll);
		for(j=0;j<5;j++)
			fprintf(outputFile,"%d ",tmp2.stu.marks[j]);
		fprintf(outputFile,"%d %lf\n",tmp2.total,tmp2.avg);
	}
	fclose(outputFile);
	
	return 0;
}

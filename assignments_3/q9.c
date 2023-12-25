#include<stdio.h>
#include<stdlib.h>
#define DATA_FILE "data.bin"
typedef struct{
	int day,month,year;
} DOB;

typedef struct{
	char name[100];
	int roll;
	int marks;
	DOB date;

} Student;

void add_record(){
	FILE *fp = fopen(DATA_FILE,"ab");
	if(fp == NULL){
		printf("Error while opening data file\n");
		exit(0);
	}
	printf("\n");
	Student student;
	printf("Name: ");
	scanf("\n%[^\n]",student.name);
	printf("Roll: ");
	scanf("%d",&student.roll);
	printf("Marks: ");
	scanf("%d",&student.marks);
	printf("Date of birth(dd/mm/yyyy): ");
	scanf("%d/%d/%d",&student.date.day,&student.date.month,&student.date.year);

	int res = fwrite(&student,sizeof(Student),1,fp);
	if(res)
		printf("\nAdded Successfully!\n");
	else
		printf("\nError while adding record!\n");
	fclose(fp);
}

void display(){
	FILE *fp = fopen(DATA_FILE,"rb");
	if(fp == NULL){
		printf("Error while opening data file\n");
		exit(0);
	}
	printf("\n");
	Student student;
	while(fread(&student,sizeof(Student),1,fp)){
		printf("%s %d %d %d/%d/%d\n",student.name,student.roll,student.marks,student.date.day,student.date.month,student.date.year);
	}
	fclose(fp);
}

void delete(){
	FILE *fp = fopen(DATA_FILE,"rb");
	if(fp == NULL){
		printf("Error while opening data file\n");
		exit(0);
	}
	printf("\nRoll: ");
	int roll;
	scanf("%d",&roll);
	FILE *pointer = fopen("temp.bin","wb");
	if(pointer == NULL){
		printf("Error while opening temporary file\n");
		exit(0);
	}
	Student student;
	while(fread(&student,sizeof(Student),1,fp)){
		if(student.roll == roll)
			continue;
		fwrite(&student,sizeof(Student),1,pointer);
	}
	fclose(fp);	
	fclose(pointer);
	remove(DATA_FILE);
	int ret = rename("temp.bin",DATA_FILE);
	if(!ret)
		printf("\nSuccessfully deleted\n");
	else
		printf("\nunable to delete!\n");
	
}

void modify_marks(){
	FILE *fp = fopen(DATA_FILE,"rb+");
	if(fp == NULL){
		printf("Error while opening data file\n");
		exit(0);
	}
	Student student;
	while(fread(&student,sizeof(Student),1,fp)){
		if(student.marks > 40 && student.marks < 50){
			student.marks += 10;
			fseek(fp,-sizeof(Student),SEEK_CUR);
			fwrite(&student,sizeof(Student),1,fp);
		}
	}
	printf("\nMarks updated Successfully!\n");
	fclose(fp);
}

int main(int argc, char const *argv[]){
	
	int choice;
	do{
		printf("\n");
		printf("1. Add new record\n");
		printf("2. Display all records\n");
		printf("3. Delete a record\n");
		printf("4. Modify marks\n");
		printf("5. Exit\n");
		printf("Choose: ");
		
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				add_record();
				break;
			case 2:
				display();
				break;
			case 3:
				delete();
				break;
			case 4:
				modify_marks();
				break;
		}

	}while(choice < 5);

	
	return 0;
}
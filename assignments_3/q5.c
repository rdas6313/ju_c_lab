#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	long long int acces_no;
	char title[100];
	char author[100];
	double price;
	int is_issued;
} Library;

void add(FILE *fp){
	Library book;
	printf("\n");
	printf("Accession number: ");
	scanf("%lld",&book.acces_no);
	printf("Book title: ");
	scanf("\n%[^\n]",book.title);
	printf("Author name: ");
	scanf("\n%[^\n]",book.author);
	printf("Price: ");
	scanf("%lf",&book.price);
	printf("Is issued(Yes -> 1 and No -> 0): ");
	scanf("%d",&book.is_issued);

	int res = fwrite(&book,sizeof(Library),1,fp);
	if(res)
		printf("\nBook added successfully\n");
	else
		printf("\nError while adding book\n");

}


void display_books(FILE *fp){
	rewind(fp);
	Library book;
	printf("\n");
	while(fread(&book,sizeof(Library),1,fp)){
		printf("%lld %s %s %.2lf %s\n",book.acces_no,book.title,book.author,book.price,(book.is_issued ? "Issued" : "Not issued"));
	}
}

void strlwr(char *source,char *output){
	int n = strlen(source),i;
	for(i=0;i<n;i++)
		if(source[i] >='A' && source[i] <= 'Z')
			output[i] = source[i] + 32;
		else
			output[i] = source[i];
	output[n] = '\0';
	
}

void search_all_book_by_author(FILE *fp){
	rewind(fp);
	Library book;
	printf("\n");
	char name[100];
	printf("Author name: ");
	scanf("\n%[^\n]",name);
	printf("\n");
	strlwr(name,name);

	while(fread(&book,sizeof(Library),1,fp)){
		char tmp[100];
		strlwr(book.author,tmp);
		if(strcmp(name,tmp) == 0)
			printf("%lld %s %s %.2lf %s\n",book.acces_no,book.title,book.author,book.price,(book.is_issued ? "Issued" : "Not issued"));
	}
}

void count_books(FILE *fp){
	rewind(fp);
	Library book;
	printf("\n");
	int count = 0;
	while(fread(&book,sizeof(Library),1,fp)){
		count++;
	}
	printf("\nTotal Books in library: %d\n",count);
}

int compare(const void *x, const void *y){
	x = x;
	y = (Library *)y;
	return (((Library *)x)->acces_no > ((Library *)y)->acces_no);
}

void sort_by_accession(FILE *fp){
	rewind(fp);
	Library books[1000];
	int n = 0,i;
	while(fread(&books[n],sizeof(Library),1,fp)){
		n++;
	}
	qsort(books,n,sizeof(Library),compare);
	printf("\n");
	for(i=0;i<n;i++){
		Library book = books[i];
		printf("%lld %s %s %.2lf %s\n",book.acces_no,book.title,book.author,book.price,(book.is_issued ? "Issued" : "Not issued"));
	}
}

int main(){
	FILE *fp = fopen("data.bin","wb+");
	if(fp == NULL){
		printf("Error while opening data file\n");
		exit(0);
	}
	int choice;
	do{
		printf("\n");
		printf("1. Add book\n");
		printf("2. Display all book information\n");
		printf("3. List of books by specific author\n");
		printf("4. List the count of books in the library\n");
		printf("5. List the books in the order of accession number\n");
		printf("6. Exit\n");
		printf("Choose: ");
		
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				add(fp);
				break;
			case 2:
				display_books(fp);
				break;
			case 3:
				search_all_book_by_author(fp);
				break;
			case 4:
				count_books(fp);
				break;
			case 5:
				sort_by_accession(fp);
				break; 
		}

	}while(choice != 6);

	fclose(fp);
	return 0;
}
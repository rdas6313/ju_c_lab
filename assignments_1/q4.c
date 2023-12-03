#include<stdio.h>
char* words[] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety","hundred","thousand","lakh","crore"};
int num[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,80,90,100,1000,100000,10000000};

char* iwords[] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety","hundred","thousand","million","billion"};
int inum[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,80,90,100,1000,1000000,1000000000};

void print(int d){
	
	int i;
	for(i=31;i>=0;i--){
		if(num[i] == d){
			printf("%s",words[i]);
			break;
		}
	}
	
}	

void iprint(int d){
	int i;
	for(i=31;i>=0;i--){
		if(inum[i] == d){
			printf("%s",iwords[i]);
			break;
		}
	}

}

int main(){
	
	int i,amount,ans,j,tmp;
	printf("Enter Number: ");
	scanf("%d",&amount);
	tmp = amount;
	printf("\nIn words: ");
	if(amount == 0){
		printf("Zero\n");
		return 0;
	}
	for(i=31;i>=1;i--){
		if(amount / num[i] == 0)
			continue;
		
		ans = amount/num[i];
		if(ans > 10 && ans <= 20){
			printf(" ");
			print(ans);
		
		}else if(ans > 20 && ans < 100){
			printf(" ");
			print((ans/10)*10);
			printf(" ");
			print(ans%10);
		}
		else{
			printf(" ");
			if(ans > 1 || num[i] > 99)
				print(ans);
			
		}
		printf(" ");
		print(num[i]);
		amount = amount % num[i];
	}
	printf("\n");

	// international
	amount = tmp;
	printf("\nIn words(International): ");
	if(amount == 0){
		printf("Zero\n");
		return 0;
	}
	for(i=31;i>=1;i--){
		if(amount / inum[i] == 0)
			continue;
		ans = amount/inum[i];
		if((ans == 1 && inum[i] > 99) || (ans > 1 && ans <= 10)){
			printf(" ");
			iprint(ans);

		}
		else if(ans > 10 && ans <= 20){
			printf(" ");
			iprint(ans);
		
		}else if(ans > 20 && ans < 100){
			printf(" ");
			iprint((ans/10)*10);
			printf(" ");
			iprint(ans%10);
		}
		else if(ans >= 100){
			
			int tmp = ans / 100;
			printf(" ");
			iprint(tmp);
			printf(" ");
			iprint(100);

			ans = ans % 100;

			if(ans > 20){
				printf(" ");
				iprint((ans/10)*10);
				printf(" ");
				iprint(ans%10);

			}else if(ans > 0){
				printf(" ");
				iprint(ans);
			}
			
		}
		printf(" ");
		iprint(inum[i]);
		amount = amount % inum[i];
		//printf("data: %d\n",amount);

	}
		printf("\n");

	return 0;
}
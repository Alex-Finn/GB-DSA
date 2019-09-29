/*
 * homework2.c
 *
 *  Created on: 29 ����. 2019 �.
 *      Author: Alexey Elshin
 */

#include <stdio.h>

int swapDigits(int in){
	int res = 0;
	while(in > 0){
		res *= 10;
		res += in % 10;
		in /= 10;
	}
	return res;
}

void decToBinRecursion(int dec, int *ptr){
	int bin = *ptr;
	bin = dec % 2;
	dec /= 2;
	if(dec > 0)
		decToBinRecursion(dec, &bin);
	printf("%d", bin);
}

int aPowB(int a, int b){
	int res = a;
	int i;
	for(i = b; i > 1; i--){
		res *= a;
	}
	return res;
}

int aPowBRec(int a, int b){
	int res = a;
	b--;
	if(b > 0)
		res *= aPowBRec(a, b);
	return res;
}

int aPowBRecEven(int a, int b){

	int res=a;

	if(b > 1){
		if(b % 2 == 0){
			res = aPowBRecEven(a, b/2) * aPowBRecEven(a, b/2);
		}
		else{
			res = a * aPowBRecEven(a, b/2) * aPowBRecEven(a, b/2);
		}
	}
	return res;
}



void fromDecToBin(){
	puts("\nSwicther decimal integer to binary value with recursion");
	int dec, bin=0;
	printf("Enter a decimal value: ");
	scanf("%d", &dec);
	printf("Binary value is: ");
	decToBinRecursion(dec, &bin);

	puts("\n---------------");
}

void poweringA(){
	puts("\nPowering integer 'a' to 'b' grade");
	int a, b;
	printf("Enter value for base 'a': ");
	scanf("%d", &a);
	printf("Enter value for grade 'b': ");
	scanf("%d", &b);
	printf("Result of 'a^b' without recursion: %d\n", aPowB(a,b));
	printf("Result of 'a^b' with recursion: %d\n", aPowBRec(a,b));
	printf("Result of 'a^b' with recursion and evens property: %d\n", aPowBRecEven(a,b));

	puts("\n---------------");
}

void calculator(){
	puts("\nContractor calculator");
	//const int ADD = 1, MULT = 2;
	int from = 3, to = 20, counter = 0/*, i, j*/;
	//printf("Enter value for 'from': ");
	//scanf("%d", &from);
	//printf("Enter value for 'to': ");
	//scanf("%d", &to);
	//int matrix[][to-from];
	//int col = 0;
	//int exec[to-from] = 0;
	//int ptr = 0;
	//while(from < to){
	//	exec[ptr] = ADD;
	//	ptr++;
	//	from++;
	//}
	//if(from == to){
	//	counter++;
	//	exec[] = 0;
	//}

	//for(i = 0; i < to-from; i++){
	//	matrix[col][i] = ADD;
	//}

	puts("Не осилил");
	printf("Count for different program from '%d' to '%d' equal '%d'\n", from, to, counter);
	puts("\n---------------");
}

void menu()
{
	printf("Choose number of task:\n");
	printf("1 - Switch decimal value to binary with recursion\n");
	printf("2 - Powering 'a' to 'b' grade\n");
	printf("3 - Contractor Calculator\n");
	printf("0 - exit\n");
}

int main(){
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	puts("Program started");

	int sel = 0;
	    do
	    {
	        menu();
	        scanf("%i", &sel);
	        switch (sel)
	        {
	            case 1:
	                fromDecToBin();
	                break;
	            case 2:
	            	poweringA();
	                break;
	            case 3:
	                calculator();
	                break;
	            case 0:
	                printf("Bye-bye");
	                break;
	            default:
	                printf("Wrong selected\n");
	        }
	    } while (sel != 0);
	    return 0;

	return 0;
}

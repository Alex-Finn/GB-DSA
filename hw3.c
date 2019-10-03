/*
 * hw3.c
 *
 *  Created on: 3 october 2019 г.
 *      Author: Elshin Alexey
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000 	// size for arrays
#define SEED 200	// seed for random function (0-200)

void fillArray(int *arr, int len);
void printArray(int *arr, int len);
void swap(int *a, int *b);
void bubbleSort(int *arr, int len);
void bubbleSort2(int *arr, int len);
void bubbleSort3(int *arr, int len);
void shakerSort(int *arr, int len);
void menu();

int main(){
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	puts("-->Program started");

	int arr[SIZE];

	int sel = 0;
		    do
		    {
		        menu();
		        scanf("%i", &sel);
		        switch (sel)
		        {
		            case 1:
		                fillArray(arr, SIZE);
		                printArray(arr, SIZE);
		                break;
		            case 2:
		            	printArray(arr, SIZE);
		                break;
		            case 3:
		                bubbleSort(arr, SIZE);
		                printArray(arr, SIZE);
		                break;
		            case 4:
		            	bubbleSort2(arr, SIZE);
		            	printArray(arr, SIZE);
		                break;
		            case 5:
		            	bubbleSort3(arr, SIZE);
		            	printArray(arr, SIZE);
		                break;
		            case 6:
		            	shakerSort(arr, SIZE);
		            	printArray(arr, SIZE);
		                break;
		            case 0:
		                printf("Bye-bye\n");
		                break;
		            default:
		                printf("Wrong selection\n");
		        }
		    } while (sel != 0);
	puts("Program finished-->");
	return 0;
}

void menu()
{
	puts("\n=====================");
	printf("Choose number of task:\n");
	printf("1 - Create new array\n");
	printf("2 - Print array\n");
	printf("3 - Execute bubble sort\n");
	printf("4 - Execute improved bubble sort\n");
	printf("5 - Execute odd-even bubble sort\n");
	printf("6 - Execute shaker sort\n");
	printf("0 - exit\n");
	puts("=====================");
}

void fillArray(int *arr, int len){
	int i;
	srand(time(NULL));
	printf("\nNew array initiated. Size = %d\n", len);
	for (i = 0; i < len; i++) {
		arr[i] = rand() % SEED;
	}
}

void printArray(int *arr, int len){
	int i;
	for (i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int *a, int *b){
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void bubbleSort(int *arr, int len){
	int i, j, counter=0;
	for (i = 0; i < len; i++) {
		counter++;
		for (j = 0; j < len-1; j++) {
			counter++;
			if (arr[j] > arr[j+1]) {
				counter++;
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
	printf("Bubble sort executed. Number of operations: %d\n", counter);
}

void bubbleSort2(int *arr, int len){
	int i, j, flag, counter=0;
	for (i = 0; i < len; i++) {
		counter++;
		flag = 0;
		for (j = 0; j < len-(i+1); j++) {
			counter++;
			if (arr[j] > arr[j+1]) {
				counter++;
				swap(&arr[j], &arr[j+1]);
				flag = 1;
			}
		}
		if (flag==0) {
			counter++;
			break;
		}
	}
	printf("Improved bubble sort executed. Number of operations: %d\n", counter);
}

void bubbleSort3(int *arr, int len){
	int i, j, loopFlag = 0, exitFlag = 0, counter = 0;
	for (i = 0; i < len; i++) {
		counter++;
		loopFlag = 0;
		for (j = 0; j < len-1; j+=2) {
			counter++;
			if (arr[j] > arr[j+1]) {
				counter++;
				swap(&arr[j], &arr[j+1]);
				loopFlag++;
				exitFlag=0;
			}
		}
		for (j = 1; j < len-1; j+=2) {
			counter++;
			if (arr[j] > arr[j+1]) {
				counter++;
				swap(&arr[j], &arr[j+1]);
				loopFlag++;
				exitFlag=0;
			}
		}
		if (loopFlag==0) {
			counter++;
			exitFlag++;
		}
		if (exitFlag > 1) {
			break;
		}
	}
	printf("Odd-even bubble sort executed. Number of operations: %d\n", counter);
}

void shakerSort(int *arr, int len){
	int i, j, k, counter=0;
	for (i = 0; i < len-1-i; i++) {
		counter++;
		for (j = i; j < len-1-i; j++) {
			counter++;
			if (arr[j] > arr[j+1]) {
				counter++;
				swap(&arr[j], &arr[j+1]);
			}
		}
		for (k = j-1; k > i; k--) {
			counter++;
			if (arr[k] < arr[k-1]) {
				counter++;
				swap(&arr[k], &arr[k-1]);
			}
		}
	}
	printf("Shaker sort executed. Number of operations: %d\n", counter);
}

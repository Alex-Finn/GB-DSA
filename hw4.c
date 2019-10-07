/*
 * hw4.c
 *
 *  Created on: 7 october 2019 г.
 *      Author: Alexey Elshin
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 7
#define N 7

int r;
int c;

void menu();
void findRoutes(int n, int m);
void findRoutesBarriers(int n, int m);
void printMatrix(int rows, int cols, int mtrx[r][c]);
void doBarriers(int bar[r][c]);

int main(){
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	puts("-->Program started");

	int sel = 0;
		    do
		    {
		        menu();
		        scanf("%i", &sel);
		        switch (sel)
		        {
		            case 1:
		            	printf("Set number of rows: ");
		            	scanf("%d", &r);
		            	printf("Set number of columns: ");
		            	scanf("%d", &c);
		            	findRoutes(r, c);
		                break;
		            case 2:
		            	printf("Set number of rows: ");
		            	scanf("%d", &r);
		            	printf("Set number of columns: ");
		            	scanf("%d", &c);
		            	findRoutesBarriers(r, c);
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
	printf("1 - King and routes\n");
	printf("2 - King and routes with barriers\n");
	printf("0 - exit\n");
	puts("=====================");
}

void findRoutes(int n, int m){
	int i, j;
	int arr[n][m];
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if(i == 0 || j == 0)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i][j-1] + arr[i-1][j];
		}
	}
	printMatrix(n, m, arr);

}

void findRoutesBarriers(int n, int m){
	int i, j;
	int arr[n][m];
	int bars[n][m];
	doBarriers(bars);
	printf("Maps of barriers:\n");
	printMatrix(n, m, bars);

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (bars[i][j] == 0)
				arr[i][j] = 0;
			else if (i == 0 || j == 0) {
				if ((i == 0 && j != 0 && arr[i][j-1] == 0)
				|| (i != 0 && j == 0 && arr[i-1][j] == 0))
					arr[i][j] = 0;
				else
					arr[i][j] = 1;
			}
			else
				arr[i][j] = arr[i][j-1] + arr[i-1][j];
		}
	}
	printf("Numbers of ways:\n");
	printMatrix(n, m, arr);
}

void printMatrix(int rows, int cols, int mtrx[r][c]){
	int k, l;
	for (k = 0; k < rows; ++k) {
		for (l = 0; l < cols; ++l) {
			printf("%5d", mtrx[k][l]);
		}
		printf("\n");
	}
}

void doBarriers(int bar[r][c]){
	int i, j;
	srand(time(NULL));
	for (i = 0; i < r; ++i) {
		for (j = 0; j < c; ++j) {
			if (rand() % 15 < 3) {
				bar[i][j] = 0;
			}
			else{
				bar[i][j] = 1;
			}
			//printf("%5d", bar[i][j]);
		}
		//printf("\n");
	}
	bar[0][0] = 1;
}

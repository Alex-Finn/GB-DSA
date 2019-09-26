/*
 * intswap.c
 *
 *  3. Ќаписать программу обмена значени€ми двух целочисленных переменных:
 *  *без использовани€ третьей переменной.
 *
 *  Created on: 26 сент. 2019 г.
 *      Author: Alexey
 */

#include <stdio.h>

int main(){
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

	puts("Program started");
	int x, y;
	printf("Enter value for X: ");
	scanf("%d", &x);
	printf("Enter value for Y: ");
	scanf("%d", &y);
	printf("\nYour entered values is:\nX = %d, Y = %d", x, y);

	x += y;
	y -= x;
	y = -y;
	x -= y;

	printf("\nSwapped values is:\nX = %d, Y = %d", x, y);

	return 0;
}

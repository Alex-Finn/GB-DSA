/*
 * roots.c
 *
 *  4. Написать программу нахождения корней заданного квадратного уравнения.
 *
 *  Created on: 26 сент. 2019 г.
 *      Author: Alexey
 */
#include <stdio.h>
#include <math.h>

int icmpr(int d){
	if(d < 0)
		return -1;
	if(d == 0)
		return 0;
	return 1;
}

float froot(int a, int b, int D){
	float root;
	float floatD = (float)D;
	root = ((-1)*b - sqrtf(floatD)) / (2*a);
	return root;
}

float sroot(int a, int b, int D){
	float root;
	float floatD = (float)D;
	root = ((-1)*b + sqrtf(floatD)) / (2*a);
	return root;
}

int main(){
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

	puts("Program started");
	int a, b, c, D;
	char op1 = '+';
	char op2 = '+';
	puts("Enter indexes for Quadratic equation with type: 'a*x^2 + b*x + c = 0'");
	puts("Note that 'a' should not be equal zero");
	printf("Enter integer value of 'a' index (a != 0): ");
	scanf("%d", &a);
	printf("Enter integer value of 'b' index: ");
	scanf("%d", &b);
	printf("Enter integer value of 'c' index: ");
	scanf("%d", &c);
	if(b < 0)
		op1 = '-';
	if(c < 0)
		op2 = '-';
// попытался видоизменять строку в случае нулевых коэффициентов или равных 1, но не вышло.
	printf("You entered this Quadratic equation: '%d*x^2 %c %d*x %c %d = 0'\n",
			a, op1, (b < 0 ? (-1)*b : b), op2, (c < 0 ? (-1)*c : c));
	D = b*b - 4*a*c;
	printf("Discriminator is equal: %d\n", D);


	switch(icmpr(D))
	{
		case 1:
			puts("Your Quadratic equation has two roots:");
			printf("First root: %.2f, Second root: %.2f", froot(a, b, D), sroot(a, b, D));
			break;

		case 0:
			puts("Your Quadratic equation has one root:");
			printf("Root equal: %.2f", froot(a, b, D));
			break;

		case -1:
			puts("Your Quadratic equation has no roots");
			break;

		default:
			puts("Somehow but its going wrong");
	}

	return 0;
}

/*
 * imt.c
 *
 * 1. ¬вести вес и рост человека. –ассчитать и вывести индекс массы тела по формуле I=m/(h*h);
 * где m-масса тела в килограммах, h - рост в метрах.
 *
 *  Created on: 26 сент. 2019 г.
 *      Author: Alexey
 */
#include <stdio.h>

int main(){
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

	puts("Program started");
	float weight, height, bmi;
	printf("Enter your weight in kg: ");
	scanf("%f", &weight);
	printf("Enter your height in cm: ");
	scanf("%f", &height);
	bmi = weight / (height * height) * 100 * 100;	//	convert cm to m
	printf("Your BMI is equal: %3.2f", bmi);

	return 0;
}

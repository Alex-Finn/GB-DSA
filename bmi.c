/*
 * imt.c
 *
 * 1. ������ ��� � ���� ��������. ���������� � ������� ������ ����� ���� �� ������� I=m/(h*h);
 * ��� m-����� ���� � �����������, h - ���� � ������.
 *
 *  Created on: 26 ����. 2019 �.
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

/*
 * age.c
 *
 *	6. ������ ������� �������� (�� 1 �� 150 ���)
 *	� ������� ��� ������ � ����������� ������ ����, ����� ��� ����.
 *
 *  Created on: 26 ����. 2019 �.
 *      Author: Alexey
 */

#include <stdio.h>

int main(){
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);

	puts("Program started");
	int age = 1;
	int sign;

	do{
		printf("������� ������� (1-150): ");
		scanf("%d", &age);
		if(age < 1 || age > 150)
			puts("�������. ����� ����� �� 1 �� 150");
	} while(age < 1 || age > 150);

	sign = age % 10;

	printf("�������� �������: %d ", age);

	if((age > 4 && age < 21) || (age > 104 && age < 121))
		puts("���");
	else if(sign > 1 && sign < 5)
		puts("����");
	else if(sign == 1)
		puts("���");
	else
		puts("���");

	return 0;
}

/*
 * intswap.c
 *
 *  3. �������� ��������� ������ ���������� ���� ������������� ����������:
 *  *��� ������������� ������� ����������.
 *
 *  Created on: 26 ����. 2019 �.
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

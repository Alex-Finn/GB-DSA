/*
 * age.c
 *
 *	6. Ввести возраст человека (от 1 до 150 лет)
 *	и вывести его вместе с последующим словом «год», «года» или «лет».
 *
 *  Created on: 26 сент. 2019 г.
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
		printf("Введите возраст (1-150): ");
		scanf("%d", &age);
		if(age < 1 || age > 150)
			puts("Палехчи. Нужно число от 1 до 150");
	} while(age < 1 || age > 150);

	sign = age % 10;

	printf("Введённый возраст: %d ", age);

	if((age > 4 && age < 21) || (age > 104 && age < 121))
		puts("лет");
	else if(sign > 1 && sign < 5)
		puts("года");
	else if(sign == 1)
		puts("год");
	else
		puts("лет");

	return 0;
}

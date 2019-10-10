/*
 * hw5.c
 *
 *  Created on: 10 october 2019 y.
 *      Author: Alexey Elshin
 */

#include <stdio.h>
#include <stdlib.h>

#define T int

struct NodeS{
	T value;
	struct NodeS* next;
};
struct NodeS *HeadS = NULL;

typedef struct NodeS NodeS;

void Push(T value){
	NodeS *temp = (NodeS*)malloc(sizeof(NodeS));
	temp->value = value;
	temp->next = HeadS;
	HeadS = temp;
}

void printList(NodeS *head){
	printf("List content: \n");
	while(head){
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

NodeS* doNewCopy(NodeS *head){
	NodeS *Newlist = (NodeS*)malloc(sizeof(NodeS));
	//NodeS *NewlistHead = NULL;

	while(head){
		// по всей видимости нужно создавать новый
		// нод для каждого элемента
		//NewlistHead->value = head->value;
		Newlist->value = head->value;
		Newlist->next = head->next;
		head = head->next;
	}

	return Newlist;
}

void menu();
void parentheses();
void queue();
void copyList();

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
			            	parentheses();
			                break;
			            case 2:
			            	copyList();
			                break;
			            case 3:
			            	queue();
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
	printf("1 - Parentheses\n");
	printf("2 - Copy single-linked list\n");
	printf("3 - Queue based on double-linked list\n");
	printf("0 - Exit\n");
	puts("=====================");
}

void parentheses(){
	printf("Parentheses program:\n");
	printf("Not implemented\n");
}

void copyList(){
	printf("Copy single-linked list program:\n");
	printf("Not implemented\n");

	NodeS *Newlist = (NodeS*)malloc(sizeof(NodeS));

	for (int i = 3; i < 40; i++) {
		Push(i);
		i = i + 3;
	}

	printList(HeadS);

	Newlist = doNewCopy(HeadS);

	printList(HeadS);
	printList(Newlist);

}

void queue(){
	printf("Double-linked list based queue program:\n");
	printf("Not implemented\n");
}

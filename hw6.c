/*
 * hw6.c
 *
 *  Created on: 14 october 2019 г.
 *      Author: Alexey Elshin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
} Node;

Node *getFreeNode(int val, Node *parent){
	Node *tmp = (Node*)malloc(sizeof(Node*));
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->data = val;
	tmp->parent = parent;
	return tmp;
}

Node *insertNode(Node *tree, int *val){
	if(tree == NULL){
		tree = (Node*)malloc(sizeof(Node*));
		tree->data = *val;
		tree->left = NULL;
		tree->right = NULL;
	}
	else if(*val < tree->data){
		tree->left = insertNode(tree->left, val+1);
	}
	else{
		tree->right = insertNode(tree->right, val+1);
	}
	return tree;
}

Node *tree(int n, Node *parent, int *arr){
	Node *node;
	if(n == 0){
		node = NULL;
	}
	else{
		node = (Node*)malloc(sizeof(Node*));
		node->data = *arr;
		node->parent = parent;
		int left = *arr/2;
		int right = *arr - left - 1;
		node->left = tree(left, node, arr+1);
		node->right = tree(right, node, arr+1);
		// не вышло с массивом в параметрах
	}
	return node;
}

void menu();
void hash();
void binaryTree();
void students();
void printTree(Node* root);

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
			            	hash();
			                break;
			            case 2:
			            	binaryTree();
			                break;
			            case 3:
			            	students();
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
	printf("1 - Hash-function\n");
	printf("2 - Binary tree search\n");
	printf("3 - Students database\n");
	printf("0 - Exit\n");
	puts("=====================");
}

void hash(){
	printf("Hash-function program:\n");
	//printf("\nEnter string: ");
	//char str[100];
	//scanf("%s", str);
	// так программа дробится по пробелам. странно

	char str[100] = {"this is some string"};
	int len = strlen(str);
	int res=0;
	for (int i = 0; i < len; ++i) {
		res += str[i];
	}

	printf("\nEntered string = \"%s\".\nlenght = %d,\nhash f(x) result = %d", str, len, res);
}

void binaryTree(){
	printf("Binary tree search program:\n");
	printf("Not implemented\n");

	int vals[10] = {5,3,7,6,9,2,4,1,0,8};
	//Node *wood = tree(10, NULL, vals);
	Node *wood = insertNode(NULL, vals);

	printTree(wood);
	printf("\n");
}

void students(){
	printf("Students database program:\n");
	printf("Not implemented\n");
}

void printTree(Node *root){
	if (root != NULL) {
		printf("%d", root->data);
		if (root->left != NULL || root->right != NULL) {
			printf("(");
			if(root->left != NULL)
				printTree(root->left);
			else
				printf("null");
			printf(", ");
			if(root->right != NULL)
				printTree(root->right);
			else
				printf("null");
			printf(")");
		}
	}
}

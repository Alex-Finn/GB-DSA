/*
 * hw7.c
 *
 *  Created on: 17 october 2019 y.
 *      Author: Alexey Elshin
 */

#include <stdio.h>
#include <stdlib.h>

int n = 10;

typedef struct Node{
	int data;
	struct Node *next;
} Node;

typedef struct{
	int data;
	int* visited;
	Node **children;
} GraphNode;

typedef struct {
	Node *head;
	int size;
} Stack;

void menu();
void dfs(GraphNode*, int);
GraphNode* createGraph(int);
void addEdge(GraphNode*, int, int);
void printGraph(GraphNode*);
void dfs_program();

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
			            	dfs_program();
			                break;
			            case 2:
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
	printf("1 - Depth-first search\n");
	printf("2 - Not implemented\n");
	printf("0 - Exit\n");
	puts("=====================");
}

void dfs_program(){
	GraphNode* graph = createGraph(4);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 2);
	addEdge(graph, 2, 3);

	printGraph(graph);
	dfs(graph, 2);
}

void dfs(GraphNode* start, int v) {
    Node* list = start->children[v];
    Node* temp = list;

    start->visited[v] = 1;
    printf("Visited %d \n", v);

    while(temp!=NULL) {
        int connectedVertex = temp->data;

        if(start->visited[connectedVertex] == 0) {
            dfs(start, connectedVertex);
        }
        temp = temp->next;
    }
}

Node* createNode(int v)
{
	Node* newNode = malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

GraphNode* createGraph(int vertices)
{
	GraphNode* graph = malloc(sizeof(GraphNode));
    graph->data = vertices;

    graph->children = malloc(vertices * sizeof(Node*));

    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->children[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(GraphNode* graph, int src, int dest)
{
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->children[src];
    graph->children[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->children[dest];
    graph->children[dest] = newNode;
}

void printGraph(GraphNode* graph)
{
    int v;
    for (v = 0; v < graph->data; v++)
    {
        Node* temp = graph->children[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

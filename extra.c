/*Gabriel Couto & Felippo Stédile: Dupla */
// funcoes auxiliares

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extra.h"

extern int yylineno;

int get_line_number() {

	return yylineno;
}

void print_node(Node *node){

printf("Entrei na print NODO\n");

	if(node != NULL)
	{
		printf("aponto: %p\n", node);
		printf("meu endereço: %p\n", &node);
		printf("%s\n %s\n %p\n %p\n", node->name, node->label, node->firstChild, node->nextSibling);
	}	


}

Node * create_node(char* name, char* label)
{
	printf("Entrei na Create Node\n");	

	Node *myNode;
	myNode = (Node*) malloc (sizeof(Node));
	strcpy(myNode->name, name);
	strcpy(myNode->label, label);
	
	//print_node(myNode);
	
	myNode->firstChild = NULL;
	myNode->nextSibling = NULL;


	return myNode;
}

Node * create_node_from_token(char* name, Valor_lexico_t valor_lexico)
{
		printf("Entrei na Create Node from Token\n");

	Node *myNode;
	myNode = (Node*) malloc (sizeof(Node));
	//printf("AQUIIIII ENDEREÇOOOO %p\n", myNode);
	strcpy(myNode->name, name);
	if(valor_lexico.genero == 0)
		strcpy(myNode->label, valor_lexico.valor.cadeia);
	else if(valor_lexico.genero == 1)
		sprintf(myNode->label, "%d", valor_lexico.valor.inteiro);
	else if(valor_lexico.genero == 2)
		sprintf(myNode->label, "%f", valor_lexico.valor.flutuante);

	//print_node(myNode);

	myNode->firstChild = NULL;
	myNode->nextSibling = NULL;


	print_tree(myNode);
	return myNode;
}

void add_child(Node *parentNode, Node *childNode)
{

//print_node(parentNode);
//print_node(childNode);

printf("Entrei na Add Child\n");
	if(parentNode->firstChild == NULL)
		parentNode->firstChild = childNode;
	else if(parentNode->nextSibling == NULL)
		parentNode->nextSibling = childNode;
	else
	{
		Node *nextNode = parentNode;
		while(nextNode->nextSibling != NULL)
			nextNode = nextNode->nextSibling;
		nextNode->nextSibling = childNode;
		// memory release?
	}
}


void print_tree(Node* node)
{
printf("Entrei na printf TReee\n");

	if(node != NULL)
	{
		if(node->firstChild != NULL){
			print_tree(node->firstChild);
			//printf("%p, %p", node, node->firstChild);
			}
		if(node->nextSibling != NULL){
			print_tree(node->nextSibling);
			//printf("%p, %p", node, node->nextSibling);
			}
		printf("%p [label=\"%s\"]\n", node, node->label);
	}	


}

void exclude_node(Node* node)
{

printf("Entrei na exclude node\n");
	// When removing a node, we remove and release it and its children recursively.
	if(node != NULL)
	{
		exclude_node(node->firstChild);
		exclude_node(node->nextSibling);		

		/*
		Reavaliar a liberação de memória.


		free(node->name);
		free(node->label);
		free(node);
		*/		
	}	
}












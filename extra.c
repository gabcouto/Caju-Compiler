/*Gabriel Couto & Felippo Stédile: Dupla */
// funcoes auxiliares

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extra.h"

extern int yylineno;

Node *irmao = NULL;
Node *irmao2= NULL;
Node *filho = NULL;

int get_line_number() {

	return yylineno;
}

void print_node(Node *node){

	printf("Entrei na print NODO\n");

	if(node != NULL)
	{
		printf("eu estou em: %p\n", node);
		printf("%s\n %s\n %p\n %p\n",
		node->name, node->label, node->firstChild, node->nextSibling);
		printf("endereço do meu filho: %p\n", node->firstChild);
		printf("endereço do meu irmao: %p\n", node->nextSibling);
	}	


}

Node * create_node(char* name, char* label)
{
	//printf("Entrei na Create Node\n");	
	irmao = NULL;
	Node *myNode;
	myNode = (Node*) malloc (sizeof(Node));
	strcpy(myNode->name, name);
	strcpy(myNode->label, label);
	
	//print_node(myNode);
	
	myNode->firstChild = NULL;
	if(irmao2!=NULL) irmao2->nextSibling = myNode;
	else irmao2 = myNode;
	
	myNode->nextSibling = NULL;
	
	return myNode;
}

Node * create_node_from_token(char* name, Valor_lexico_t valor_lexico)
{
	printf("Entrei na Create Node from Token\n");
	irmao2= NULL;
	Node *myNode;
	myNode = (Node*) malloc (sizeof(Node));
	strcpy(myNode->name, name);
	if(valor_lexico.genero == 0)
		strcpy(myNode->label, valor_lexico.valor.cadeia);
	else if(valor_lexico.genero == 1)
		sprintf(myNode->label, "%d", valor_lexico.valor.inteiro);
	else if(valor_lexico.genero == 2)
		sprintf(myNode->label, "%f", valor_lexico.valor.flutuante);
		
	//print_node(myNode);
	
	myNode->firstChild = NULL;
	if(irmao!=NULL) irmao->nextSibling = myNode;
	else irmao = myNode;
	
	myNode->nextSibling = NULL;

	//print_tree(myNode);
	return myNode;
}

void add_child(Node *parentNode, Node *childNode)
{

irmao = NULL;
printf("Entrei na Add Child\n");
/*
printf("PAI\n");
print_node(parentNode);
printf("\nFILHO\n");
print_node(childNode);
*/
	if(parentNode->firstChild == NULL){
		parentNode->firstChild = childNode;
		//printf("\nPAI\n");
		//print_node(parentNode);
		}
	else
	{
		Node *nextNode = parentNode->firstChild;
		while(nextNode->nextSibling != NULL)
			nextNode = nextNode->nextSibling;
		nextNode->nextSibling = childNode;
		// memory release?
	}
	
	print_node(parentNode);
	print_node(parentNode->nextSibling);
	print_node(childNode);
	
	
	//print_tree(parentNode);
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
			if (node->nextSibling!=node) print_tree(node->nextSibling);
			//printf("%p, %p", node, node->nextSibling);
			}
		printf("%p [label=\"%s\"]\n", node, node->label);
	}	


}

void exporta(void *arvore)
{
       print_tree((Node*) arvore);
}

void libera(void *arvore)
{
       exclude_node((Node*) arvore);
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












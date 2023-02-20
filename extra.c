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

Pilha * create_stack(Tabela* tabela)
{
	Pilha *myStack;
	myStack = (Pilha*) malloc (sizeof(Pilha));
	
	myStack->top = NULL;
	myStack->elemento_pilha = tabela;

	return myStack;
}

void push_stack(Tabela* tabela, Pilha* pilha)
{
	Pilha *newStackElement;
	newStackElement = (Pilha*) malloc (sizeof(Pilha));

	Pilha *topo = top_stack(pilha);

	newStackElement->elemento_pilha = tabela;
	newStackElement->top = NULL;

	topo->top = newStackElement;

}

Pilha* top_stack(Pilha* pilha)
{
	Pilha *myStack = pilha;
	while(myStack->top != NULL)
		myStack = myStack->top;
	
	return myStack;
}

Pilha* pop_stack(Pilha* pilha)
{
	Pilha *myStack = pilha, *eliminado;
	while(myStack->top->top != NULL)
		myStack = myStack->top;

	eliminado = myStack->top;
	myStack->top = NULL;

	return eliminado;
}

void print_node(Node *node){

	//printf("Entrei na print NODO\n");

	if(node != NULL)
	{
		printf("eu estou em: %p\n", node);
		printf("%s\n %s\n & do meu filho: %p\n &do meu irmao: %p\n",
		node->name, node->label, node->firstChild, node->nextSibling);
	}	


}

Node * create_node(char* name, char* label)
{	
	Node *myNode;
	myNode = (Node*) malloc (sizeof(Node));
	strcpy(myNode->name, name);
	strcpy(myNode->label, label);

	
	myNode->firstChild = NULL;
	myNode->nextSibling = NULL;
	

	return myNode;
}

Node * create_node_from_token(char* name, Valor_lexico_t valor_lexico)
{

	Node *myNode;
	myNode = (Node*) malloc (sizeof(Node));
	strcpy(myNode->name, name);
	if(valor_lexico.genero == 0)
		if(strcmp("CHAMA_FUNCAO", name) == 0)
		{
			char fcall[100] = "call ";
			strcat(fcall, valor_lexico.valor.cadeia);
			strcpy(myNode->label, fcall);
		}
		else
			strcpy(myNode->label, valor_lexico.valor.cadeia);
	else if(valor_lexico.genero == 1)
		sprintf(myNode->label, "%d", valor_lexico.valor.inteiro);
	else if(valor_lexico.genero == 2)
		sprintf(myNode->label, "%f", valor_lexico.valor.flutuante);

	
	myNode->firstChild = NULL;
	myNode->nextSibling = NULL;

	return myNode;
}

void add_child(Node *parentNode, Node *childNode)
{
	if(parentNode->firstChild == NULL)
		parentNode->firstChild = childNode;

	else
	{
		Node *nextNode = parentNode->firstChild;
		while(nextNode->nextSibling != NULL )
			nextNode = nextNode->nextSibling;

		nextNode->nextSibling = childNode;
		// memory release?
	}

	//printf("Vou printar com nó pai: %s\n", parentNode->name);
	//print_tree(parentNode);
}


void print_tree(Node* node)
{

	if(node != NULL)
	{
		if(node->firstChild != NULL){
			print_tree(node->firstChild);
			}
		printf("%p [label=\"%s\"]\n", node, node->label);
		if(node->nextSibling != NULL){
			print_tree(node->nextSibling);
			}
	}	


}

void print_parentship(Node* node)
{
	Node *nextNode = node->firstChild;
	if(nextNode != NULL)
	{
		printf("%p, %p\n", node, nextNode);
		print_parentship(nextNode);
		while(nextNode->nextSibling != NULL)
		{
			printf("%p, %p\n", node, nextNode->nextSibling);
			nextNode = nextNode->nextSibling;
			print_parentship(nextNode);		
		}
	
	}
}

void exporta(void *arvore)
{
	print_tree((Node*) arvore);
	print_parentship((Node*) arvore);
}

void libera(void *arvore)
{
       exclude_node((Node*) arvore);
}


void exclude_node(Node* node)
{
	if(node != NULL)
	{
		if(node->firstChild != NULL){
			exclude_node(node->firstChild);
			}
		if(node->nextSibling != NULL){
			exclude_node(node->nextSibling);
		}
		free(node);
	}		
}












/*Gabriel Couto & Felippo Stédile: Dupla */
// funcoes auxiliares

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int yylineno;

int get_line_number() {

	return yylineno;
}

enum token_type {caractere_especial, palavra_reservada, operador_composto, identificador, literal};

union Valor {
	int inteiro;
	float flutuante;
	char caractere;
	int booleano;
	char cadeia[80];
};

typedef struct valor_lexico_t
{
	int line_no;
	token_type tipo;
	union Valor valor;

} Valor_lexico_t;

typedef struct node
{
	char name[60];
	char label[60];
	struct node *firstChild;
	struct node *nextSibling;
} Node;

Node create_node(char* name, char* label)
{
	Node myNode;
	strcpy(myNode.name, name);
	strcpy(myNode.label, label);
	
	myNode.firstChild = NULL;
	myNode.nextSibling = NULL;

	return myNode;
}

void add_child(Node *parentNode, Node *childNode)
{
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
	if(node != NULL)
	{
		print_tree(node->firstChild);
		print_tree(node->nextSibling);
		printf("%p [label=\"%s\"]\n", node, node->label);
	}	


}

void exclude_node(Node* node){
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












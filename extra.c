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

Node create_node(char* name, char* label)
{
	Node myNode;
	strcpy(myNode.name, name);
	strcpy(myNode.label, label);
	
	myNode.firstChild = NULL;
	myNode.nextSibling = NULL;

	return myNode;
}

Node create_node_from_token(char* name, Node *node)
{
	Node myNode;	
	strcpy(myNode.name, name);
	strcpy(myNode.label, node.label);
	
	
	myNode.firstChild = node.firstChild;
	myNode.nextSibling = node.nestSibling;

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
		if(node->firstChild != NULL)
			printf("%p, %p", node, node->firstChild);
		print_tree(node->nextSibling);
		if(node->nextSibling != NULL)
			printf("%p, %p", node, node->nextSibling);
		printf("%p [label=\"%s\"]\n", node, node->label);
	}	


}

void exclude_node(Node* node)
{
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












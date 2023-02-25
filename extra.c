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

int tamanho_tipo(enum Tipo tipo)
{
	if(tipo == inteiro)
		return 4;
	else if(tipo == flutuante)
		return 4;	
	else if(tipo == booleano)
		return 4; // é int
	else if(tipo == caractere)
		return 1;

}

Tabela* create_simbolo()
{
	Tabela* myTable;
	myTable = (Tabela*) malloc (sizeof(Tabela));
	myTable->nextElement = NULL;
	return myTable;
}

Content* create_conteudo(int linha, int coluna, enum Natureza natureza, int tamanho, char *dados, char *outros)
{
	Content* myContent;
	myContent = (Content*) malloc (sizeof(Content));
	Location* myLocation;
	myLocation = (Location*) malloc (sizeof(Location));
	myLocation->linha = linha;
	myLocation->coluna = coluna;

	myContent->localizacao = myLocation;
	myContent->natureza = natureza;
	myContent->tamanho = tamanho;
	strcpy(myContent->dados, dados);
	strcpy(myContent->outros, outros);

	return myContent;

}
/*
	Content* conteudo_de_simbolo = create_conteudo();
	add_to_table(tabela_raiz, conteudo_de_simbolo);
*/
Tabela* find_free_place(Tabela* myTable)
{
	if(myTable->nextElement != NULL)
		find_free_place(myTable->nextElement);
	else
		return myTable;
}

void add_to_table(Tabela* myTable, Content* conteudo)
{
	Tabela* newSimbolo = create_simbolo();
	find_free_place(myTable)->nextElement = newSimbolo;
	newSimbolo->conteudo = conteudo;

}

void analisa_e_insere(Tabela *myTable, Node *arvore, Node *tipo)
{

	if(arvore != NULL)
	{
		if(arvore->firstChild->label[0] == ','){
			analisa_e_insere(myTable, arvore->firstChild, tipo);
		}
		if(strcmp(arvore->name, "TK_IDENTIFICADOR") == 0)
		{
			enum Tipo type;
			char outros[60] = {};
			switch(tipo->label[0])
			{
				case 'i':
					type = inteiro; break;
				case 'f':
					type = flutuante; break;
				case 'b':
					type = booleano; break;
				case 'c':
					type = caractere; break;
			}

			Content* conteudo_de_simbolo = create_conteudo(arvore->line_no, arvore->col_no,/* Variavel,*/ type, tamanho_tipo(type), arvore->label, outros);
			add_to_table(myTable, conteudo_de_simbolo);
		}

	
		if(strcmp(arvore->nextSibling->label, "[]") == 0)
		{
			arvore = arvore->nextSibling->firstChild;
			int line_no = arvore->line_no, col_no = arvore->col_no, tamanho;
			enum Tipo type;
			char outros[60] = {};
			char dados[60];
			strcpy(dados, arvore->label);
			switch(tipo->label[0])
			{
				case 'i':
					type = inteiro; break;
				case 'f':
					type = flutuante; break;
				case 'b':
					type = booleano; break;
				case 'c':
					type = caractere; break;
			}

			tamanho = 0;
			
			while(arvore->nextSibling != NULL)
			{
				arvore = arvore->nextSibling->firstChild;
				tamanho++;
				if(outros != NULL){
					outros[0] = '^';
					strcpy(&outros[1], arvore->label);//sprintf(outros, "^%d", arvore->label);
					}
				else
					strcpy(outros, arvore->label);//sprintf(outros, "%d", arvore->label);
			}

			Content* conteudo_de_simbolo = create_conteudo(arvore->line_no, arvore->col_no, /*Arranjo,*/ type, tamanho_tipo(type)*tamanho, dados, outros);
			add_to_table(myTable, conteudo_de_simbolo);
		}
	}	

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
	myNode->line_no = valor_lexico.line_no;
	myNode->col_no = valor_lexico.col_no;
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
	else if(valor_lexico.genero == 3)
		sprintf(myNode->label, "%c", valor_lexico.valor.caractere);

	
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

Node * ultimaInit(Node * parentNode){
	
	Node *node = parentNode->firstChild;
	Node *final;
	while (node->nextSibling != NULL)
		node = node->nextSibling;
	
	if (!strcmp(node->label, "<="))
		final = ultimaInit(node);
	else return parentNode;

	return final;

}












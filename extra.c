/*Gabriel Couto & Felippo Stédile: Dupla */
// funcoes auxiliares

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extra.h"

extern int yylineno;
extern Pilha *myStack;
extern L_iloc *arvore_iloc;

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
		return 1; // é int
	else if(tipo == caractere)
		return 1;

}

Iloc* new_instruction(char* label, char* r1, char* r2, char* r3)
{
	Iloc* new_instruction = (Iloc*) malloc (sizeof(Iloc));
	new_instruction->label = label; 
	new_instruction->r1 = r1;
	new_instruction->r2 = r2;
	new_instruction->r3 = r3;
}

L_iloc* create_lista_iloc()
{
	L_iloc* minha_lista = (L_iloc*) malloc (sizeof(L_iloc));
	minha_lista->instruction = NULL;
	minha_lista->next_instruction = NULL;
}

L_iloc* find_free_place_iloc(L_iloc* minha_lista)
{
	if(minha_lista->next_instruction != NULL)
		find_free_place_iloc(minha_lista->next_instruction);
	else
		return minha_lista;
}

void add_to_l_iloc(L_iloc* lista_iloc, Iloc* nova_instrucao)
{
	L_iloc* espaco_vazio = find_free_place_iloc(lista_iloc);
	if(espaco_vazio->instruction == NULL)
		espaco_vazio->instruction = nova_instrucao;
	else
	{
		L_iloc* novo_elemento_de_lista = create_lista_iloc();
		espaco_vazio->next_instruction = novo_elemento_de_lista;
		novo_elemento_de_lista->instruction = nova_instrucao;
	}

}


void print_iloc(L_iloc* lista_instrucoes)
{
	while(lista_instrucoes->next_instruction != NULL)
		print_iloc(lista_instrucoes->next_instruction);
	
	printf("%s %s %s %s\n", lista_instrucoes->instruction->label, lista_instrucoes->instruction->r1, lista_instrucoes->instruction->r2, lista_instrucoes->instruction->r3);

}

Tabela* create_simbolo()
{
	Tabela* minhaTabela;
	minhaTabela = (Tabela*) malloc (sizeof(Tabela));
	minhaTabela->nextElement = NULL;
	return minhaTabela;
}

Content* create_conteudo(int linha, int coluna, enum Natureza natureza, enum Tipo tipo, int tamanho, char *dados, char *outros)
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
	myContent->tipo = tipo;
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
	Tabela* espaco_vazio = find_free_place(myTable);
	if(espaco_vazio->conteudo == NULL)
		espaco_vazio->conteudo = conteudo;
	else
	{
		Tabela* newSimbolo = create_simbolo();
		espaco_vazio->nextElement = newSimbolo;
		newSimbolo->conteudo = conteudo;
	}
}


void analisa_e_insere(Tabela *myTable, Node *arvore, Node *tipo)
{
	if(arvore != NULL)
	{
		int tamanho = 0;
		if(arvore->label[0] == ',')
		{
			analisa_e_insere(myTable, arvore->firstChild, tipo);
			analisa_e_insere(myTable, arvore->firstChild->nextSibling, tipo);
		} 
		else if(strcmp(arvore->name, "TK_IDENTIFICADOR") == 0)
		{
			enum Tipo type;
			char outros[60] = {};
			switch(tipo->label[0])
			{
				case 'i':
					type = inteiro; tamanho = 4; break;
				case 'f':
					type = flutuante; tamanho = 4; break;
				case 'b':
					type = booleano; tamanho = 1;  break;
				case 'c':
					type = caractere; tamanho = 1;  break;
			}
			/* Necessitamos pesquisar se a variável já foi declarada antes de adicioná-la na tabela.*/
			Content* conteudo_de_simbolo = create_conteudo(arvore->line_no, arvore->col_no, Variavel, type, tamanho, arvore->label, outros);
			verifica_isDeclared(myTable, conteudo_de_simbolo);
			add_to_table(myTable, conteudo_de_simbolo);
		}
		else if(strcmp(arvore->name, "LISTA_LIT") == 0)
		{
			arvore = arvore->firstChild;//aqui tem o id do var global multidimensional
			int line_no = arvore->line_no, col_no = arvore->col_no;
			enum Tipo type;
			char outros[60] = {};
			char dados[60];
			strcpy(dados, arvore->label);
			switch(tipo->label[0])
			{
				case 'i':
					type = inteiro; tamanho = 4; break;
				case 'f':
					type = flutuante; tamanho = 4; break;
				case 'b':
					type = booleano; tamanho = 1; break;
				case 'c':
					exit(ERR_CHAR_VECTOR);
			}
			int EOS=0; //end of string
			Node* calctam = arvore;
			while (calctam->nextSibling->label[0]== '^')
			{
				calctam = calctam->nextSibling->firstChild;
				tamanho*=atoi(calctam->label);
				strcpy(&outros[EOS], calctam->label);
				for(int i=0; calctam->label[i]!='\0'; i++, EOS++);
				outros[EOS] = '^';
				EOS++;
			}
			calctam=calctam->nextSibling;
			strcpy(&outros[EOS], calctam->label);
			tamanho*=atoi(calctam->label);
				
			Content* conteudo_de_simbolo = create_conteudo(arvore->line_no, arvore->col_no, Arranjo, type, tamanho, dados, outros);
			verifica_isDeclared(myTable, conteudo_de_simbolo);
			add_to_table(myTable, conteudo_de_simbolo);
		}
		else if(strcmp(arvore->label, "<=") == 0)
		{
			int line_no = arvore->line_no, col_no = arvore->col_no;
			enum Tipo type;
			char dados[60];
			char outros[60]={};
			switch(tipo->label[0])
			{
				case 'i':
					type = inteiro; tamanho = 4; break;
				case 'f':
					type = flutuante; tamanho = 4; break;
				case 'b':
					type = booleano; tamanho = 1;  break;
				case 'c':
					type = caractere; tamanho = 1;  break;
			}
			strcpy(dados, arvore->firstChild->label);
			Content* conteudo_de_simbolo = create_conteudo(arvore->line_no, arvore->col_no, Variavel, type, tamanho, dados, outros);
			verifica_isDeclared(myTable, conteudo_de_simbolo);
			add_to_table(myTable, conteudo_de_simbolo);
		}	
		else if(strcmp(arvore->name, "FuncaoL") == 0)
		{
			int line_no = arvore->line_no, col_no = arvore->col_no;
			enum Tipo type;
			char dados[60];
			char outros[60]={};
			switch(tipo->label[0])
			{
				case 'i':
					type = inteiro; tamanho = 4; break;
				case 'f':
					type = flutuante; tamanho = 4; break;
				case 'b':
					type = booleano; tamanho = 1;  break;
				case 'c':
					type = caractere; tamanho = 1;  break;
			}
			strcpy(dados, arvore->label);
			int EOS=0; //end of string
			Node* parametros = arvore->firstChild;
			while (parametros->label[0] == ',')
			{
				strcpy(&outros[EOS], parametros->firstChild->name);
				for(int i=0; parametros->firstChild->name[i]!='\0'; i++, EOS++);
				outros[EOS] = ' ';
				EOS++;
				strcpy(&outros[EOS], parametros->firstChild->label);
				for(int i=0; parametros->firstChild->label[i]!='\0'; i++, EOS++);
				outros[EOS] = ',';
				EOS++;
				outros[EOS] = ' ';
				EOS++;
				parametros=parametros->firstChild->nextSibling;
			}
			strcpy(&outros[EOS], parametros->name);
			for(int i=0; parametros->name[i]!='\0'; i++, EOS++);
			outros[EOS] = ' ';
			EOS++;
			strcpy(&outros[EOS], parametros->label);
			for(int i=0; parametros->label[i]!='\0'; i++, EOS++);	
			
			Content* conteudo_de_simbolo = create_conteudo(arvore->line_no, arvore->col_no, Funcao, type, tamanho, dados, outros);
			verifica_isDeclared(myTable, conteudo_de_simbolo);
			add_to_table(myTable, conteudo_de_simbolo);
		}
		else if(strcmp(arvore->name, "Funcao") == 0)
		{
			enum Tipo type;
			char outros[60] = {};
			switch(tipo->label[0])
			{
				case 'i':
					type = inteiro; tamanho = 4; break;
				case 'f':
					type = flutuante; tamanho = 4; break;
				case 'b':
					type = booleano; tamanho = 1;  break;
				case 'c':
					type = caractere; tamanho = 1;  break;
			}
			/* Necessitamos pesquisar se a funcao já foi declarada antes de adicioná-la na tabela.*/
			Content* conteudo_de_simbolo = create_conteudo(arvore->line_no, arvore->col_no, Funcao, type, tamanho, arvore->label, outros);
			verifica_isDeclared(myTable, conteudo_de_simbolo);
			add_to_table(myTable, conteudo_de_simbolo);
		}

	}
}	

void verifica_isDeclared(Tabela* myTable, Content* conteudo)
{
	/* Temos de iterar desde a tabela mais profunda (global) da pilha até a tabela atual para ver se o símbolo já foi declarado: */

	// O elemento mais profundo da pilha é myStack. Vamos de myStack->elementoPilha até myTable:
	/*Pilha *tempPilha = myStack;
	Tabela *tempTable;
	int bool = 0;
	do
	{	
		if(bool)
			tempPilha = tempPilha->top;
		bool=1;

		tempTable = tempPilha->elemento_pilha;
		
		while(tempTable->conteudo != NULL)
		{
			if(strcmp(tempTable->conteudo->dados, conteudo->dados) == 0)
				//if(tempTable->conteudo->tipo == funcao || tempPilha->elemento_pilha == myTable)
					exit(ERR_DECLARED);

			if (tempTable->nextElement!= NULL) tempTable = tempTable->nextElement;
			else break;
		}
	} while (tempPilha->elemento_pilha != myTable);
*/	
	//solução que compreende mascaras, mas acho q é pra ser como a anterior caso haja uma função com o mesmo identificador
	// ou seja, qnd acertar o tipo e a natureza, voltar ao método anterior 
	while(myTable->conteudo != NULL)
	{
		if(strcmp(myTable->conteudo->dados, conteudo->dados) == 0)
			exit(ERR_DECLARED);

		if (myTable->nextElement!= NULL) myTable = myTable->nextElement;
		else break;
	}
}

enum Tipo compareTypes(enum Tipo tipoLeft, enum Tipo tipoRight){
	if (tipoLeft == caractere)
		if (tipoRight != caractere) exit(ERR_X_TO_CHAR);
		else return caractere;
	else 
	if (tipoRight == caractere){
		if (tipoLeft == inteiro) exit(ERR_CHAR_TO_INT);
		if (tipoLeft == flutuante) exit(ERR_CHAR_TO_FLOAT);
		if (tipoLeft == booleano) exit(ERR_CHAR_TO_BOOL);
		}
	else if (tipoLeft == flutuante || tipoRight == flutuante) return flutuante;
	else if (tipoLeft == inteiro || tipoRight == inteiro) return inteiro;
	else return booleano;
}

enum Tipo analisa_uso(Tabela *myTable, Node *variavel){ //tem que acertar as coisas de função aqui e na analisa
	Pilha *tempPilha = myStack;
	Tabela *tempTable;
	int bool = 0;
	int mult = 0;
	int funct = 0;
	Node* id = variavel;
	if (variavel->label[0] >= '0' && variavel->label[0] <= '9'){ return variavel->tipo;} //caso a expressao venha com um literal
	else if (variavel->label[0] >= '*' && variavel->label[0] <= '/'){ //caso a expressao venha com uma operação
		enum Tipo tipoLeft;
		enum Tipo tipoRight;
		tipoLeft = analisa_uso(myTable, variavel->firstChild);
		tipoRight = analisa_uso(myTable, variavel->firstChild->nextSibling);
		return compareTypes(tipoLeft, tipoRight);
	} else if (variavel->tipo == booleano) return booleano;
	else
		
	if (variavel->label[0] == '[') {
		mult = 1;
		id=variavel->firstChild->nextSibling;
	}
	else if (strcmp(variavel->name, "CHAMA_FUNCAO")==0){
		funct = 1;
		
		}
	do
	{	
		if(bool)
			tempPilha = tempPilha->top;
		bool=1;

		tempTable = tempPilha->elemento_pilha;
		
		while(tempTable->conteudo != NULL)
		{	
			if(strcmp(tempTable->conteudo->dados, id->label) != 0)
				if (myTable->nextElement!= NULL)
					tempTable = tempTable->nextElement;
				else break;
			else {
				if (mult){
					if (tempTable->conteudo->natureza == Variavel)
						exit(ERR_VARIABLE);
					else if (tempTable->conteudo->natureza == Funcao)
						exit(ERR_FUNCTION);
					else return tempTable->conteudo->tipo;
				}
				else if(funct) {
					if (tempTable->conteudo->natureza == Variavel)
						exit(ERR_VARIABLE);
					else if (tempTable->conteudo->natureza == Arranjo)
						exit(ERR_ARRAY);
					else return tempTable->conteudo->tipo;
				}
				else{
					if (tempTable->conteudo->natureza == Funcao)
						exit(ERR_FUNCTION);
					else if (tempTable->conteudo->natureza == Arranjo)
						exit(ERR_ARRAY);
					else return tempTable->conteudo->tipo;
				}
			}
						
		}
	} while (tempPilha->elemento_pilha != myTable);
	
	exit(ERR_UNDECLARED);
	
}



Pilha * create_stack(Tabela* tabela)
{
	Pilha *newStack;
	newStack = (Pilha*) malloc (sizeof(Pilha));
	
	newStack->top = NULL;
	newStack->elemento_pilha = tabela;

	return newStack;
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
	Pilha *topStack = pilha;
	while(topStack->top != NULL)
		topStack = topStack->top;
	
	return topStack;
}

Pilha* pop_stack(Pilha* pilha)
{
	Pilha *popStack = pilha, *eliminado;
	while(popStack->top->top != NULL)
		popStack = popStack->top;

	eliminado = popStack->top;
	popStack->top = NULL;

	return eliminado;
}

void print_full_stack()
{
  Pilha* tempStack = myStack;
  int nivel = 0;
  while(tempStack != NULL)
  {
    Tabela* resultado = tempStack->elemento_pilha;
    printf("Nivel %d:\n", nivel);
    while(resultado != NULL)
    {
    if(resultado->conteudo != NULL)
      printf("\tLinha: %d, Coluna: %d, Natureza: %d, Tipo: %d, Tamanho: %d, Dados: [%s], Outros: [%s], Endereço: [%p]\n", resultado->conteudo->localizacao->linha, resultado->conteudo->localizacao->coluna, resultado->conteudo->natureza, resultado->conteudo->tipo, resultado->conteudo->tamanho, resultado->conteudo->dados, resultado->conteudo->outros, resultado);
      resultado = resultado->nextElement;
    }
    tempStack = tempStack->top;
    nivel++;
  }

}

void print_node(Node *node){

	if(node != NULL)
	{
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
		/*if(strcmp("CHAMA_FUNCAO", name) == 0)
		{
			char fcall[100] = "call ";
			strcat(fcall, valor_lexico.valor.cadeia);
			strcpy(myNode->label, fcall);
		}
		else*/
			strcpy(myNode->label, valor_lexico.valor.cadeia);
	else if(valor_lexico.genero == 1){
		sprintf(myNode->label, "%d", valor_lexico.valor.inteiro);
		myNode->tipo = inteiro;}
	else if(valor_lexico.genero == 2){
		sprintf(myNode->label, "%f", valor_lexico.valor.flutuante);
		myNode->tipo = flutuante;}
	else if(valor_lexico.genero == 3){
		sprintf(myNode->label, "%c", valor_lexico.valor.caractere);
		myNode->tipo = caractere;}
	else if(valor_lexico.genero == 5){
		strcpy(myNode->label, valor_lexico.valor.cadeia);
		myNode->tipo = booleano;}

	
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
	if(node != NULL)
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












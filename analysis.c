#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extra.h"

void anl_DECLARACAO_GLOBAL(Tabela *myTable, Node *arvore, Node *tipo)
{
    if(arvore != NULL)
	{
		int tamanho = 0;
		if(arvore->label[0] == ',')
		{
			anl_DECLARACAO_GLOBAL(myTable, arvore->firstChild, tipo);
			anl_DECLARACAO_GLOBAL(myTable, arvore->firstChild->nextSibling, tipo);
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
			v_ERR_DECLARED(myTable, conteudo_de_simbolo);
			add_to_table(myTable, conteudo_de_simbolo);
			print_full_stack();
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
					type = caractere; tamanho = 1; break;
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
			v_ERR_DECLARED(myTable, conteudo_de_simbolo);
			add_to_table(myTable, conteudo_de_simbolo);
			print_full_stack();
		}
    }
}

void anl_PARAMETROS_DEF_FUNCAO(Tabela *myTable, Node *arvore, Node *tipo)
{
    if(arvore != NULL)
	{
		int tamanho = 0;
		if(arvore->label[0] == ',')
		{
			anl_PARAMETROS_DEF_FUNCAO(myTable, arvore->firstChild, tipo);
			anl_PARAMETROS_DEF_FUNCAO(myTable, arvore->firstChild->nextSibling, tipo);
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
			v_ERR_DECLARED(myTable, conteudo_de_simbolo);
			add_to_table(myTable, conteudo_de_simbolo);
			print_full_stack();
		}
    }
}

void anl_DEF_FUNCAO(Tabela *myTable, Node *arvore, Node *tipo)
{
    int tamanho = 0;
    if(strcmp(arvore->name, "FuncaoL") == 0)
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
			v_ERR_DECLARED(myTable, conteudo_de_simbolo);
			add_to_table(myTable, conteudo_de_simbolo);
			print_full_stack();
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
			v_ERR_DECLARED(myTable, conteudo_de_simbolo);
			add_to_table(myTable, conteudo_de_simbolo);
			print_full_stack();
		}
}

void anl_DECLARACAO_LOCAL(Tabela *myTable, Node *arvore, Node *tipo)
{
    if(arvore != NULL)
	{
		int tamanho = 0;
		if(arvore->label[0] == ',')
		{
			anl_DECLARACAO_GLOBAL(myTable, arvore->firstChild, tipo);
			anl_DECLARACAO_GLOBAL(myTable, arvore->firstChild->nextSibling, tipo);
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
			v_ERR_DECLARED(myTable, conteudo_de_simbolo);
			add_to_table(myTable, conteudo_de_simbolo);
			print_full_stack();
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
					type = caractere; tamanho = 1; break;
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
			v_ERR_DECLARED(myTable, conteudo_de_simbolo);
			add_to_table(myTable, conteudo_de_simbolo);
			print_full_stack();
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
			v_ERR_DECLARED(myTable, conteudo_de_simbolo);
			add_to_table(myTable, conteudo_de_simbolo);
			print_full_stack();
		}	
    
    }

}

void anl_ATRIBUICAO_LOCAL(Tabela *myTable, Node *variavel)
{



}


void anl_EXPRESSAO(Tabela *myTable, Node *variavel)
{




}
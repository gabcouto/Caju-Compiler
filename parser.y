%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(const char *);
%}

%define parse.error verbose

%token TK_PR_INT
%token TK_IDENTIFICADOR
%token TK_PR_FLOAT
%token TK_PR_CHAR
%token TK_PR_IF
%token TK_PR_THEN
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_INPUT
%token TK_PR_OUTPUT
%token TK_PR_RETURN
%token TK_PR_FOR
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_CHAR
%token TK_ERRO
%token TK_PR_BOOL


%start programa

%%

programa: lista_de_elementos | ;
lista_de_elementos: lista_de_elementos funcao;
lista_de_elementos: lista_de_elementos declaracao; 
lista_de_elementos: funcao;
lista_de_elementos: declaracao;
declaracao: tipo lista_de_nome_de_variaveis ';';
lista_de_nome_de_variaveis: lista_de_nome_de_variaveis ',' TK_IDENTIFICADOR;
lista_de_nome_de_variaveis: TK_IDENTIFICADOR;

tipo: TK_PR_INT;
tipo: TK_PR_FLOAT;
tipo: TK_PR_CHAR;
tipo: TK_PR_BOOL;



funcao: ';';


%%
void yyerror(const char *mensagem){
	printf("Erro Sintático: [%s] na linha %d", mensagem, 0);
	return;
}

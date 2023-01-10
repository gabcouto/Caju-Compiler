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
lista_de_elementos: lista_de_elementos cabecalho_funcao;
lista_de_elementos: lista_de_elementos declaracao; 
lista_de_elementos: cabecalho_funcao;
lista_de_elementos: declaracao;
/*
	Declaração de Variáveis Globais
*/
declaracao: tipo lista_de_nome_de_variaveis ';';
lista_de_nome_de_variaveis: lista_de_nome_de_variaveis ',' multidimensional;
lista_de_nome_de_variaveis: multidimensional;
multidimensional: TK_IDENTIFICADOR '[' lista_literais;
lista_literais: TK_LIT_INT '^' lista_literais; 
lista_literais: TK_LIT_INT ']';
multidimensional: TK_IDENTIFICADOR;

/*
	Definição de Função
*/
cabecalho_funcao: tipo TK_IDENTIFICADOR '(' lista_parametros bloco_comandos;
lista_parametros: tipo TK_IDENTIFICADOR ',' lista_parametros;
lista_parametros: tipo TK_IDENTIFICADOR ')';
lista_parametros: ')';
bloco_comandos: '{' comandos_simples;
comandos_simples: declaracao_local comandos_simples;
comandos_simples: atribuicao_local comandos_simples;

/*
	Declaração de Variável Local
*/
declaracao_local: tipo lista_de_nome_de_variaveis_locais ';';
lista_de_nome_de_variaveis_locais: lista_de_nome_de_variaveis_locais ',' multidimensional_local;
lista_de_nome_de_variaveis_locais: multidimensional_local;
multidimensional_local: TK_IDENTIFICADOR '[' lista_literais_locais;
lista_literais_locais: TK_LIT_INT '^' lista_literais_locais;
lista_literais_locais: TK_LIT_INT ']';

/* Não estou fazendo inicialização de variáveis multidimensionais, por não saber como fazer ou se é para fazer.
	Por exemplo: int mediaAlunos[2][3] = 0;
*/

multidimensional_local: TK_IDENTIFICADOR TK_OC_LE literal;
multidimensional_local: TK_IDENTIFICADOR;

/*
	Atribuição local (incompleto)
*/
atribuicao_local: TK_IDENTIFICADOR  lista_de_expressoes '=' expressao;
lista_de_expressoes:;
expressao:;
comandos_simples: '}';


tipo: TK_PR_INT;
tipo: TK_PR_FLOAT;
tipo: TK_PR_CHAR;
tipo: TK_PR_BOOL;
literal: TK_LIT_INT;
literal: TK_LIT_FLOAT;
literal: TK_LIT_CHAR;


%%
void yyerror(const char *mensagem){
	printf("Erro Sintático: [%s] na linha %d", mensagem, 0);
	return;
}

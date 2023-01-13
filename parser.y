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
comandos_simples: chamada_funcao comandos_simples;
comandos_simples: chamada_retorno comandos_simples;
comandos_simples: chamada_ctrl_fluxo comandos_simples;

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
	Atribuição local
*/
atribuicao_local: TK_IDENTIFICADOR  lista_de_identificadores '=' expressao;
lista_de_identificadores: TK_IDENTIFICADOR lista_de_expressoes;
lista_de_expressoes: '[' expressao lista_de_expressoes_;
lista_de_expressoes_: '^' expressao lista_de_expressoes_;
lista_de_expressoes_: ']';
lista_de_expressoes: ;

/*
	Chamada de Função
*/
chamada_funcao: TK_IDENTIFICADOR  '(' lista_expressoes_funcao |  ')'; 
lista_expressoes_funcao: expressao ',' lista_expressoes_funcao;
lista_expressoes_funcao: expressao;

/*
	Chamada de retorno
*/
chamada_retorno: TK_PR_RETURN expressao;

/*
	Controle de Fluxo
*/
chamada_ctrl_fluxo: ctrl_condicional | ctrl_repeticao;
ctrl_repeticao: TK_PR_WHILE '(' expressao ')' bloco_comandos;
ctrl_condicional: TK_PR_IF '(' expressao ')' TK_PR_THEN bloco_comandos cond_else;
cond_else: TK_PR_ELSE bloco_comandos;
cond_else: ;



comandos_simples: '}';

/*
	Expressão

	fiz recursões a direita, n sei se tem problema, e n sei como garantir precedência 
 	mas a declaração dos operadores ta na ordem certa pra n precisar ficar consultando a tabela
*/


expressao: operandos;
expressao: '(' expressao ')';
expressao: operadores_pre expressao;
expressao: expressao operadores expressao;

operandos: multidimensional;
operandos: literal;
operandos: chamada_funcao;

operadores_pre: '-' | '!';
operadores: '*' | '/' | '%';
operadores: '+' | '-';
operadores: '<' | '>' | TK_OC_LE | TK_OC_GE;
operadores: TK_OC_EQ | TK_OC_NE;
operadores: TK_OC_AND;
operadores: TK_OC_OR;


tipo: TK_PR_INT;
tipo: TK_PR_FLOAT;
tipo: TK_PR_CHAR;
tipo: TK_PR_BOOL;
literal: TK_LIT_INT;
literal: TK_LIT_FLOAT;
literal: TK_LIT_CHAR;


%%
void yyerror(const char *mensagem){
	printf("Erro Sintático: [%s] na linha %d\n", mensagem, 0);
	return;
}

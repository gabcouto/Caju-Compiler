/* Gabriel Couto & Felippo Stédile: Dupla */

%{
	#include <stdio.h>
	extern int yylineno;
	int yylex(void);
	void yyerror(const char *);
%}

%define parse.error verbose
%define parse.trace

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
multidimensional: TK_IDENTIFICADOR '[' lista_literais ']';
lista_literais: lista_literais '^' TK_LIT_INT;
lista_literais: TK_LIT_INT;
multidimensional: TK_IDENTIFICADOR;

/*
	Definição de Função
*/
cabecalho_funcao: tipo TK_IDENTIFICADOR '(' lista_parametros ')' bloco_comandos;
lista_parametros: tipo TK_IDENTIFICADOR ',' lista_parametros;
lista_parametros: tipo TK_IDENTIFICADOR ;
bloco_comandos: '{' lista_comandos_simples '}';
lista_comandos_simples: comandos_simples ';' lista_comandos_simples;
lista_comandos_simples: comandos_simples;
comandos_simples: declaracao_local;
comandos_simples: atribuicao_local;
comandos_simples: chamada_funcao;
comandos_simples: chamada_retorno;
comandos_simples: chamada_ctrl_fluxo;
comandos_simples: bloco_comandos;

/*
	Declaração de Variável Local
*/
declaracao_local: tipo lista_de_nome_de_variaveis_locais ';';
lista_de_nome_de_variaveis_locais: lista_de_nome_de_variaveis_locais ',' variavel_local;
lista_de_nome_de_variaveis_locais: variavel_local;
variavel_local: TK_IDENTIFICADOR TK_OC_LE literal;
variavel_local: TK_IDENTIFICADOR;

/*
	Atribuição local
*/
atribuicao_local: TK_IDENTIFICADOR  lista_de_expressoes '=' expressao ';';
lista_de_expressoes: '[' lista_de_expressoes_ expressao']';
lista_de_expressoes_: lista_de_expressoes_ expressao '^';
lista_de_expressoes_: ;
lista_de_expressoes: ;

/*
	Chamada de Função
*/
chamada_funcao: TK_IDENTIFICADOR  '(' lista_expressoes_funcao ')';
chamada_funcao: TK_IDENTIFICADOR  '(' ')'; 
lista_expressoes_funcao: expressao ',' lista_expressoes_funcao;
lista_expressoes_funcao: expressao;

/*
	Chamada de retorno
*/
chamada_retorno: TK_PR_RETURN expressao ';';

/*
	Controle de Fluxo
*/
chamada_ctrl_fluxo: ctrl_condicional | ctrl_repeticao;
ctrl_repeticao: TK_PR_WHILE '(' expressao ')' bloco_comandos;
ctrl_condicional: TK_PR_IF '(' expressao ')' TK_PR_THEN bloco_comandos cond_else;
cond_else: TK_PR_ELSE bloco_comandos;
cond_else: ;



/*
	Expressão

*/

operandos: literal;
operandos: multidimensional;
operandos: chamada_funcao;

/*
expressao: operandos;
expressao: operadores_pre operandos_;
expressao: operandos_ operadores expressao;
expressao: operadores_pre operandos_ operadores expressao;
operandos_: operandos;
operandos_: '(' operandos_ ')';

operadores_pre: '-' | '!';
operadores: '*' | '/' | '%';
operadores: '+' | '-';
operadores: '<' | '>' | TK_OC_LE | TK_OC_GE;
operadores: TK_OC_EQ | TK_OC_NE;
operadores: TK_OC_AND;
operadores: TK_OC_OR;
*/
/*
E: E+T | T;
T: T*F | F;
F: (E) | id;

*/

op0: '-' | '!' ;
op1: '*' | '/' | '%';
op2: '+' | '-';
op3: '<' | '>' | TK_OC_LE | TK_OC_GE;
op4: TK_OC_EQ | TK_OC_NE;
op5: TK_OC_AND;
op6: TK_OC_OR;

expressao: expressao op6 exp1 | exp1;
exp1: exp1 op5 exp2 | exp2;
exp2: exp2 op4 exp3 | exp3;
exp3: exp3 op3 exp4 | exp4;
exp4: exp4 op2 exp5 | exp5;
exp5: exp5 op1 exp6 | exp6;
exp6: op0 exp6 | exp7;
exp7: '(' expressao ')' | operandos;



tipo: TK_PR_INT;
tipo: TK_PR_FLOAT;
tipo: TK_PR_CHAR;
tipo: TK_PR_BOOL;
literal: TK_LIT_INT;
literal: TK_LIT_FLOAT;
literal: TK_LIT_CHAR;


%%
void yyerror(const char *mensagem){
	printf("Erro Sintático: [%s] na linha %d\n", mensagem, yylineno);
	return;
}
